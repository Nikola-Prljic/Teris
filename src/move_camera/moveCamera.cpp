#include "moveCamera.hpp"

moveCamera::moveCamera(Camera *camera, const float &movmentspeed, const float &rotationSpeed, const float &zoomSpeed) : camera(camera), movmentspeed(movmentspeed), rotationSpeed(rotationSpeed), zoomSpeed(zoomSpeed)
{

}

moveCamera::~moveCamera() { return; }

void moveCamera::ForwardAndBack(float key)
{
    if(key) UpdateCameraPro(camera, Vector3{key * movmentspeed, 0.0f, 0.0f}, Vector3{0.0f, 0.0f, 0.0f}, 0);
}

void moveCamera::LeftAndRight(float key)
{
    if(key) UpdateCameraPro(camera, Vector3{0.0f, key * movmentspeed, 0.0f}, Vector3{0.0f, 0.0f, 0.0f}, 0);
}

void moveCamera::ZoomInAndOut(float key)
{
    if(key) UpdateCameraPro(camera, Vector3{0.0f, 0.0f, 0.0f}, Vector3{0.0f, 0.0f, 0.0f}, key * movmentspeed);
}

// W A S D movement and Q E for rotation
void moveCamera::keyDownMoveCamera() 
{
    ForwardAndBack(IsKeyDown(KEY_W));
    ForwardAndBack(-IsKeyDown(KEY_S));

    LeftAndRight(IsKeyDown(KEY_D));
    LeftAndRight(-IsKeyDown(KEY_A));

    ZoomInAndOut(IsKeyDown(KEY_C));
    ZoomInAndOut(-IsKeyDown(KEY_V));

    if(IsKeyDown(KEY_E))
        rotateCamera(rotationSpeed, true);
    if(IsKeyDown(KEY_Q))
        rotateCamera(-rotationSpeed, true);
}

void moveCamera::rotateCamera(float angle, bool rotateAroundTarget)
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