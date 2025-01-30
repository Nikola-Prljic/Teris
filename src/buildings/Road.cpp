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

bool Road::rotateIfKeyHold(const Vector3 pos_last_model, const bool &left_pressed)
{
    Vector3 new_road_pos = this->getPos();
    if(pos_last_model.y != 0 || left_pressed == false)
        return false;
    //Vector3 new_road_pos = models.at(model_name)->getPos();
    if(Vector3Distance(pos_last_model, new_road_pos) != 1)
    {
        std::cout << "distance to big" << std::endl;
        return false;
    }
    if(pos_last_model.x != new_road_pos.x)
        rotateX(true);
    if(pos_last_model.z != new_road_pos.z)
        rotateX(false);
    return true;
}