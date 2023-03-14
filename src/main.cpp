#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

GLuint WINDOW_WIDTH = 900;
GLuint WINDOW_HEIGHT = 600;

int main()
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *pWindow = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "LearnOpenGL", nullptr, nullptr);
    glfwMakeContextCurrent(pWindow);

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    while (!glfwWindowShouldClose(pWindow))
    {
        glClearColor(0.0, 0.0, 0.5, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(pWindow);
        glfwPollEvents();
    }

    glfwTerminate();
}
