#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(std::string &vertexShaderPath, std::string &fragmentShaderPath)
{
    std::string vertexCode, fragmentCode;
    std::ifstream vertexFile, fragmentFile;

    vertexFile.open(vertexShaderPath);
    fragmentFile.open(fragmentShaderPath);

    std::stringstream vStream, fStream;

    vStream << vertexFile.rdbuf();
    fStream << fragmentFile.rdbuf();

    vertexCode = vStream.str();
    fragmentCode = fStream.str();

    GLuint vertexShader;
    if(!createShader(vertexShader, vertexCode, GL_VERTEX_SHADER))
    {
        std::cerr << "SHADER::VERTEX::CREATION ERROR\n";
    }

    GLuint fragmentShader;
    if(!createShader(fragmentShader, fragmentCode, GL_FRAGMENT_SHADER))
    {
        std::cerr << "SHADER::FRAGEMNT::CREATION ERROR\n";
    }

    prog_ID = glCreateProgram();
    glAttachShader(prog_ID, vertexShader);
    glAttachShader(prog_ID, fragmentShader);
    glLinkProgram(prog_ID);

    char infoLog[512];
    int success;
    glGetProgramiv(prog_ID, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(prog_ID, sizeof(infoLog), nullptr, infoLog);
        std::cerr << "ERROR::SHADER_PROGRAM::LINK::" << infoLog << std::endl;
    }
}

bool ShaderProgram::createShader(GLuint &shader, std::string &shaderCode, GLenum ShaderType)
{
    shader = glCreateShader(ShaderType);
    const char* code = shaderCode.c_str();
    glShaderSource(shader, 1, &code, nullptr);
    glCompileShader(shader);

    char infoLog[512];
    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shader, sizeof(infoLog), nullptr, infoLog);
        std::cerr << "SHADER::ERROR::" << infoLog << std::endl;
        return false;
    }
    return true;
}

