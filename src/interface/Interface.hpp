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
        std::map<std::string, std::shared_ptr<button>> _button_map; 
        
        std::shared_ptr<button> _active_button;

        Interface();

        void createButton(const std::string &button_name, const Rectangle &hitbox);

    public:

        Interface(const int &width_background, const int &height_background, const Color &color_background);
        ~Interface();

        void createButtons();

        void draw();

        bool isClicked(const Vector2 &mouse_pos);
        bool setActiveButtonIfClicked(const Vector2 &mouse_pos, const std::string &button_name);
        bool isMouseOnInterface();

        std::shared_ptr<button> getActiveButton();
        std::string getActiveButtonName() const;
};
