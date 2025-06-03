#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
    if (!glfwInit()) {
        std::cerr << "Couldn't initialize GLFW - Check if the necessary submodules were imported correctly."
                  << std::endl;
        return -1;
    }

    // Create a temporary window to create an OpenGL context before initializing GLAD
    GLFWwindow* window = glfwCreateWindow(800, 600, "vcgb", NULL, NULL);

    if (!window) {
        std::cerr << "Failed to create GLFW window." << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD - Check if the necessary submodules were imported correctly."
                  << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }

    int major, minor, rev;
    glfwGetVersion(&major, &minor, &rev);

    std::cout << "The boilerplate is working as expected, using the following:" << std::endl;
    std::cout << "GLFW v." << major << "." << minor << "." << rev << std::endl;
    std::cout << "OpenGL v." << glGetString(GL_VERSION) << std::endl;

    glfwTerminate();
    return 0;
}