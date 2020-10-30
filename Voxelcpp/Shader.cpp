#include "Shader.h"
#include "FileReader.h"
using namespace renderer;
using namespace freader;

Shader::Shader(const char* vertexPath, const char* fragmentPath){
    //create vertex shader
    FileReader reader;
    std::string vertexShdrStr = reader.ReadFile(vertexPath);
    const char* vertexShaderSource = vertexShdrStr.c_str();
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

    //compile shader
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);

    //compile success check
    CheckCompileErrors(vertexShader, "VERTEX");

    //create fragment shader
    std::string fragmentShdrStr = reader.ReadFile(fragmentPath);
    const char* fragmentShaderSource = fragmentShdrStr.c_str();
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    //compile shader
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);

    //compile success check
    CheckCompileErrors(fragmentShader, "FRAGMENT");

    //create shader program
    ID = glCreateProgram();

    //attach shaders and link program
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    glLinkProgram(ID);

    //check link success
    CheckCompileErrors(ID, "PROGRAM");
    //delete shaders
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::use() const{
    glUseProgram(ID);
}

void Shader::SetBool(const std::string &name, bool value) const{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::SetInt(const std::string &name, int value) const{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::SetFloat(const std::string &name, float value) const{
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::SetVec2(const std::string &name, const glm::vec2 &value) const{
    glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}

void Shader::SetVec2(const std::string &name, float x, float y) const{
    glUniform2f(glGetUniformLocation(ID, name.c_str()), x, y);
}

void Shader::SetVec3(const std::string &name, const glm::vec3 &value) const{
    glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}

void Shader::SetVec3(const std::string &name, float x, float y, float z) const{
    glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);
}

void Shader::SetVec4(const std::string &name, const glm::vec4 &value) const{
    glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}

void Shader::SetVec4(const std::string &name, float x, float y, float z, float w) const{
    glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w);
}

void Shader::SetMat2(const std::string &name, const glm::mat2 &mat) const{
    glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::SetMat3(const std::string &name, const glm::mat3 &mat) const{
    glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::SetMat4(const std::string &name, const glm::mat4 &mat) const{
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::CheckCompileErrors(GLuint shader, std::string type){
        GLint success;
        GLchar infoLog[1024];
        if (type != "PROGRAM")
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
        else
        {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
}