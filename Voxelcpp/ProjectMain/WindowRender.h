#include "../Renderer/RenderCube.h"
#include "Camera.h"
#include <iostream>
using namespace renderer;

namespace ProjectMain {
    class WindowRender{
        public:
            const float _width = 1920.0f;
            const float _height = 1080.0f;
            // glm::mat4 origin = glm::mat4(1.0f);
            glm::mat4 model = glm::mat4(1.0f);
            glm::mat4 view = glm::mat4(1.0f);
            glm::mat4 projection = glm::mat4(1.0f);
            float scale = 1.0f;

            //timing
            float deltaTime = 0.0f;
            float lastFrame = 0.0f;
            float currentFrame = 0.0f;

            //shader program
            std::string vertPath = "../Shaders/VertexShader.glsl";
            std::string fragPath = "../Shaders/FragmentShader.glsl";
            std::string lightPath = "../Shaders/LightFragment.glsl";

            std::shared_ptr<Shader> shaderProgram;
            std::shared_ptr<Shader> lightProgram;

            //methods
            void processInput(GLFWwindow* window);
            void Display();
            void InitialiseShaders();
    };
}