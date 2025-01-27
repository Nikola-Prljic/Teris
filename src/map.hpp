#pragma once

#include <string>
#include <raylib.h>
#include <vector>
#include "buildings/ABuildings.hpp"
#include <memory>

class map {

    private:
        const std::string name;
        const int size;
        std::vector<Vector3> map_hitbox;
        std::vector<std::shared_ptr<ABuildings>> game_map;
        map();

    public:
        map(const std::string &name, const int &size);
        ~map();

        RayCollision GetMapCollisionQuad(const Camera &camera);
        std::vector<std::shared_ptr<ABuildings>> getGameMap();

        void setModelOnGameMap(const std::shared_ptr<ABuildings> &model, const Camera &camera);

        void draw();
};
