#pragma once

#include <string>
#include <raylib.h>

class ABuildings 
{
    private:

        Model model;
        std::string model_path;
        std::string model_texture_path;
        
        ABuildings();
        void load_model();
    
    public:
        ABuildings(std::string model_path, std::string model_texture_path);

};