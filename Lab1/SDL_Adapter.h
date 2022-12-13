#pragma once
#include <iostream>
#include "SDL.h"
#include "imgui.h"
#include "imgui_impl_sdlrenderer.h"
#include "imgui_impl_sdl.h"
#include <string>
#include <list>
#include <iterator>
#include "Textures.h"
class SDL_Adapter
{
protected:
    SDL_Window* window = nullptr;
    SDL_Surface* bmp = nullptr;
    SDL_Texture* tex = nullptr;
    SDL_Renderer* renderer = nullptr;
public:
    void init(std::string title, int width, int height);

    void set_texture(std::string path);
    void show_texture();
    SDL_Texture* get_texture();

    SDL_Adapter();
    ~SDL_Adapter();
   
};

