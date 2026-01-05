#include <MorpoEngine/Renderer/Renderer.hpp>
#include <SDL.h>

namespace MorpoEngine::Renderer {
    Renderer::Renderer(SDL_Window* window) {
        m_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        SDLK_w;
    }

    Renderer::~Renderer() {
        SDL_DestroyRenderer(m_renderer);
    }
}
