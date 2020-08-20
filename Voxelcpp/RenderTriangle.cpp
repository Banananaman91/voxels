#include "RenderTriangle.h"
using namespace renderer;

void RenderTriangle::CreateTriangle(){
    LoadProgram(&shaderProgram, vertPath, fragPath);
    LoadProgram(&shaderProgram2, vertPath, yellowPath);

    //Bind vertex array buffer
    glGenVertexArrays(2, VAOs);
    glGenBuffers(2, VBOs);

    glBindVertexArray(VAOs[0]);

    //copy vertices into array buffer for OpenGL
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);

    //set vertex attribute pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), reinterpret_cast<void*>(0));
    glEnableVertexAttribArray(0);

    glBindVertexArray(VAOs[1]);

    //copy vertices into array buffer for OpenGL
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle2), triangle2, GL_STATIC_DRAW);

    //set vertex attribute pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), reinterpret_cast<void*>(0));
    glEnableVertexAttribArray(0);
}

std::string RenderTriangle::ReadFile(const char *filePath) {
    std::stringstream content;
    std::ifstream fileStream(filePath, std::ios::in);

    if(!fileStream.is_open()) {
        std::cerr << "Could not read file " << filePath << ". File does not exist." << std::endl;
        return "";
    }

    content << fileStream.rdbuf();
    std::string returnString = content.str();

    fileStream.close();
    return returnString;
}

void RenderTriangle::LoadProgram(unsigned int* ShaderProgram, const char* VertPath, const char* FragPath){
    //create vertex shader
    std::string vertexShdrStr = ReadFile(VertPath);
    vertexShaderSource = vertexShdrStr.c_str();
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    //compile shader
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);

    //compile success check
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if (!success){
        glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
        std::cout << "ERROR: SHADER::VERTEX::COMPILATION_FAILED" << std::endl;
        std::cout << infoLog << std::endl;
    }

    //create fragment shader
    std::string fragmentShdrStr = ReadFile(FragPath);
    fragmentShaderSource = fragmentShdrStr.c_str();
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    //compile shader
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);

    //compile success check
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success){
        glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
        std::cout << "ERROR: SHADER::FRAGMENT::COMPILATION_FAILED" << std::endl;
        std::cout << infoLog << std::endl;
    }

    //create shader program
    *ShaderProgram = glCreateProgram();

    //attach shaders and link program
    glAttachShader(*ShaderProgram, vertexShader);
    glAttachShader(*ShaderProgram, fragmentShader);
    glLinkProgram(*ShaderProgram);

    //check link success
    glGetProgramiv(*ShaderProgram, GL_LINK_STATUS, &success);
    if (!success){
        glGetProgramInfoLog(*ShaderProgram, 512, nullptr, infoLog);
        std::cout << "ERROR: SHADER::PROGRAM::LINK_FAILED" << std::endl;
        std::cout << infoLog << std::endl;
    }
    //delete shaders
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}