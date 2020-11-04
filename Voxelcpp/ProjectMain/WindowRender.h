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
            unsigned int vertexShader;
            unsigned int fragmentShader;
            const char *vertexShaderSource;
            const char *fragmentShaderSource;
            const char *vertPath = "Shaders/VertexShader.glsl";
            const char *fragPath = "Shaders/FragmentShader.glsl";
            const char *lightPath = "Shaders/LightFragment.glsl";

            Shader shaderProgram = Shader(vertPath, fragPath);
            Shader shaderProgram2 = Shader(vertPath, lightPath);

            //methods
            void processInput(GLFWwindow* window);
            void Display();
    };
}