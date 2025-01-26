#pragma once

#include "ABuildings.hpp"
#include <memory>

class House : public ABuildings
{
    private:

        House();
        void f() override;

    public:

        House(const std::string &model_path, const std::string &model_texture_path);

        std::shared_ptr<ABuildings> clone() const override;
};