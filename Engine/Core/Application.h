#pragma once

#include <memory>

namespace RealEngine {

    class Window;

    class Application {
    public:
        Application();
        ~Application();

        void Run();
        void Init();

    private:
        std::unique_ptr<Window> m_Window;
    };

}