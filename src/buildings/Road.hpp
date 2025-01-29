#pragma once

#include "ABuildings.hpp"

class Road : public ABuildings
{
    private:

        Road();
        void f() override;

    public:

        std::shared_ptr<ABuildings> clone() const override;
        Road(const std::string &model_path, const std::string &model_texture_path);
        void rotateX(const bool &x) override;
};