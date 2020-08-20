#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace renderer {
    class WindowRender{
        public:
            const int _width = 800;
            const int _height = 600;
            
            void processInput(GLFWwindow* window);
            void Display();
    };
}