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
#include"SDL_Adapter.h"
class GameLoop
{
    SDL_Adapter* sdl;
    Textures textures;
public:
    void run();

    void init(SDL_Adapter* sdl, Textures textures);
   

};

