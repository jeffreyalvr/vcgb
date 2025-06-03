#include <GLFW/glfw3.h>
#include <iostream>

int main() {

    if (!glfwInit()) {
        std::cerr << "Couldn't initialize GLFW - Check if the necessary submodules were imported correctly."
                  << std::endl;
        return -1;
    }

    std::cout << "The boilerplate is working as expected, using the following:" << std::endl;
    std::cout << glfwGetVersion << std::endl;

    glfwTerminate();
    return 0;
}