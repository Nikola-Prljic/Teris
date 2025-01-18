#pragma once

#include <string>
#include <raylib.h>

class ABuildings 
{
    protected:

        Model model;
        Texture2D texture;

        std::string model_path;
        std::string model_texture_path;
        
        ABuildings();
        void load_model();
        virtual void f() = 0;
    
    public:
        ABuildings(std::string model_path, std::string model_texture_path);
        ~ABuildings();

        Model getModel();
};