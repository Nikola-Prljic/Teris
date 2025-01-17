#include "ABuildings.hpp"

ABuildings::ABuildings(std::string model_path, std::string model_texture_path): model(), model_path(model_path), model_texture_path(model_texture_path)
{
    load_model();
}

ABuildings::~ABuildings()
{
    //UnloadModel(model);
}

void ABuildings::load_model()
{
    //Model model = LoadModel(model_path.c_str());
    //Texture2D texture = LoadTexture(model_texture_path.c_str());
    //model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
}
