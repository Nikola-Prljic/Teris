#include "KeyManager.hpp"

KeyManager::KeyManager() {}

KeyManager::~KeyManager() {}

void KeyManager::update(Interface *interface, std::map<std::string, std::shared_ptr<ABuildings>> &models)
{
    if(IsKeyReleased(KEY_R) && interface->getActiveButtonName() == "house")
    {
        models["house"]->rotate();
    }

    if(IsKeyReleased(KEY_R) && interface->getActiveButtonName() == "road_straight")
    {
        models["road_straight"]->rotate();
    }
}