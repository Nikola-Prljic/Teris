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
