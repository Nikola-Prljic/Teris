#include "map.hpp"

// needs to be a quatrat so size is one lenght 4 = 4x4
map::map(const std::string name, const int size) : name(name), size(size), map_hitbox()
{
    Vector3 g0 = (Vector3){ (float)-size, 0.0f, (float)-size };
    Vector3 g1 = (Vector3){ (float)-size, 0.0f,  (float)size };
    Vector3 g2 = (Vector3){  50.0f, 0.0f,  (float)size };
    Vector3 g3 = (Vector3){  50.0f, 0.0f, (float)-size };
    map_hitbox = {g0, g1, g2, g3};
};

map::~map() 
{
    
};

RayCollision map::GetMapCollisionQuad(Vector2 mouse_pos, Camera camera)
{
    Ray ray = GetScreenToWorldRay(mouse_pos, camera);
    RayCollision groundHitInfo = GetRayCollisionQuad(ray, map_hitbox[0], map_hitbox[1], map_hitbox[2], map_hitbox[3]);
    return groundHitInfo;
}
