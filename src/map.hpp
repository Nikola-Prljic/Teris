#ifndef MAP_HPP
#define MAP_HPP

#include <string>
#include <raylib.h>
#include <vector>
#include "buildings/ABuildings.hpp"

class map {

    private:
        const std::string name;
        const int size;
        std::vector<Vector3> map_hitbox;
        map();

    public:
        std::vector<ABuildings *> game_map;
        map(const std::string name, const int size);
        ~map();

        RayCollision GetMapCollisionQuad(const Camera &camera);
        std::vector<ABuildings *> getGameMap();

        void setModelOnGameMap(ABuildings *model, const Camera &camera);

};

#endif
