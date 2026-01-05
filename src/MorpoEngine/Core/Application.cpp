#include <SDL.h>
#include <MorpoEngine/Core/Application.hpp>
#include <MorpoEngine/Renderer/Renderer.hpp>
#include <MorpoEngine/Window/Window.hpp>


namespace MorpoEngine::Core {
    Application::Application(MorpoEngine::Window::Window& window, 
        MorpoEngine::Renderer::Renderer& renderer) : 
        m_window(window), m_renderer(renderer) {}

    void Application::run() {
        Uint32 last = SDL_GetTicks();

        while(!m_window.shouldClose()) {
            Uint32 now = SDL_GetTicks();
            float dt = (now - last) / 1000.0f;

            update(dt);
            m_window.poolEvents();
        }

    }

    void Application::update(float delta) {

    }

    void Application::render() {
    }
}