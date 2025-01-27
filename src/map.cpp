#include "map.hpp"

// needs to be a quatrat so size is one lenght 4 = 4x4
map::map(const std::string &name, const int &size) : name(name), size(size), map_hitbox(), game_map()
{
    Vector3 g0 = (Vector3){ (float)-size, 0.0f, (float)-size };
    Vector3 g1 = (Vector3){ (float)-size, 0.0f,  (float)size };
    Vector3 g2 = (Vector3){  (float)size, 0.0f,  (float)size };
    Vector3 g3 = (Vector3){  (float)size, 0.0f, (float)-size };
    map_hitbox = {g0, g1, g2, g3};
};

map::~map() 
{
    /* for(size_t i = 0; i < game_map.size(); i++)
    {
        delete game_map[i];
    } */
};

RayCollision map::GetMapCollisionQuad(const Camera &camera)
{
    Vector2 mouse_pos = GetMousePosition();
    Ray ray = GetScreenToWorldRay(mouse_pos, camera);
    return GetRayCollisionQuad(ray, map_hitbox[0], map_hitbox[1], map_hitbox[2], map_hitbox[3]);
}

std::vector<std::shared_ptr<ABuildings>> map::getGameMap() { return game_map; }

//Places a Model at the game_map to draw it later.
void map::setModelOnGameMap(const std::shared_ptr<ABuildings> &model, const Camera &camera)
{
    RayCollision groundHitInfo = GetMapCollisionQuad(camera);
    model->setPos(groundHitInfo);
    game_map.push_back(model->clone());
    
}

void map::draw()
{
    for(const std::shared_ptr<ABuildings> & element : game_map)
        if (element)
        {
            DrawModel(element->getModel(), element->getPos(), 0.5f, WHITE);
            DrawBoundingBox(element->getHitBoxPos(), GREEN);
        }
}
