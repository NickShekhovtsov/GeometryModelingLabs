#include <iostream>
#include <vector>

#include "SDL.h"
#include "imgui.h"
#include "imgui_impl_sdlrenderer.h"
#include "imgui_impl_sdl.h"
#include <string>
#include <list>
#include <iterator>
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
class Textures
{
private:
    std::list<std::string> paths;
public:
    std::string get_at(int index)
    {
        int count=0;
        for (auto st : paths)
        {
            if (count == index)
            {
                return st;
            }
            else
            {
                count++;
            }
        }
        return "";
    }
    void add_texture(std::string path)
    {
        paths.push_back(path);
    }

    void remove(std::string path)
    {
        auto iter = path.cbegin();
        for (auto st : paths)
        {
            if (st == path)
            {
                path.erase(iter);
            }
            else
            {
                iter++;
            }
        }
    }
    int get_size()
    {
        return paths.size();
    }
};
class SDL_Adapter
{
protected:
    SDL_Window* window=nullptr;
    SDL_Surface* bmp = nullptr;
    SDL_Texture* tex = nullptr;
    SDL_Renderer* renderer = nullptr;
public:
    void init(std::string title,int width,int height )
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

    void set_texture(std::string path)
    {
        bmp = SDL_LoadBMP(path.c_str());
        tex = SDL_CreateTextureFromSurface(renderer, bmp);
        SDL_FreeSurface(bmp);
        
    }

    void show_texture()
    {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, tex, NULL, NULL);
        SDL_RenderPresent(renderer);
        //SDL_Delay(2000);
    }

    SDL_Texture* get_text()
    {
        return tex;
    }

    SDL_Adapter()
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        {
            std::cout << "SDL init falure\n";
        }
    }

    ~SDL_Adapter()
    {
        SDL_DestroyTexture(tex);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
};

class GameLoop
{
    SDL_Adapter* sdl;
    Textures textures;
public:
    void run()
    {
        bool work = true;
        SDL_Event e;
        IMGuiAdapter ad;
       
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

    void init(SDL_Adapter* sdl,Textures textures)
    {
        this->sdl = sdl;
        this->textures = textures;
    }

};
int main(int argc, char** argv)
{
   
    std::vector<Uint32> bufferForUpdate(400 * 400);
    SDL_Adapter* sdl=new SDL_Adapter();
    Textures textures;
    textures.add_texture("H:\\Tests\\123.bmp");
    textures.add_texture("H:\\Tests\\222.bmp");
    sdl->init("my_own", 400, 400);
    //sdl.set_texture(textures.get_at(0));
    //sdl.show_texture();
   

    ////SDL_Delay(1000);
    //sdl.set_texture(textures.get_at(1));
    //sdl.show_texture();

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