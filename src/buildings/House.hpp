#pragma once

#include "ABuildings.hpp"

class House : public ABuildings
{
    private:

        House();
        void f() override;

    public:

        House(const std::string &model_path, const std::string &model_texture_path);
};