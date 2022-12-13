#include "GameLoop.h"

void GameLoop::run()
{
    bool work = true;
    SDL_Event e;


    while (work) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                work = false;
            }

            if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_UP) {
                    sdl->set_texture(textures.get_at(0));

                }
                if (e.key.keysym.sym == SDLK_DOWN) {
                    sdl->set_texture(textures.get_at(1));

                }
                if (e.key.keysym.sym == SDLK_RIGHT) {

                }
                if (e.key.keysym.sym == SDLK_LEFT) {

                }
            }
        }

        sdl->show_texture();

    }
}

void GameLoop::init(SDL_Adapter* sdl, Textures textures)
{
    this->sdl = sdl;
    this->textures = textures;
}
