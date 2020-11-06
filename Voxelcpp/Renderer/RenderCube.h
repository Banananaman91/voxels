#include "Vertex.h"
#include <array>

namespace renderer{
    class RenderCube{
        public:
            const std::array<glm::vec3, 8> cubeVertices {
                glm::vec3(0, 0, 0), //0
                glm::vec3(1, 0, 0), //1
                glm::vec3(1, 1, 0), //2
                glm::vec3(0, 1, 0), //3
                glm::vec3(0, 1, 1), //4
                glm::vec3(1, 1, 1), //5
                glm::vec3(1, 0, 1), //6
                glm::vec3(0, 0, 1) //7
            };

            const std::array<glm::vec3, 6> cubeNormals {
                glm::vec3(0.0f, 1.0f, 0.0f),
                glm::vec3(0.0f, 0.0f, 1.0f),
                glm::vec3(-1.0f, 0.0f, 0.0f),
                glm::vec3(0.0f, -1.0f, 0.0f),
                glm::vec3(1.0f, 0.0f, 0.0f),
                glm::vec3(0.0f, 0.0f, -1.0f)
            };

            std::array<unsigned int, 36> indices{
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

            const std::array<Vertex, 36> vertices = {
                Vertex { cubeVertices[1], cubeNormals[0] },
                Vertex { cubeVertices[2], cubeNormals[0] },
                Vertex { cubeVertices[5], cubeNormals[0] },
                Vertex { cubeVertices[6], cubeNormals[0] },

                Vertex { cubeVertices[7], cubeNormals[1] },
                Vertex { cubeVertices[4], cubeNormals[1] },
                Vertex { cubeVertices[3], cubeNormals[1] },
                Vertex { cubeVertices[0], cubeNormals[1] },

                Vertex { cubeVertices[3], cubeNormals[2] },
                Vertex { cubeVertices[4], cubeNormals[2] },
                Vertex { cubeVertices[5], cubeNormals[2] },
                Vertex { cubeVertices[2], cubeNormals[2] },

                Vertex { cubeVertices[0], cubeNormals[3] },
                Vertex { cubeVertices[1], cubeNormals[3] },
                Vertex { cubeVertices[6], cubeNormals[3] },
                Vertex { cubeVertices[7], cubeNormals[3] },

                Vertex { cubeVertices[6], cubeNormals[3] },
                Vertex { cubeVertices[5], cubeNormals[3] },
                Vertex { cubeVertices[4], cubeNormals[3] },
                Vertex { cubeVertices[7], cubeNormals[3] },
 
                Vertex { cubeVertices[0], cubeNormals[3] },
                Vertex { cubeVertices[3], cubeNormals[3] },
                Vertex { cubeVertices[2], cubeNormals[3] },
                Vertex { cubeVertices[1], cubeNormals[3] },
            };

            unsigned int VBO;
            unsigned int VAO;
            unsigned int EBO;
            unsigned int NBO;

            void CreateCube();
    };
}