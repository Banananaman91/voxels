#include "MainHeader.h"
#include <iostream>

namespace renderer {
    class WindowRender{
        public:
            const int _width = 800;
            const int _height = 600;

            glm::mat4 transform = glm::mat4(1.0f);
            float scale = 1.0f;
            
            void processInput(GLFWwindow* window);
            void Display();
    };
}