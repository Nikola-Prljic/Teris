#pragma once

#include "ABuildings.hpp"

class Road : public ABuildings
{
    private:

        Road();
        void f() override;

    public:

        Road(const std::string &model_path, const std::string &model_texture_path);
};