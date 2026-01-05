#include <MorpoEngine/Window/Window.hpp>
#include <MorpoEngine/Window/Window.hpp>
#include <MorpoEngine/Input/Input.hpp>
#include <SDL.h>
#include <string>
#include <iostream>

namespace MorpoEngine::Window {
    Window::Window(int width, int height, std::string title) :  m_width(width), m_height(height), m_title(title) {
        m_window = SDL_CreateWindow(m_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, SDL_WINDOW_SHOWN);
    }
    
    Window::~Window() {
        SDL_DestroyWindow(m_window);
    }

    void Window::poolEvents() {
        SDL_Event event;

        while(SDL_PollEvent(&event)) {
            SDL_Keycode keycode = event.key.keysym.sym;
            const char* key_name = SDL_GetKeyName(keycode);

            std::string log = "Key ";
            log.append(key_name);
            switch (event.type) {
                case SDL_QUIT:
                m_shouldClose = true;
                break;
                case SDL_KEYDOWN:
                log.append(" pressed");
                Input::Input::setKeyIsPressed(key_name, true);
                std::cout << log << std::endl;
                break;
                case SDL_KEYUP:
                log.append(" release");
                Input::Input::setKeyIsPressed(key_name, false);
                std::cout << log << std::endl;
            break;
            }

        }
    }

    bool Window::shouldClose() {
        return m_shouldClose;
    }

    SDL_Window* Window::nativeHandle() const noexcept {
        return m_window;
    }
}