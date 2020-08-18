#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

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

            const char *vertexShaderSource = "#version 330 core\n"
                "layout (location = 0) in vec3 aPos;\n"
                "void main ()\n"
                "{\n"
                    "gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);\n"
                "}\0";

            const char *fragmentShaderSource = "#version 330 core\n"
                "out vec4 FragColour;\n"
                "void main()\n"
                "{\n"
                    "FragColour = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                "}\0";

            void CreateTriangle();
    };
}