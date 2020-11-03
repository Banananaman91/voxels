#include "WindowRender.h"
#include "../Renderer/RenderPolygon.h" //this is one folder up
using namespace ProjectMain;
using namespace renderer;

void framebuffer_size_callback(GLFWwindow* window, int width, int height); 

void WindowRender::Display(){
    //initialise glfw with OpenGL version 3 and core profile
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    std::unique_ptr<GLFWwindow, decltype(&glfwDestroyWindow)> window = std::unique_ptr<GLFWwindow, decltype(&glfwDestroyWindow)>(glfwCreateWindow(_width, _height, "Voxel", nullptr, nullptr), glfwDestroyWindow);
    //GLFWwindow* window = glfwCreateWindow(_width, _height, "Voxel", NULL, NULL);

    if(window == NULL){
        std::cout << "Failed to creat GLFW Window" << std::endl;
        glfwTerminate();
        return;
    }
    //Make window the main context on current thread
    glfwMakeContextCurrent(window.get());

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }
    //set viewport size
    glViewport(0, 0, 800, 600);
    //check for viewport resizing
    glfwSetFramebufferSizeCallback(window.get(), framebuffer_size_callback);
    RenderPolygon polygon;
    polygon.CreatePolygon();
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    glEnable(GL_DEPTH_TEST);
    //wait for user to close window
    while(!glfwWindowShouldClose(window.get())){
        //Check for input
        processInput(window.get());

        //Rendering commands
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //draw object
        polygon.shaderProgram.use();

        //create transformations
        polygon.shaderProgram.SetMat4("model", model);
        polygon.shaderProgram.SetMat4("view", view);
        polygon.shaderProgram.SetMat4("projection", projection);

        //render container
        glBindVertexArray(polygon.VAO);
        glDrawElements(GL_TRIANGLES, sizeof(polygon.indices), GL_UNSIGNED_INT, 0);

        //swap colour buffers
        glfwSwapBuffers(window.get());

        //check if any events are triggered
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &polygon.VAO);
    glDeleteBuffers(1, &polygon.VBO);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

void WindowRender::processInput(GLFWwindow* window){
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
        model = glm::translate(model, glm::vec3(0.0f, 0.01f, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
        model = glm::translate(model, glm::vec3(0.0f, -0.01f, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
        model = glm::translate(model, glm::vec3(0.01f, 0.0f, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
        model = glm::translate(model, glm::vec3(-0.01f, 0.0f, 0.0f));
    }
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS){
        model = glm::rotate_slow(model, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 0.01f));
    }
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS){
        model = glm::rotate_slow(model, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, -0.01f));
    }
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS){
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.01f));
        // scale += 0.001f;
        // transform = glm::scale(transform, glm::vec3(scale, scale, scale));
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS){
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, -0.01f));
        // scale -= 0.01f;
        // transform = glm::scale_slow(transform, glm::vec3(scale, scale, scale));
    }
}