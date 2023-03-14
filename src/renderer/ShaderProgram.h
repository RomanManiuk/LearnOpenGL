#include <iostream>
#include <fstream>
#include <sstream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class ShaderProgram
{
public:
    ShaderProgram(std::string &vertexShaderPath, std::string &fragmentShaderPath);
    ~ShaderProgram() { glDeleteProgram(prog_ID); };
    int getID() { return prog_ID; }
    void useProg() { glUseProgram(prog_ID); }

private:
    bool createShader(GLuint &shader, std::string &shaderCode, GLenum ShaderType);
    GLuint prog_ID;
};
