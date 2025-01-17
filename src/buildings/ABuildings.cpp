#include "ABuildings.hpp"

ABuildings::ABuildings(std::string model_path, std::string model_texture_path): model(), texture(), model_path(model_path), model_texture_path(model_texture_path)
{
    load_model();
}

ABuildings::~ABuildings()
{
    UnloadTexture(texture);
    UnloadModel(model);
}

void ABuildings::load_model()
{
    model = LoadModel(model_path.c_str());
    texture = LoadTexture(model_texture_path.c_str());
    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
}

Model ABuildings::getModel()
{
    return model;
}
