#include "MainHeader.h"
#include "Camera.h"
#include <iostream>

namespace ProjectMain {
    class WindowRender{
        public:
            const float _width = 800.0f;
            const float _height = 600.0f;
            glm::mat4 origin = glm::mat4(1.0f);
            glm::mat4 model = glm::mat4(1.0f);
            glm::mat4 view = glm::mat4(1.0f);
            glm::mat4 projection = glm::mat4(1.0f);
            float scale = 1.0f;

            //timing
            float deltaTime = 0.0f;
            float lastFrame = 0.0f;
            float currentFrame = 0.0f;
            
            void processInput(GLFWwindow* window);
            void Display();
    };
}