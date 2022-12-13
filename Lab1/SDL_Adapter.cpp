#include "SDL_Adapter.h"

void SDL_Adapter::init(std::string title, int width, int height)
{
    window = SDL_CreateWindow(title.c_str(),
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (!window)
    {
        std::cout << "Couldn't create window\n";

    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        std::cout << "Couldn't create renderer\n";
    }
}

void SDL_Adapter::set_texture(std::string path)
{
    bmp = SDL_LoadBMP(path.c_str());
    tex = SDL_CreateTextureFromSurface(renderer, bmp);
    SDL_FreeSurface(bmp);
}

void SDL_Adapter::show_texture()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, tex, NULL, NULL);
    SDL_RenderPresent(renderer);
}

SDL_Texture* SDL_Adapter::get_texture()
{
    return tex;
}

SDL_Adapter::SDL_Adapter()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "SDL init falure\n";
    }
}

SDL_Adapter::~SDL_Adapter()
{
    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
