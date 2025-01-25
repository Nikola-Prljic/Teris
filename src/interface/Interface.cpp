#include "Interface.hpp"

Interface::Interface(const int &width_background, const int &height_background, const Color &color_background) : 
width_background(width_background), height_background(height_background), color_background(color_background), 
texture(), _button_map(), _active_button(nullptr)
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
    /* std::string button_name = "house";
    button new_button("house", Rectangle{0, 520, 100, 80});
    _button_map.emplace("house", std::make_unique<button>(new_button));
    //button_map["house"] = new_button;
    _button_map.emplace("house", std::make_unique<button>(new_button)); */

    createButton("house", Rectangle{0, 520, 100, 80});
    createButton("road_straight", Rectangle{100, 520, 100, 80});
}

void Interface::createButton(const std::string &button_name, const Rectangle &hitbox)
{
    button new_button(button_name, hitbox);
    _button_map.emplace(button_name, std::make_unique<button>(new_button));
}

void Interface::draw()
{
    DrawTexture(texture, 0, 520, WHITE);
    //button_map["house"].getHitBox();
    if(_active_button)
        DrawRectangleLinesEx(_active_button->getHitBox(), 4.0f, GREEN);
}

bool Interface::isClicked(const Vector2 &mouse_pos)
{
    return setActiveButtonIfClicked(mouse_pos, "house");
    //bool hitbutton = CheckCollisionPointRec(mouse_pos, interface.getButtonHitBox());
    //std::cout << hitbutton << std::endl;
}

bool Interface::setActiveButtonIfClicked(const Vector2 &mouse_pos, const std::string &button_name)
{
    std::shared_ptr<button> active_button = _button_map[button_name];

    if (CheckCollisionPointRec(mouse_pos, active_button->getHitBox()) == false)
        return false;
    _active_button = active_button;
    return true;
}

bool Interface::isMouseOnInterface()
{
    Vector2 mouse_pos = GetMousePosition();
    return CheckCollisionPointRec(mouse_pos, Rectangle{0, 520, static_cast<float>(texture.width), static_cast<float>(texture.height)});
}

// can return nullptr !
std::shared_ptr<button> Interface::getActiveButton()
{
    return _active_button;
}

std::string Interface::getActiveButtonName() const
{
    if (_active_button)
        return _active_button->getName();
    return std::string("");
}
