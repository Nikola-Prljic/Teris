#pragma once

#include <string>
#include <raylib.h>
#include <raymath.h>

class Interface
{
    private:

        int width_background;
        int height_background;
        Color color_background;

        Rectangle buttonHitBox;

        void drawInterfaceBackground();
        void drawInterfaceButtons();

        Interface();

    public:

        Interface(const int &width_background, const int &height_background, const Color &color_background);
        ~Interface();

        void draw();
        Rectangle getButtonHitBox();


};
