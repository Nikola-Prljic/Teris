#pragma once

#include "ABuildings.hpp"

class Road : public ABuildings
{
    private:

        Road();
        void f() override;

    public:
        bool conected_road;
        Vector3 conected_road_pos;

        std::shared_ptr<ABuildings> clone() const override;
        Road(const std::string &model_path, const std::string &model_texture_path);
        void rotateX(const bool &x) override;
        bool rotateIfKeyHold(const Vector3 pos_last_model, const bool &left_pressed) override;
};