#include "ABuildings.hpp"

ABuildings::ABuildings(const std::string &model_path, const std::string &model_texture_path): model(), texture(),  hit_box(), hit_box_pos(), model_path(model_path), model_texture_path(model_texture_path)
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
    hit_box_pos = hit_box;
}

const Model &ABuildings::getModel() const { return model; }

const BoundingBox &ABuildings::getHitBox() const { return hit_box; }

const BoundingBox &ABuildings::getHitBoxPos() const { return hit_box_pos; }

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