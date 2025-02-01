#pragma once

#include "ABuildings.hpp"
#include <vector>
#include <iostream>

class Road : public ABuildings
{
    private:

        Road();
        void f() override;

        // conected roads

    public:

        std::weak_ptr<Road> up;
        std::weak_ptr<Road> down;
        std::weak_ptr<Road> left;
        std::weak_ptr<Road> right;
        

        std::shared_ptr<ABuildings> clone() const override;
        Road(const std::string &model_path, const std::string &model_texture_path);
        void rotateX(const bool &x) override;
        bool rotateIfKeyHold(const Vector3 pos_last_model, const bool &left_pressed);
        void setConnectedRoad(std::weak_ptr<Road> weak_last_road, std::weak_ptr<Road> weak_this_road);

        bool hasAnyConectedRoads();

        int getRoadType();
        void setNewRoadType();

        void setCURVE();

};