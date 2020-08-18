#include "RenderTriangle.h"
using namespace renderer;

void RenderTriangle::CreateTriangle(){
    //create vertex shader
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    //compile shader
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    //compile success check
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if (!success){
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR: SHADER::VERTEX::COMPILATION_FAILED" << std::endl;
    }

    //create fragment shader
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    //compile shader
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    //compile success check
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    if (!success){
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR: SHADER::FRAGMENT::COMPILATION_FAILED" << std::endl;
    }

    //create shader program
    shaderProgram = glCreateProgram();

    //attach shaders and link program
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    //check link success
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success){
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR: SHADER::PROGRAM::LINK_FAILED" << std::endl;
    }
    //delete shaders
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    //Bind vertex array buffer
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);

    //copy vertices into array buffer for OpenGL
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //copy indices into array buffer for OpenGL
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    //set vertex attribute pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}