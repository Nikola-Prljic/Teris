#include "Interface.hpp"

Interface::Interface(const int &width_background, const int &height_background, const Color &color_background) : 
width_background(width_background), height_background(height_background), color_background(color_background), 
buttonHitBox()
{
    float offset_height = height_background * 0.9f;
    float button_height = height_background * 0.8f;

    float button_width = height_background * 0.8f;
    float button_offset = width_background / 2 - height_background * 0.1f;

    buttonHitBox = Rectangle{400 - button_offset, 450 - offset_height, button_width, button_height};
    return ;
}

Interface::~Interface() {}

void Interface::draw()
{
    drawInterfaceBackground();
    drawInterfaceButtons();
}

// centers the background
void Interface::drawInterfaceBackground()
{
    DrawRectangle(-(width_background / 2), -height_background, width_background, height_background, color_background);
}

void Interface::drawInterfaceButtons()
{
    float offset_height = height_background * 0.9f;
    float button_height = height_background * 0.8f;

    float button_width = height_background * 0.8f;
    float button_offset = -(width_background / 2 - height_background * 0.1f);

    DrawRectangle(button_offset, -offset_height, button_width, button_height, Color{12, 35, 71, 200});
}

Rectangle Interface::getButtonHitBox()
{
    return buttonHitBox;
}