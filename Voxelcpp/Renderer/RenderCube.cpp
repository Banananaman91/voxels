#include "RenderCube.h"
using namespace renderer;

void RenderCube::CreateCube(){
    //Bind vertex array buffer
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glGenBuffers(1, &NBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, pos));
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
    glEnableVertexAttribArray(1);
    
    // //copy vertices into array buffer for OpenGL
    // glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * cubeVertices.size(), cubeVertices.data(), GL_STATIC_DRAW);

    // //set vertex attribute pointers
    // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    // glEnableVertexAttribArray(0);    

    // //copy normals into array buffer for OpenGL
    // glBindBuffer(GL_ARRAY_BUFFER, NBO);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * cubeNormals.size(), cubeNormals.data(), GL_STATIC_DRAW);

    // //set normal attribute pointers
    // glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
    // glEnableVertexAttribArray(1);

    //copy indices into array buffer for OpenGL
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), indices.data(), GL_STATIC_DRAW);
}