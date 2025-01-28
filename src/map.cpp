#include "map.hpp"

// needs to be a quatrat so size is one lenght 4 = 4x4
map::map(const std::string &name, const int &size) : name(name), size(size), map_hitbox(), models(), game_map(), groundHitInfo(), draw_selected_model(false)
{
    create_models_map();
    Vector3 g0 = (Vector3){ (float)-size, 0.0f, (float)-size };
    Vector3 g1 = (Vector3){ (float)-size, 0.0f,  (float)size };
    Vector3 g2 = (Vector3){  (float)size, 0.0f,  (float)size };
    Vector3 g3 = (Vector3){  (float)size, 0.0f, (float)-size };
    map_hitbox = {g0, g1, g2, g3};
};

map::~map() 
{
    for (auto const& [key, val] : models)
    {
        std::cout << "\033[34m[map.cpp][18] Unload model: " << key << "\033[0m" << std::endl;
        val->unload_model();
    }
};

RayCollision map::GetMapCollisionQuad(const Camera &camera)
{
    Vector2 mouse_pos = GetMousePosition();
    Ray ray = GetScreenToWorldRay(mouse_pos, camera);
    return GetRayCollisionQuad(ray, map_hitbox[0], map_hitbox[1], map_hitbox[2], map_hitbox[3]);
}

std::vector<std::shared_ptr<ABuildings>> map::getGameMap() { return game_map; }

//Places a Model at the game_map to draw it later.
void map::setModelOnGameMap(const std::string &model_name, const Camera &camera)
{
    //RayCollision groundHitInfo = GetMapCollisionQuad(camera);
    if(groundHitInfo.hit == false || draw_selected_model == false)
        return ;
    models[model_name]->setPos(groundHitInfo);
    game_map.push_back(models[model_name]->clone());
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

void map::create_models_map()
{
    House building("H:/Programms 2023/raycasting java/Teris/models/Assets/obj/building_A.obj", "H:/Programms 2023/raycasting java/Teris/models/Assets/obj/citybits_texture.png");
    building.load_model();

    Road road_straight("H:/Programms 2023/raycasting java/Teris/models/Assets/obj/road_straight.obj", "H:/Programms 2023/raycasting java/Teris/models/Assets/obj/citybits_texture.png");
    road_straight.load_model();

    models.emplace("house", std::make_shared<House>(building));
    models.emplace("road_straight", std::make_shared<Road>(road_straight));
}

void map::ModelSetHitbox( const std::string &model_name, const Camera &camera)
{
    models.at(model_name)->setHitBoxPos(groundHitInfo);
}

void map::ModelRotate(const std::string &model_name)
{
    models.at(model_name)->rotate();
}

void map::drawSelectedModel(const std::string &model_name)
{
    if(draw_selected_model)
    {
        DrawModel(models.at(model_name)->getModel(), groundHitInfo.point, 0.5f, WHITE);
        DrawBoundingBox(models.at(model_name)->getHitBoxPos(), GREEN);
    }
}

void map::update(const bool &is_mouse_on_interface, const std::string &active_button_name, const Camera &camera)
{
    groundHitInfo = GetMapCollisionQuad(camera);

    draw_selected_model = false;
    if(is_mouse_on_interface == false && active_button_name != "" && groundHitInfo.hit)
    {
        ModelSetHitbox(active_button_name, camera);
        draw_selected_model = true;
    }
}

