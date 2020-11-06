#include "../Renderer/RenderCube.h"
#include "Camera.h"
#include <iostream>
#include <array>

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
            glm::mat4 lightModel = glm::mat4(1.0f);
            float scale = 1.0f;

            glm::vec3 lightPos = glm::vec3(1.0f, 1.0f, 1.0f);

            std::array<glm::vec3, 10> cubePositions = {
                glm::vec3( 0.0f,  0.0f,  0.0f), 
                glm::vec3( 2.0f,  5.0f, -15.0f), 
                glm::vec3(-1.5f, -2.2f, -2.5f),  
                glm::vec3(-3.8f, -2.0f, -12.3f),  
                glm::vec3( 2.4f, -0.4f, -3.5f),  
                glm::vec3(-1.7f,  3.0f, -7.5f),  
                glm::vec3( 1.3f, -2.0f, -2.5f),  
                glm::vec3( 1.5f,  2.0f, -2.5f), 
                glm::vec3( 1.5f,  0.2f, -1.5f), 
                glm::vec3(-1.3f,  1.0f, -1.5f)  
            };

            std::array<glm::mat4, 10> cubeMatrices = {
                glm::mat4(1.0f),
                glm::mat4(1.0f),
                glm::mat4(1.0f),
                glm::mat4(1.0f),
                glm::mat4(1.0f),
                glm::mat4(1.0f),
                glm::mat4(1.0f),
                glm::mat4(1.0f),
                glm::mat4(1.0f),
                glm::mat4(1.0f),
            };

            //colours
            glm::vec3 boxColour = glm::vec3(1.0f, 0.5f, 0.31f);
            glm::vec3 lightColour = glm::vec3(1.0f, 1.0f, 1.0f);

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