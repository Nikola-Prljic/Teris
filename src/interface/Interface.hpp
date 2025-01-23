#pragma once

#include <string>
#include <raylib.h>
#include <raymath.h>
#include "button.hpp"
#include <map>
#include <memory>

class Interface
{
    private:

        int width_background;
        int height_background;
        Color color_background;

        Texture2D texture;
        std::map<std::string, std::unique_ptr<button>> _button_map; 
        //std::map<std::string, button> button_map;

        Interface();

    public:

        Interface(const int &width_background, const int &height_background, const Color &color_background);
        ~Interface();

        void createButtons();

        void draw();


};
