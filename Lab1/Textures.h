#pragma once
#include <list>
#include <string>
class Textures
{
private:
    std::list<std::string> paths;
public:
    std::string get_at(int index);
   
    void add_texture(std::string path);

    void remove_by_path(std::string path);
    int get_size();
    
};

