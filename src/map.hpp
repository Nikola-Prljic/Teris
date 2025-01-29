#pragma once

#include <string>
#include <raylib.h>
#include <vector>
#include <map>
#include "buildings/ABuildings.hpp"
#include <memory>
#include "buildings/House.hpp"
#include "buildings/Road.hpp"
//#include <utility>

#include <iostream>

struct MyVector3 : public Vector3
{
    MyVector3(const Vector3 &other)
    {
        this->x = other.x;
        this->y = other.y;
        this->z = other.z;
    }

    bool operator<(const Vector3& other) const {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        return z < other.z;
    }
};

class map {

    private:
        const std::string name;
        const int size;
        std::vector<Vector3> map_hitbox;

        std::map<std::string, std::shared_ptr<ABuildings>> models;
        //std::vector<std::shared_ptr<ABuildings>> game_map;

        using mapModels = std::map<MyVector3, std::shared_ptr<ABuildings>>;
        mapModels game_map;
        //make map with floor(pos) as key for hit box!

        Vector3 pos_last_model;
        RayCollision groundHitInfo;

        bool draw_selected_model;

        map();
        void setRoadOnGameMap(const std::string &model_name, const Camera &camera);

    public:
        bool left_pressed;
        map(const std::string &name, const int &size);
        ~map();

        RayCollision GetMapCollisionQuad(const Camera &camera);
        //std::vector<std::shared_ptr<ABuildings>> getGameMap();

        void setModelOnGameMap(const std::string &model_name, const Camera &camera);

        void draw();
        
        void create_models_map();

        void ModelSetHitbox( const std::string &model_name, const Camera &camera );
        void ModelRotate(const std::string &model_name);

        void drawSelectedModel(const std::string &model_name);

        void update(const bool &is_mouse_on_interface, const std::string &active_button_name, const Camera &camera);
};
