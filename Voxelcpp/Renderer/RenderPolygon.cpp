#include "RenderPolygon.h"
using namespace renderer;

void RenderPolygon::CreatePolygon(){
    //Bind vertex array buffer
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glm::vec3 vertexPoints[36];
    int count = 0;
    for (auto &&i : indices)
    {
        vertexPoints[count] = cubeVertices[i];
        count++;
    }
    

    //copy vertices into array buffer for OpenGL
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPoints), vertexPoints, GL_STATIC_DRAW);    

    //set vertex attribute pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), nullptr);
    glEnableVertexAttribArray(0);
}