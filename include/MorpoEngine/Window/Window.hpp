#pragma once
#include <string>

struct SDL_Window;

namespace MorpoEngine::Window {
    class Window {
    public:
        explicit Window(int width, int height, std::string title);
        ~Window();
        SDL_Window* nativeHandle() const noexcept;
        void poolEvents();
        bool shouldClose();
    private: 
        SDL_Window* m_window;
        std::string m_title;
        int m_width;
        int m_height;
        bool m_shouldClose = false;
    };
}