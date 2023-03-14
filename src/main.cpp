#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "renderer/ShaderProgram.h"

GLuint WINDOW_WIDTH = 900;
GLuint WINDOW_HEIGHT = 600;

void window_size_callback(GLFWwindow* window, int width, int height);
void press_input(GLFWwindow* window);

int main()
{
    glfwInit();

    /* GLFW config */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* window creation */
    GLFWwindow *pWindow = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "LearnOpenGL", nullptr, nullptr);
    if(!pWindow)
    {
        std::cerr <<"WINDOW::CREATION ERROR\n";
        glfwTerminate();
    }
    glfwMakeContextCurrent(pWindow);

    /* callbacks */
    glfwSetWindowSizeCallback(pWindow, window_size_callback);

    /* GLAD load */
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "GLAD::LOAD ERROR\n";
        glfwTerminate();
    }

    /* sahdering */
    
    std::string vertexPath("D:/projects/LearnOpenGL/shaders/VertexShader.txt");
    std::string fragmentPath("D:/projects/LearnOpenGL/shaders/FragmentShader.txt");
    ShaderProgram shader_prog(vertexPath, fragmentPath);

    /* render cycle */
    while (!glfwWindowShouldClose(pWindow))
    {
        press_input(pWindow);

        glClearColor(0.0, 0.0, 0.5, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(pWindow);
        glfwPollEvents();
    }

    glfwTerminate();
}

void window_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0,0, width, height);
}

void press_input(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}
