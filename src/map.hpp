#pragma once

#include <string>
#include <raylib.h>
#include <vector>
#include <map>
#include "buildings/ABuildings.hpp"
#include <memory>
#include "buildings/House.hpp"
#include "buildings/Road.hpp"

class map {

    private:
        const std::string name;
        const int size;
        std::vector<Vector3> map_hitbox;

        std::map<std::string, std::shared_ptr<ABuildings>> models;
        std::vector<std::shared_ptr<ABuildings>> game_map;
        //make map with floor(pos) as key for hit box!

        RayCollision groundHitInfo;
        bool draw_selected_model;

        map();

    public:
        map(const std::string &name, const int &size);
        ~map();

        RayCollision GetMapCollisionQuad(const Camera &camera);
        std::vector<std::shared_ptr<ABuildings>> getGameMap();

        void setModelOnGameMap(const std::string &model_name, const Camera &camera);

        void draw();
        
        void create_models_map();

        void ModelSetHitbox( const std::string &model_name, const Camera &camera );
        void ModelRotate(const std::string &model_name);

        void drawSelectedModel(const std::string &model_name);

        void update(const bool &is_mouse_on_interface, const std::string &active_button_name, const Camera &camera);
};
