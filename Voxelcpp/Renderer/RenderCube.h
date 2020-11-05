#include "Shader.h"

namespace renderer{
    class RenderCube{
        public:
            const glm::vec3 cubeVertices [8] {
                glm::vec3(0, 0, 0), //0
                glm::vec3(1, 0, 0), //1
                glm::vec3(1, 1, 0), //2
                glm::vec3(0, 1, 0), //3
                glm::vec3(0, 1, 1), //4
                glm::vec3(1, 1, 1), //5
                glm::vec3(1, 0, 1), //6
                glm::vec3(0, 0, 1) //7
            };

            const glm::vec3 cubeNormals [6] {
                glm::vec3(0.0f, 0.0f, -1.0f),
                glm::vec3(0.0f, 0.0f, 1.0f),
                glm::vec3(-1.0f, 0.0f, 0.0f),
                glm::vec3(1.0f, 0.0f, 0.0f),
                glm::vec3(0.0f, -1.0f, 0.0f),
                glm::vec3(0.0f, 1.0f, 0.0f)
            };

            unsigned int indices[36]{
                // Front
                0, 2, 1,
                0, 3, 2,
                // Top
                2, 3, 4,
                2, 4, 5,
                // Right
                1, 2, 5,
                1, 5, 6,
                // Left
                0, 7, 4,
                0, 4, 3,
                // Back
                5, 4, 7,
                5, 7, 6,
                // Bottom
                0, 6, 7,
                0, 1, 6
            };

            unsigned int VBO;
            unsigned int VAO;
            unsigned int EBO;
            unsigned int NBO;

            void CreateCube();
    };
}