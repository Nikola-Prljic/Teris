#include <raylib.h>
#include <raymath.h>
#include <iostream>
//#include "buildings/ABuildings.hpp"
#include "map.hpp"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Teris");

    Model model = LoadModel("H:/Programms 2023/raycasting java/Teris/models/Assets/obj/building_A.obj");
    Texture2D texture = LoadTexture("H:/Programms 2023/raycasting java/Teris/models/Assets/obj/citybits_texture.png");
    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;

    //ABuildings building("H:/Programms 2023/raycasting java/Teris/models/Assets/obj/building_A.obj", "H:/Programms 2023/raycasting java/Teris/models/Assets/obj/citybits_texture.png");

    Camera camera = { 0 };
    camera.position = (Vector3){ 5.0f, 5.0f, 5.0f }; // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };     // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;
    
    Vector3 pos = (Vector3){ 1.0f, 0.0f, -1.0f };
    //pos = (Vector3){ 0.0f, 0.0f, 0.0f };
    BoundingBox boundsOri = GetMeshBoundingBox(model.meshes[0]);
    BoundingBox bounds = boundsOri;
    bounds.min = Vector3Add(bounds.min, pos);
    bounds.max = Vector3Add(bounds.max, pos);

    //bool selected = false;          // Selected object flag

    SetTargetFPS(30);



    Ray ray = { 0 };

    Vector2 mouse_pos = { 0 };

    bool place_model = false;

    map game_map("Teris", 4);

    while(!WindowShouldClose())
    {
        UpdateCamera(&camera, CAMERA_PERSPECTIVE);

        mouse_pos = GetMousePosition();
        ray = GetScreenToWorldRay(mouse_pos, camera);
        
        RayCollision groundHitInfo = game_map.GetMapCollisionQuad(mouse_pos, camera);

        //RayCollision groundHitInfo = GetRayCollisionQuad(ray, map_hitbox[0], map_hitbox[1], map_hitbox[2], map_hitbox[3]);

        if (groundHitInfo.hit)
        {
            std::cout << "Mouse Pos: (" << mouse_pos.x << ", " << mouse_pos.y << ")" << std::endl;
            std::cout << "Ray Origin: (" << ray.position.x << ", " << ray.position.y << ", " << ray.position.z << ")" << std::endl;
            std::cout << "Ray Direction: (" << ray.direction.x << ", " << ray.direction.y << ", " << ray.direction.z << ")" << std::endl;
        }

        //if (!IsKeyPressed(KEY_W))
        //{
            //pos.x += 1;
            //bounds.min.x += 1;
            //bounds.max.x += 1;

            //place_model = true;
        //}

        //bounds = UpdateBoundingBox(bounds, pos);
        bounds.min = Vector3Add(boundsOri.min, groundHitInfo.point);
        bounds.max = Vector3Add(boundsOri.max, groundHitInfo.point);
            
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);
                DrawGrid((int) 10, 2.0f);
                //DrawModel(model, pos, 1.0f, WHITE);
                if (place_model == false)
                {
                    DrawModel(model, groundHitInfo.point, 1.0f, WHITE);
                    DrawBoundingBox(bounds, GREEN);
                    place_model = false;
                }
                DrawRay(ray, RED);
            EndMode3D();

            DrawFPS(10, 10);
        EndDrawing();
    }

    //UnloadTexture(texture);
    UnloadModel(model);
    CloseWindow();
}