#include "WindowRender.h"
#include "RenderTriangle.h"
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
    RenderTriangle triangle;
    triangle.CreateTriangle();
    //wait for user to close window
    while(!glfwWindowShouldClose(window.get())){
        //Check for input
        processInput(window.get());
        //Rendering commands
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
            //draw object
        glUseProgram(triangle.shaderProgram);
        glBindVertexArray(triangle.vao);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        //swap colour buffers
        glfwSwapBuffers(window.get());
        //check if any events are triggered
        glfwPollEvents();
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

void WindowRender::processInput(GLFWwindow* window){
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }
}