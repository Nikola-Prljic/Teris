#include "button.hpp"
#include <iostream>
button::button(const std::string &name, const Rectangle &hit_box) : _name(name), _hit_box(hit_box), _is_active(false)
{
    std::cout << hit_box.x << std::endl;
}

button::~button()
{
}

Rectangle button::getHitBox() 
{ 
    return _hit_box; 
}

bool button::getIsActive() const { return _is_active; }

void button::setActive(const bool &is_active) 
{ 
    _is_active = is_active; 
}

std::string button::getName() const { return _name; }