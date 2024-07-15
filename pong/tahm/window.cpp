#include "seek.h"


extern App app;



void Window::Create(const char* title, int width, int height)
{
    this->title = title;
    this->width = width;
    this->height = height;
}

void Window::initSDL(void)
{

    int rendererFlags, windowFlags;

    rendererFlags = SDL_RENDERER_ACCELERATED;

    windowFlags = 0;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << ("Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    app.window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, windowFlags);

    if (!app.window)
    {
        std::cout << ("Failed to open %d x %d window: %s\n", width, height, SDL_GetError());
        exit(1);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);

    if (!app.renderer)
    {
        std::cout << ("Failed to create renderer: %s\n", SDL_GetError());
        exit(1);
    }
}




void cleanup(void)
{
    SDL_DestroyRenderer(app.renderer);

    SDL_DestroyWindow(app.window);

    SDL_Quit();
}