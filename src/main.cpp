#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include "buildings/House.hpp"
#include "interface/Interface.hpp" 
#include "map.hpp"

void rotateCamera(Camera *camera, float angle, bool rotateAroundTarget)
{
    // Rotation axis
    Vector3 up = camera->up;

    // View vector
    Vector3 targetPosition = Vector3Subtract(camera->target, camera->position);

    // Rotate view vector around up axis
    targetPosition = Vector3RotateByAxisAngle(targetPosition, up, angle);

    if (rotateAroundTarget)
    {
        // Move position relative to target
        camera->position = Vector3Subtract(camera->target, targetPosition);
    }
    else // rotate around camera.position
    {
        // Move target relative to position
        camera->target = Vector3Add(camera->position, targetPosition);
    }
}

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
    Interface interface;

    float angle = 0.0f;
    float radius = 5.0f;

    while(!WindowShouldClose())
    {
        Vector3 movement = Vector3{0.0f, 0.0f, 0.0f};
        float movmentspeed = 0.2f;
        float rotationSpeed = 0.05f;

        if(IsKeyDown(KEY_W))
            movement.x += 1 * movmentspeed;
        if(IsKeyDown(KEY_S))
            movement.x -= 1 * movmentspeed;
        if(IsKeyDown(KEY_A))
            movement.y -= 1 * movmentspeed;
        if(IsKeyDown(KEY_D))
            movement.y += 1 * movmentspeed;

        UpdateCameraPro(&camera, movement, Vector3{0.0f, 0.0f, 0.0f}, CAMERA_PERSPECTIVE);

        if(IsKeyDown(KEY_E))
        {
            rotateCamera(&camera, rotationSpeed, true);
        }
        if (IsKeyDown(KEY_D)) {
            camera.position = Vector3Add(camera.position, Vector3Scale(right, moveSpeed));
            camera.target = Vector3Add(camera.target, Vector3Scale(right_target, moveSpeed));
        if(IsKeyDown(KEY_Q))
        {
            rotateCamera(&camera, -rotationSpeed, true);
        }

        
        RayCollision groundHitInfo = game_map.GetMapCollisionQuad(camera);
        building.setHitBoxPos(groundHitInfo);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            std::cout << "Left" << std::endl;
            House* building2 = new House(building);
            //House building2("H:/Programms 2023/raycasting java/Teris/models/Assets/obj/building_A.obj", "H:/Programms 2023/raycasting java/Teris/models/Assets/obj/citybits_texture.png");
            game_map.setModelOnGameMap(building2, camera);
        }

        //Vector3 interfacePos = Vector3Add(camera.position, Vector3{-0.0f, -0.5f, -0.0f});  
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);
                DrawGrid((int) 10, 1.0f);
                DrawCube(camera.target, 0.1f, 0.1f, 0.1f, RED);
                //DrawModel(model, pos, 1.0f, WHITE);
                if (place_model == false)
                {
                    DrawModel(building.getModel(), groundHitInfo.point, 0.5f, WHITE);
                    for(int i = 0; i < (int)game_map.game_map.size(); i++)
                    {
                        DrawModel(game_map.game_map[i]->getModel(), game_map.game_map[i]->getPos(), 0.5f, WHITE);
                    }
                    DrawBoundingBox(building.getHitBoxPos(), GREEN);
                    place_model = false;
                }
                //DrawRay(ray, RED);
            EndMode3D();

            //UpdateCamera(&camera, CAMERA_PERSPECTIVE);
            //BeginMode3D(camera);
            //    Vector3 interfacePos = camera.target;
            //    interface.draw(building.getModel(), interfacePos);
            //EndMode3D();

            DrawFPS(10, 10);
        EndDrawing();
    }

    building.unload_model();

    CloseWindow();
}