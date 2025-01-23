#include "Interface.hpp"

Interface::Interface(const int &width_background, const int &height_background, const Color &color_background) : 
width_background(width_background), height_background(height_background), color_background(color_background), 
texture(), _button_map()
{
    Image image  = LoadImage("img/interface.png");
    texture = LoadTextureFromImage(image);
    UnloadImage(image);

    createButtons();

    return ;
}

Interface::~Interface() 
{
    UnloadTexture(texture);
}

void Interface::createButtons()
{
    std::string button_name = "house";
    button new_button("house", Rectangle{0, 520, 100, 80});
    _button_map.emplace("house", std::make_unique<button>(new_button));
    //button_map["house"] = new_button;
}

void Interface::draw()
{
    DrawTexture(texture, 0, 520, WHITE);
    //button_map["house"].getHitBox();
    DrawRectangleLinesEx(_button_map.at("house")->getHitBox(), 4.0f, GREEN);
}
