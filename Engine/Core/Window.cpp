#include "Window.h"
#include <GLFW/glfw3.h>
#include <stdexcept>

namespace RealEngine {

    Window::Window(int width, int height, const char* title) {
        if (glfwInit() == GLFW_FALSE)
            throw std::runtime_error("Failed to initialize GLFW");

        m_Window = glfwCreateWindow(width, height, title, nullptr, nullptr);
        if (!m_Window) {
            glfwTerminate();
            throw std::runtime_error("Failed to create GLFW window");
        }

		glfwSetWindowPos(m_Window, 500, 500); // To see console window without glfw window overlapping

        glfwMakeContextCurrent(m_Window);
        glfwSwapInterval(1);
    }

    Window::~Window() {
        glfwDestroyWindow(m_Window);
        glfwTerminate();
    }

    void Window::OnUpdate() {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    bool Window::ShouldClose() const {
        return glfwWindowShouldClose(m_Window);
    }

}
