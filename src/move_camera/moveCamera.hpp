
#include <raylib.h>
#include <raymath.h>

class moveCamera
{
    private:

        Camera *camera;

        float movmentspeed;
        float rotationSpeed;
        float zoomSpeed;

        moveCamera();

    public:

    moveCamera(Camera *camera, const float &movmentspeed, const float &rotationSpeed, const float &zoomSpeed);
    ~moveCamera();

    void ForwardAndBack(float key);
    void LeftAndRight(float key);
    void ZoomInAndOut(float key);
    void keyDownMoveCamera();

    void rotateCamera(float angle, bool rotateAroundTarget);
};