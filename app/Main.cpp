#include <MorpoEngine/Core/Application.hpp>
#include <MorpoEngine/Window/Window.hpp>
#include <MorpoEngine/Renderer/Renderer.hpp>

int main(int argc, char* argv[]) {
    MorpoEngine::Window::Window window(800, 600, "Teste");
    MorpoEngine::Renderer::Renderer renderer(window.nativeHandle());

    MorpoEngine::Core::Application application(window, renderer);
    application.run();
}

// const int WINDOW_WIDTH = 800;
// const int WINDOW_HEIGHT = 600;

// int main(int argc, char* argv[]) {
//     SDL_Window* window = NULL;
//     SDL_Renderer* renderer = NULL;

//     if (SDL_Init(SDL_INIT_VIDEO) != 0) {
//         std::cerr << "SDL failed to initialize! SDL_Error: " << SDL_GetError() << std::endl;
//         return 1;
//     }

//     if (SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN, &window, &renderer) < 0) {
//         std::cerr << "Window and renderer creation failed! SDL_Error: " << SDL_GetError() << std::endl;
//         SDL_Quit();
//         return 1;
//     }

//     bool quit = false;
//     SDL_Event e;

//     while (!quit) {
//         while (SDL_PollEvent(&e) != 0) {
//             if (e.type == SDL_QUIT) {
//                 quit = true;
//             }
//         }

//         SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 
//         SDL_RenderClear(renderer); 
//         SDL_RenderPresent(renderer); 
//     }

//     SDL_DestroyRenderer(renderer);
//     SDL_DestroyWindow(window);
//     SDL_Quit();

//     return 0;
// }
