#include "Road.hpp"

Road::Road(const std::string &model_path, const std::string &model_texture_path) : ABuildings(model_path, model_texture_path), 
up(), down(), left(), right()
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

// saves the roads that are conected to this road
void Road::setConnectedRoad(std::weak_ptr<Road> weak_last_road, std::weak_ptr<Road> weak_this_road)
{
    enum Xdir {RIGHT = -1, LEFT = 1};
    enum Zdir {UP = 1, DOWN = -1};

    if(std::shared_ptr<Road> last_road = weak_last_road.lock())
    {
        Vector3 direction = Vector3Subtract(getPos(), last_road->pos);

        if(direction.x == RIGHT)
        {
            right = last_road;
            last_road->left = weak_this_road; 
            std::cout << "right" << std::endl;
        }
        else if(direction.x == LEFT)
        {
            left = last_road;
            last_road->right = weak_this_road; 
            std::cout << "left" << std::endl;
        }
        else if(direction.z == UP)
        {
            up = last_road;
            last_road->down = weak_this_road; 
            std::cout << "up" << std::endl;
        }
        else if(direction.z == DOWN)
        {
            down = last_road;
            last_road->up = weak_this_road; 
            std::cout << "down" << std::endl;
        }
    }
}

bool Road::hasAnyConectedRoads()
{
    if(up.expired() == false)
        return true;
    if(down.expired() == false)
        return true;
    if(left.expired() == false)
        return true;
    if(right.expired() == false)
        return true;
    return false;
}

int Road::getRoadType()
{
    int i = 0;

    if(up.expired() == false)
        i += 1;
    if(down.expired() == false)
        i += 1;
    if(left.expired() == false)
        i += 1;
    if(right.expired() == false)
        i += 1;
    return i;
}

void Road::setNewRoadType()
{
    enum RoadType : int { NONE, STRAIGHT, CURVE, T_INTERSECTION, INTERSECTION};
    int type = getRoadType();

    switch (type)
    {
        case STRAIGHT:
            std::cout << "STRAIGHT" << std::endl;
            break;

        case CURVE:
            setCURVE();
            break;
        
        case T_INTERSECTION:
            std::cout << "T_INTERSECTION" << std::endl;
            break;
        
        case INTERSECTION:
            std::cout << "INTERSECTION" << std::endl;
            break;

        case NONE:
            std::cout << "NONE" << std::endl;
            break;

        default:
            break;
    }
}

void Road::setCURVE()
{
    if(up.expired() == false && left.expired() == false)
        std::cout << "curve left to top" << std::endl;
}