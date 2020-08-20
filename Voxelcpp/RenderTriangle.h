#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

namespace renderer{
    class RenderTriangle{
        public:
            float vertices[12] = {
                0.5f, 0.5f, 0.0f, //top right
                0.5f, -0.5f, 0.0f, //bottom right
                -0.5f, -0.5f, 0.0f, //bottom left
                -0.5f, 0.5f, 0.0f // top left
            };
            unsigned int indices[6] = {
                0, 1, 3, //first triangle
                1, 2, 3 // second triangle
            };

            unsigned int vbo;
            unsigned int vao;
            unsigned int ebo;
            unsigned int vertexShader;
            unsigned int fragmentShader;
            unsigned int shaderProgram;
            const char *vertexShaderSource;
            const char *fragmentShaderSource;
            const char *vertPath = "vertexShader.glsl";
            const char *fragPath = "FragmentShader.glsl";

            void CreateTriangle();

            std::string ReadFile(const char* filePath);
    };
}