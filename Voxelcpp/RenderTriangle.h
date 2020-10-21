#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

namespace renderer{
    class RenderTriangle{
        public:
            float triangle[9] = {
                0.9f, 0.9f, 0.0f, //top right
                0.9f, -0.85f, 0.0f, //bottom right
                -0.85f, 0.9f, 0.0f, // top left
            };
            float triangle2[9] = {
                -0.9f, -0.9f, 0.0f, //bottom left
                -0.9f, 0.85f, 0.0f, //top left
                0.85f, -0.9f, 0.0f //bottom right
            };
            unsigned int indices[6] = {
                0, 1, 2, //first triangle
                3, 4, 5, //second triangle
            };

            unsigned int VBOs[2];
            unsigned int VAOs[2];
            unsigned int ebo;
            unsigned int vertexShader;
            unsigned int fragmentShader;
            unsigned int shaderProgram;
            unsigned int shaderProgram2;
            const char *vertexShaderSource;
            const char *fragmentShaderSource;
            const char *vertPath = "Shaders/VertexShader.glsl";
            const char *fragPath = "Shaders/FragmentShader.glsl";
            const char *yellowPath = "Shaders/YellowFragment.glsl";

            void CreateTriangle();

            std::string ReadFile(const char* filePath);

            void LoadProgram(unsigned int* ShaderProgram, const char* VertPath, const char* FragPath);
    };
}