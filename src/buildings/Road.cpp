#include "Road.hpp"

Road::Road(const std::string &model_path, const std::string &model_texture_path) : ABuildings(model_path, model_texture_path)
{
    return ;
}

void Road::f()
{
    return ;
}

std::shared_ptr<ABuildings> Road::clone() const
{
    return std::make_shared<Road>(*this);
}
#include <iostream>
// model will rotae true for horizontal
void Road::rotateX(const bool &x)
{
    std::cout << yaw << std::endl;
    if(x && (yaw == 0 || yaw == 180))
        rotate();
    if(!x && (yaw == 90 || yaw == 270))
        rotate();
}