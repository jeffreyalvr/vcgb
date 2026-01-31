#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace vcgb {

class Window {
  private:
    GLFWwindow* m_window;
    int m_width;
    int m_height;
    const char* m_title;

  public:
    Window(const char* title, int width, int height);
    ~Window();

    void update();
    bool shouldClose() const;

  private:
    bool init();
    void shutdown();
};
} // namespace vcgb