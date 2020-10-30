#include "Shader.h"
#include <iostream>
#include <fstream>
#include <sstream>

namespace renderer{
    class RenderPolygon{
        public:
            float vertices[20] = {
                //positions         
                0.5f, 0.5f, 0.0f, //top right
                0.5f, -0.5f, 0.0f, //bottom right
                -0.5f, -0.5f, 0.0f, //bottom left
                -0.5f, 0.5f, 0.0f, //top left
            };
            unsigned int indices[6] = {
                0, 1, 3, //first triangle
                1, 2, 3, //second triangle
            };

            unsigned int VBO;
            unsigned int VAO;
            unsigned int EBO;
            unsigned int vertexShader;
            unsigned int fragmentShader;
            const char *vertexShaderSource;
            const char *fragmentShaderSource;
            const char *vertPath = "Shaders/VertexShader.glsl";
            const char *fragPath = "Shaders/FragmentShader.glsl";
            const char *yellowPath = "Shaders/YellowFragment.glsl";

            Shader shaderProgram = Shader(vertPath, fragPath);
            Shader shaderProgram2 = Shader(vertPath, yellowPath);

            void CreatePolygon();
    };
}