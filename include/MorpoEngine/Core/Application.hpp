#pragma once
#include <MorpoEngine/ECS/Registry.hpp>

namespace MorpoEngine::Window {
    class Window; 
}

namespace MorpoEngine::Renderer {
    class Renderer; 
}

namespace MorpoEngine::Core {
    class Application {
        public:
        explicit Application(MorpoEngine::Window::Window& window, MorpoEngine::Renderer::Renderer& renderer);
        void run();
        void update(float delta);
        void render();
    private:
        MorpoEngine::Window::Window& m_window;
        MorpoEngine::Renderer::Renderer& m_renderer;

        ECS::Registry m_registry;
    };
}