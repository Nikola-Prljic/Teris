#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include "buildings/House.hpp"
#include "interface/Interface.hpp"
#include "move_camera/moveCamera.hpp"
#include "map.hpp"
#include "buildings/Road.hpp"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Teris");

    House building("H:/Programms 2023/raycasting java/Teris/models/Assets/obj/building_A.obj", "H:/Programms 2023/raycasting java/Teris/models/Assets/obj/citybits_texture.png");
    building.load_model();

    Camera camera = { 0 };
    camera.position = (Vector3){ 5.0f, 5.0f, 5.0f };    // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;

    float movmentspeed = 0.2f;
    float rotationSpeed = 0.04f;
    float zoomSpeed = 0.2f;

    Camera2D cameraInterface = { 0 };
    cameraInterface.target = (Vector2){ 0.0f, 0.0f };
    //cameraInterface.offset = (Vector2){ screenWidth / 2.0f, screenHeight };
    cameraInterface.rotation = 0.0f;
    cameraInterface.zoom = 1.0f;

    moveCamera moveCamera(&camera, movmentspeed, rotationSpeed, zoomSpeed);
    
    SetTargetFPS(30);

    map game_map("Teris", 4);
    Interface interface(800, 80, BLACK);

    while(!WindowShouldClose())
    {
        moveCamera.keyDownMoveCamera();

        RayCollision groundHitInfo;
        groundHitInfo.hit = false;
        if( interface.isMouseOnInterface() == false)
        {
            groundHitInfo = game_map.GetMapCollisionQuad(camera);
            building.setHitBoxPos(groundHitInfo);
        }

        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Vector2 mouse_pos = GetMousePosition();
            if(interface.isClicked(mouse_pos))
            {   
                //Rectangle b_hitbox = interface.getButtonHitBox();
                //bool hitbutton = CheckCollisionPointRec(mouse_pos, interface.getButtonHitBox());
                //std::cout << hitbutton << std::endl;
            }
            else if(groundHitInfo.hit && interface.getActiveButtonName() == "house")
            {
                House* building2 = new House(building);
                //House building2("H:/Programms 2023/raycasting java/Teris/models/Assets/obj/building_A.obj", "H:/Programms 2023/raycasting java/Teris/models/Assets/obj/citybits_texture.png");
                game_map.setModelOnGameMap(building2, camera);
            }
        }

        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);
                DrawGrid((int) 10, 1.0f);
                DrawCube(camera.target, 0.1f, 0.1f, 0.1f, RED);
                //DrawModel(model, pos, 1.0f, WHITE);

                // check if button clicked and mouse on map
                if(interface.getActiveButton() != nullptr && groundHitInfo.hit)
                {
                    // draw building at the mouse position
                    DrawModel(building.getModel(), groundHitInfo.point, 0.5f, WHITE);
                    DrawBoundingBox(building.getHitBoxPos(), GREEN);
                }

                // draw all buildings on the map
                for(size_t i = 0; i < game_map.game_map.size(); i++)
                {
                    DrawModel(game_map.game_map[i]->getModel(), game_map.game_map[i]->getPos(), 0.5f, WHITE);
                }
                //DrawRay(ray, RED);
            EndMode3D();
            BeginMode2D(cameraInterface);
                //DrawGrid((int) 10, 1.0f);
                interface.draw();
                //interface.draw(building.getModel(), interfacePos);
            EndMode2D();
            DrawFPS(10, 10);
        EndDrawing();
    }

    building.unload_model();

    CloseWindow();
}