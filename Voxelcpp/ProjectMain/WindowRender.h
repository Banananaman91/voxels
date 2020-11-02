#include "MainHeader.h"
#include <iostream>

namespace ProjectMain {
    class WindowRender{
        public:
            const int _width = 800;
            const int _height = 600;
            glm::mat4 model = glm::mat4(1.0f);
            glm::mat4 view = glm::mat4(1.0f);
            glm::mat4 projection = glm::mat4(1.0f);
            float scale = 1.0f;
            
            void processInput(GLFWwindow* window);
            void Display();
    };
}