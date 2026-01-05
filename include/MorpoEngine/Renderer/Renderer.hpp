#pragma once

struct SDL_Window;
struct SDL_Renderer;

namespace MorpoEngine::Renderer {
    class Renderer {
    public:
        Renderer(SDL_Window* window);
        ~Renderer();
    private:
        SDL_Renderer* m_renderer = nullptr;;
    };
} 

