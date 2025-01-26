#include "House.hpp"

House::House(const std::string &model_path, const std::string &model_texture_path) : ABuildings(model_path, model_texture_path)
{
    return ;
}

void House::f()
{
    return ;
}

std::shared_ptr<ABuildings> House::clone() const
{
    return std::make_shared<House>(*this);
}