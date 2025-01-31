#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include "buildings/House.hpp"
#include "interface/Interface.hpp"
#include "move_camera/moveCamera.hpp"
#include "map.hpp"
#include "buildings/Road.hpp"
#include "interface/KeyManager.hpp"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Teris");

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

    KeyManager keyManager;
    
    SetTargetFPS(30);

    map game_map("Teris", 4);
    Interface interface(800, 80, BLACK);

    while(!WindowShouldClose())
    {
        moveCamera.keyDownMoveCamera();

        game_map.update(interface.isMouseOnInterface(), interface.getActiveButtonName(), camera);
        keyManager.update(interface, game_map, camera);

        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                DrawGrid((int) 10, 1.0f);
                DrawCube(camera.target, 0.1f, 0.1f, 0.1f, RED);

                game_map.draw();
                game_map.drawSelectedModel(interface.getActiveButtonName());

                DrawLine3D((Vector3){ 0, 0, 0 }, (Vector3){ 5, 0, 0 }, RED);    // X-Axis
                DrawLine3D((Vector3){ 0, 0, 0 }, (Vector3){ 0, 5, 0 }, GREEN);  // Y-Axis
                DrawLine3D((Vector3){ 0, 0, 0 }, (Vector3){ 0, 0, 5 }, BLUE);   // Z-Axis

            EndMode3D();

            BeginMode2D(cameraInterface);

                interface.draw();
                DrawText("X", 700, 20, 20, RED);   // X-axis label
                DrawText("Y", 700, 40, 20, GREEN);  // Y-axis label
                DrawText("Z", 700, 60, 20, BLUE);   // Z-axis label

            EndMode2D();

            DrawFPS(10, 10);

        EndDrawing();
    }

    CloseWindow();
}