#include "src/Window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace vcgb {

Window::Window(const char* title, int width, int height) {
    m_title = title;
    m_width = width;
    m_height = height;

    if (!init()) {
        shutdown();
    }
}

Window::~Window() {
    shutdown();
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(m_window);
}

void Window::update() {
    glfwPollEvents();
    glfwSwapBuffers(m_window);
}

bool Window::init() {
    if (!glfwInit()) {
        std::cerr << "Couldn't initialize GLFW - Check if the necessary submodules were imported correctly."
                  << std::endl;
        return false;
    }

    m_window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);

    if (!m_window) {
        std::cerr << "Failed to create GLFW window." << std::endl;
        return false;
    }

    glfwMakeContextCurrent(m_window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD - Check if the necessary submodules were imported correctly."
                  << std::endl;
        glfwDestroyWindow(m_window);
        return false;
    }

    int major, minor, rev;
    glfwGetVersion(&major, &minor, &rev);

    std::cout << "The boilerplate is working as expected, using the following:" << std::endl;
    std::cout << "GLFW v." << major << "." << minor << "." << rev << std::endl;
    std::cout << "OpenGL v." << glGetString(GL_VERSION) << std::endl;

    return true;
}

void Window::shutdown() {
    glfwTerminate();
}
} // namespace vcgb