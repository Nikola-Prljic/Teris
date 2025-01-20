#include "ABuildings.hpp"

ABuildings::ABuildings(const std::string &model_path, const std::string &model_texture_path): model(), texture(),  hit_box(), hit_box_pos(), model_path(model_path), model_texture_path(model_texture_path), pos()
{
    //load_model();
}

ABuildings::~ABuildings()
{
    //UnloadTexture(texture);
    //UnloadModel(model);
}

void ABuildings::load_model()
{
    model = LoadModel(model_path.c_str());
    texture = LoadTexture(model_texture_path.c_str());
    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
    hit_box = GetMeshBoundingBox(model.meshes[0]);
    //scale hit box down because it should fit in a 1x1 grid
    hit_box.min = Vector3Multiply(hit_box.min, Vector3{0.5f, 0.5f, 0.5f});
    hit_box.max = Vector3Multiply(hit_box.max, Vector3{0.5f, 0.5f, 0.5f});
    hit_box_pos = hit_box;
}

const Model &ABuildings::getModel() const { return model; }

const BoundingBox &ABuildings::getHitBox() const { return hit_box; }

const BoundingBox &ABuildings::getHitBoxPos() const { return hit_box_pos; }

Vector3 ABuildings::getPos() { return pos; }

#include <iostream>

//floors the number and checks if odd other wise add 1
float getCellCenter(const float &num)
{
    int x = static_cast<int>(std::floor(num));
    return (x += (x % 2 == 0));
}

// one cell of the grid is 2x2 so when user cklicks center the model
void ABuildings::setPos(const RayCollision &groundHitInfo) 
{
    pos.x = std::floor(groundHitInfo.point.x) + 0.5;
    pos.z = std::floor(groundHitInfo.point.z) + 0.5;
}

void ABuildings::setHitBoxPos(const RayCollision &groundHitInfo)
{
    hit_box_pos.min = Vector3Add(hit_box.min, groundHitInfo.point);
    hit_box_pos.max = Vector3Add(hit_box.max, groundHitInfo.point);
}

void ABuildings::unload_model()
{
    UnloadTexture(texture);
    UnloadModel(model);
}