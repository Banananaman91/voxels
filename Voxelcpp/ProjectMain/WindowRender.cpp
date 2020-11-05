#include "WindowRender.h"
using namespace ProjectMain;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xOffset, double yOffset);

Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = 800.0f / 2.0f;
float lastY = 600.0f / 2.0f;
bool firstMouse = true;

void WindowRender::Display(){
    //initialise glfw with OpenGL version 4 and core profile
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    std::unique_ptr<GLFWwindow, decltype(&glfwDestroyWindow)> window = std::unique_ptr<GLFWwindow, decltype(&glfwDestroyWindow)>(glfwCreateWindow(_width, _height, "Voxel", nullptr, nullptr), glfwDestroyWindow);

    if(window == NULL){
        std::cout << "Failed to creat GLFW Window" << std::endl;
        glfwTerminate();
        return;
    }
    //Make window the main context on current thread
    glfwMakeContextCurrent(window.get());

    glfwSetInputMode(window.get(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }

    //set viewport size
    glViewport(0, 0, _width, _height);
    //check for viewport resizing
    glfwSetFramebufferSizeCallback(window.get(), framebuffer_size_callback);
    glfwSetCursorPosCallback(window.get(), mouse_callback);
    glfwSetScrollCallback(window.get(), scroll_callback);

    InitialiseShaders();
    RenderCube polygon;
    polygon.CreateCube();
    //origin = glm::translate(origin, glm::vec3(0.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    view = camera.GetViewMatrix();
    projection = glm::perspective(glm::radians(45.0f), _width / _height, 0.1f, 100.0f);
    glEnable(GL_DEPTH_TEST);

    for (unsigned int i = 0; i <= 10; i++)
    {
        cubeMatrices[i] = glm::translate(cubeMatrices[i], cubePositions[i]);
    }

    lightModel = glm::translate(lightModel, lightPos);
    lightModel = glm::scale(lightModel, glm::vec3(0.2f));

    //wait for user to close window
    while(!glfwWindowShouldClose(window.get())){
        //per-frame time logic
        currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        //Check for input
        processInput(window.get());

        //Rendering commands
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //draw object
        shaderProgram->use();

        //create transformations
        view = camera.GetViewMatrix();
        shaderProgram->SetMat4("view", view);
        shaderProgram->SetMat4("projection", projection);

        //render container
        glBindVertexArray(polygon.VAO);
        for (unsigned int i = 0; i <= 10; i++)
        {
            shaderProgram->SetVec3("lightPos", lightPos);
            shaderProgram->SetVec3("objectColour", boxColour);
            shaderProgram->SetVec3("lightColour", lightColour);
            shaderProgram->SetFloat("ambientStrength", 0.1f);
            shaderProgram->SetMat4("model", cubeMatrices[i]);
            glDrawElements(GL_TRIANGLES, sizeof(polygon.indices), GL_UNSIGNED_INT, 0);
        }

        lightProgram->use();
        lightProgram->SetVec3("lightColour", lightColour);
        lightProgram->SetMat4("view", view);
        lightProgram->SetMat4("projection", projection);
        lightProgram->SetMat4("model", lightModel);
        glDrawElements(GL_TRIANGLES, sizeof(polygon.indices), GL_UNSIGNED_INT, 0);

        //swap colour buffers
        glfwSwapBuffers(window.get());

        //check if any events are triggered
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &polygon.VAO);
    glDeleteBuffers(1, &polygon.VBO);
    glDeleteBuffers(1, &polygon.EBO);
    glDeleteBuffers(1, &polygon.NBO);
}

void WindowRender::InitialiseShaders(){
    shaderProgram = std::make_shared<Shader>(vertPath, fragPath);
    lightProgram = std::make_shared<Shader>(vertPath, lightPath);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

void WindowRender::processInput(GLFWwindow* window){
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
        camera.ProcessKeyboard(FORWARD, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
        camera.ProcessKeyboard(RIGHT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
       camera.ProcessKeyboard(LEFT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS){
        view = glm::rotate_slow(view, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 0.01f));
    }
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS){
        view = glm::rotate_slow(view, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, -0.01f));
    }
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS){
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, 0.01f));
        // scale += 0.001f;
        // transform = glm::scale(transform, glm::vec3(scale, scale, scale));
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS){
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -0.01f));
        // scale -= 0.01f;
        // transform = glm::scale_slow(transform, glm::vec3(scale, scale, scale));
    }
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos){
    if (firstMouse){
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xOffset = xpos - lastX;
    float yOffset = lastY - ypos;

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xOffset, yOffset, true);
}

void scroll_callback(GLFWwindow* window, double xOffset, double yOffset){
    camera.ProcessMouseScroll(yOffset);
}

