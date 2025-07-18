#include "Application.h"
#include "Window.h"
#include <glad/glad.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include <Renderer/Renderer.h>

namespace RealEngine {

    Application::Application() {
        m_Window = std::make_unique<Window>(1280, 720, "Real Engine");
		Init();
    }

    Application::~Application() {}

    void Application::Run() {
        RealEngine::Renderer renderer;

        while (!m_Window->ShouldClose()) {
            renderer.Draw();
            m_Window->OnUpdate();
        }
    }

    void Application::Init() {
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cerr << "[Engine] Failed to initialize GLAD." << std::endl;
            std::exit(EXIT_FAILURE);
        }

        std::cout << "[Engine] OpenGL version loaded: " << glGetString(GL_VERSION) << std::endl;
    }
}
