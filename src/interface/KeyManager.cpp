#include "KeyManager.hpp"

KeyManager::KeyManager() {}

KeyManager::~KeyManager() {}

void KeyManager::update(Interface &interface, map &game_map, std::map<std::string, std::shared_ptr<ABuildings>> &models, const RayCollision &groundHitInfo, const Camera &camera)
{
    if(IsKeyReleased(KEY_R) && interface.getActiveButtonName() == "house")
    {
        models["house"]->rotate();
    }

    if(IsKeyReleased(KEY_R) && interface.getActiveButtonName() == "road_straight")
    {
        models["road_straight"]->rotate();
    }

    // we cklick some where on map so we need to desice waht is happening
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        Vector2 mouse_pos = GetMousePosition();

        // if mouse cklicked on interface or not cklicked on map return
        if(interface.isClicked(mouse_pos) || groundHitInfo.hit == false)
            return ;

        // get the active button "" means we have not cklicked on something to place so we return
        std::string button_name = interface.getActiveButtonName();
        if(button_name == "")
            return ;

        // get the model and clone it save it in game map so we can draw it later
        std::shared_ptr<ABuildings> deepCopy = models[button_name]->clone();
        game_map.setModelOnGameMap(deepCopy, camera);
    }
}