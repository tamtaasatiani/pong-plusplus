#include "seek.h"

void Tahm::Renderer::create(SDL_Window* SDLwindow)
{
    this->SDLwindow = SDLwindow;
}

void Tahm::Renderer::init(void)
{
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    SDLrenderer = SDL_CreateRenderer(SDLwindow, -1, flags);

    if (!SDLrenderer)
    {
        std::cout << ("Failed to create renderer: %s\n", SDL_GetError());
        exit(1);
    }
}



void Tahm::Renderer::prepare(void)
{
    SDL_SetRenderDrawColor(SDLrenderer, 0, 0, 0, 255);
    SDL_RenderClear(SDLrenderer);
}

void Tahm::Renderer::present(void)
{
    if (SDLrenderer == nullptr)
    {
        std::cout << ("SDL renderer not present\n", SDL_GetError());
        return;
    }

    SDL_RenderPresent(SDLrenderer);
}
