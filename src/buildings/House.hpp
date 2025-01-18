#pragma once

#include "ABuildings.hpp"

class House : public ABuildings
{
    private:

        House();
        void f() override;

    public:

        House(std::string model_path, std::string model_texture_path);
};