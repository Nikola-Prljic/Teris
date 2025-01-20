#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include "buildings/House.hpp"
#include "map.hpp"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Teris");

    House building("H:/Programms 2023/raycasting java/Teris/models/Assets/obj/building_A.obj", "H:/Programms 2023/raycasting java/Teris/models/Assets/obj/citybits_texture.png");
    building.load_model();

    Camera camera = { 0 };
    camera.position = (Vector3){ 5.0f, 5.0f, 5.0f }; // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };     // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(30);

    bool place_model = false;

    map game_map("Teris", 4);

    while(!WindowShouldClose())
    {
        UpdateCamera(&camera, CAMERA_PERSPECTIVE);

        //ray = GetScreenToWorldRay(mouse_pos, camera);
        
        RayCollision groundHitInfo = game_map.GetMapCollisionQuad(camera);
        building.setHitBoxPos(groundHitInfo);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            std::cout << "Left" << std::endl;
            House* building2 = new House(building);
            //House building2("H:/Programms 2023/raycasting java/Teris/models/Assets/obj/building_A.obj", "H:/Programms 2023/raycasting java/Teris/models/Assets/obj/citybits_texture.png");
            game_map.setModelOnGameMap(building2, camera);
        }
            
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);
                DrawGrid((int) 10, 1.0f);
                //DrawModel(model, pos, 1.0f, WHITE);
                if (place_model == false)
                {
                    DrawModel(building.getModel(), groundHitInfo.point, 1.0f, WHITE);
                    for(int i = 0; i < (int)game_map.game_map.size(); i++)
                    {
                        DrawModel(game_map.game_map[i]->getModel(), game_map.game_map[i]->getPos(), 1.0f, WHITE);
                    }
                    DrawBoundingBox(building.getHitBoxPos(), GREEN);
                    place_model = false;
                }
                //DrawRay(ray, RED);
            EndMode3D();

            DrawFPS(10, 10);
        EndDrawing();
    }

    building.unload_model();

    CloseWindow();
}