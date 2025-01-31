#include "Road.hpp"

Road::Road(const std::string &model_path, const std::string &model_texture_path) : ABuildings(model_path, model_texture_path), conected_road(false), conected_road_pos()
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
    setConnectedRoad(pos_last_model);
    return true;
}

void Road::setConnectedRoad(const Vector3 pos_last_model)
{
    enum Xdir {RIGHT = -1, LEFT = 1};
    enum Zdir {UP = -1, DOWN = 1};

    Vector3 direction = Vector3Subtract(getPos(), pos_last_model);

    if(direction.x == RIGHT)
    {
        conected_road_pos.right = pos_last_model;
        std::cout << "right" << std::endl;
    }
    if(direction.x == LEFT)
        std::cout << "left" << std::endl;
    if(direction.z == UP)
        std::cout << "up" << std::endl;
    if(direction.z == DOWN)
        std::cout << "down" << std::endl;
}