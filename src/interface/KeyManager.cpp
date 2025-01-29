#include "KeyManager.hpp"

KeyManager::KeyManager() {}

KeyManager::~KeyManager() {}

void KeyManager::update(Interface &interface, map &game_map, const Camera &camera)
{
    if(IsKeyReleased(KEY_R) && interface.getActiveButtonName() == "house")
    {
        game_map.ModelRotate("house");
    }

    if(IsKeyReleased(KEY_R) && interface.getActiveButtonName() == "road_straight")
    {
        game_map.ModelRotate("road_straight");
    }

    // we cklick some where on map so we need to desice waht is happening
    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        Vector2 mouse_pos = GetMousePosition();

        // if mouse cklicked on interface or not cklicked on map return
        if(interface.isClicked(mouse_pos))
            return ;

        // get the active button "" means we have not cklicked on something to place so we return
        std::string button_name = interface.getActiveButtonName();
        if(button_name == "")
            return ;

        // get the model and clone it save it in game map so we can draw it later
        //std::shared_ptr<ABuildings> deepCopy = models[button_name]->clone();
        game_map.setModelOnGameMap(button_name, camera);
        game_map.left_pressed = true;
    }

    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
    {
        game_map.left_pressed = false;
    }
}