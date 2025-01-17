#ifndef MAP_HPP
#define MAP_HPP

#include <string>
#include <raylib.h>
#include <vector>

class map {

    private:
        const std::string name;
        const int size;
        std::vector<Vector3> map_hitbox;
        map();

    public:
        map(const std::string name, const int size);
        ~map();

        RayCollision GetMapCollisionQuad(Vector2 mouse_pos, Camera camera);

};

#endif
