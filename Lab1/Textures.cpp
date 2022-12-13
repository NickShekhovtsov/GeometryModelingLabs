#include "Textures.h"

std::string Textures::get_at(int index)
{
    int count = 0;
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

void Textures::add_texture(std::string path)
{
    paths.push_back(path);
}

void Textures::remove_by_path(std::string path)
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

int Textures::get_size()
{
    return paths.size();
}
