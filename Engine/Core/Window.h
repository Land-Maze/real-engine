#pragma once

struct GLFWwindow;

namespace RealEngine {

    class Window {
    public:
        Window(int width, int height, const char* title);
        ~Window();

        void OnUpdate();
        bool ShouldClose() const;

    private:
        GLFWwindow* m_Window;
    };

}
