#include <iostream>
#include <vector>

#include "SDL.h"
#include "imgui.h"
#include "imgui_impl_sdlrenderer.h"
#include "imgui_impl_sdl.h"
#include <string>
#include <list>
#include <iterator>
#include "Textures.h"
#include "Textures.h"
#include "SDL_Adapter.h"
#include "GameLoop.h"
class IMGuiAdapter
{
    public:
    void init()
    {
        // UpdateImage

        ImGui_ImplSDLRenderer_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();


        ImGui::Begin("Window");

        if (ImGui::Button("Yellow"))
        {
            /*for (int i = 0; i < bufferForUpdate.size(); i++)
            {
                bufferForUpdate[i] = 0xffff0000;
            }*/
            //SDL_UpdateTexture(texture, nullptr, bufferForUpdate.data(), textureWidth * sizeof(bufferForUpdate[0]));
        }

        if (ImGui::Button("Green"))
        {
            /*for (int i = 0; i < bufferForUpdate.size(); i++)
            {
                bufferForUpdate[i] = 0x44944A00;
            }
            SDL_UpdateTexture(texture, nullptr, bufferForUpdate.data(), textureWidth * sizeof(bufferForUpdate[0]));*/
        }

        if (ImGui::Button("White"))
        {
            /*for (int i = 0; i < bufferForUpdate.size(); i++)
            {
                bufferForUpdate[i] = 0xffffffff;
            }
            SDL_UpdateTexture(texture, nullptr, bufferForUpdate.data(), textureWidth * sizeof(bufferForUpdate[0]));*/
        }

        if (ImGui::Button("Black"))
        {
            /*for (int i = 0; i < bufferForUpdate.size(); i++)
            {
                bufferForUpdate[i] = 0x00000000;
            }
            SDL_UpdateTexture(texture, nullptr, bufferForUpdate.data(), textureWidth * sizeof(bufferForUpdate[0]));*/
        }

        ImGui::End();


        ImGui::Render();

        /*SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, nullptr, nullptr);

        ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
        SDL_RenderPresent(renderer);*/
    }
};

//Из того что планирую сделать прикрутить к game_loop фпс
//Загрузка в текстуры не тольно фотографий, но и заливок
//IMGui поле в SDL_Adapter, с методом добавлением кнопок, для кнопок, наверное, сделаю интерфейс, чтобы от него можно было наследоваться

int main(int argc, char** argv)
{
   
    std::vector<Uint32> bufferForUpdate(400 * 400);
    SDL_Adapter* sdl=new SDL_Adapter();
    Textures textures;
    textures.add_texture("H:\\Tests\\123.bmp");
    textures.add_texture("H:\\Tests\\222.bmp");
    sdl->init("my_own", 400, 400);
   
    GameLoop game;
    game.init(sdl, textures);
    game.run();
   
    
    //SDL_Delay(1000);
    /*for (int i = 0; i < bufferForUpdate.size(); i++)
    {
        bufferForUpdate[i] = 0x00000000;
    }*/

    //SDL_UpdateTexture(sdl.get_text(), nullptr, bufferForUpdate.data(), 400 * sizeof(bufferForUpdate[0]));

   /* bool programWorks = true;
    int fps = 60;
    Uint64 trueFrameTime = 1000.f / fps;
    while (programWorks)
    {
        Uint64 frameTime = SDL_GetTicks();
        {
            SDL_Event e;
            while (SDL_PollEvent(&e))
            {
                ImGui_ImplSDL2_ProcessEvent(&e);
                if (e.type == SDL_QUIT)
                    programWorks = false;
            }
        }
    }*/
    /*bool run = true;
    SDL_Event e;
    SDL_Rect r;

    int x = 0;
    int y = 0;

    r.x = x;
    r.y = y;
    while (run) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                run = false;
            }

            if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_UP) {
                    sdl.set_texture(textures.get_at(0));
                    
                }
                if (e.key.keysym.sym == SDLK_DOWN) {
                    sdl.set_texture(textures.get_at(1));
                   
                }
                if (e.key.keysym.sym == SDLK_RIGHT) {
                    x += 1;
                }
                if (e.key.keysym.sym == SDLK_LEFT) {
                    x -= 1;
                }
            }
        }
        r.x = x;
        r.y = y;
        sdl.show_texture();*/
       /* SDL_FillRect(scr, NULL, SDL_MapRGB(scr->format, 255, 255, 255));

        SDL_BlitSurface(john, NULL, scr, &r);

        SDL_UpdateWindowSurface(win);*/
    //}
    //    // UpdateImage
    //    {
    //        ImGui_ImplSDLRenderer_NewFrame();
    //        ImGui_ImplSDL2_NewFrame();
    //        ImGui::NewFrame();
    //        
    //        {
    //            ImGui::Begin("Window");

    //            if (ImGui::Button("Yellow"))
    //            {
    //                for (int i = 0; i < bufferForUpdate.size(); i++)
    //                {
    //                    bufferForUpdate[i] = 0xffff0000;
    //                }
    //                SDL_UpdateTexture(texture, nullptr, bufferForUpdate.data(), textureWidth * sizeof(bufferForUpdate[0]));
    //            }

    //            if (ImGui::Button("Green"))
    //            {
    //                for (int i = 0; i < bufferForUpdate.size(); i++)
    //                {
    //                    bufferForUpdate[i] = 0x44944A00;
    //                }
    //                SDL_UpdateTexture(texture, nullptr, bufferForUpdate.data(), textureWidth * sizeof(bufferForUpdate[0]));
    //            }

    //            if (ImGui::Button("White"))
    //            {
    //                for (int i = 0; i < bufferForUpdate.size(); i++)
    //                {
    //                    bufferForUpdate[i] = 0xffffffff;
    //                }
    //                SDL_UpdateTexture(texture, nullptr, bufferForUpdate.data(), textureWidth * sizeof(bufferForUpdate[0]));
    //            }

    //            if (ImGui::Button("Black"))
    //            {
    //                for (int i = 0; i < bufferForUpdate.size(); i++)
    //                {
    //                    bufferForUpdate[i] = 0x00000000;
    //                }
    //                SDL_UpdateTexture(texture, nullptr, bufferForUpdate.data(), textureWidth * sizeof(bufferForUpdate[0]));
    //            }

    //            ImGui::End();
    //        }

    //        ImGui::Render();

    //        SDL_RenderClear(renderer);
    //        SDL_RenderCopy(renderer, texture, nullptr, nullptr);

    //        ImGui_ImplSDLRenderer_RenderDrawData(ImGui::GetDrawData());
    //        SDL_RenderPresent(renderer);
    //    }
    //    
    //    frameTime = SDL_GetTicks() - frameTime;
    //    if (frameTime < trueFrameTime)
    //    {
    //        SDL_Delay(trueFrameTime - frameTime);
    //    }
    //        
    //}

    //ImGui_ImplSDLRenderer_Shutdown();
    //ImGui_ImplSDL2_Shutdown();
    //ImGui::DestroyContext();

    //SDL_DestroyTexture(texture);
    //SDL_DestroyRenderer(renderer);
    //SDL_DestroyWindow(window);

    return 0;
}