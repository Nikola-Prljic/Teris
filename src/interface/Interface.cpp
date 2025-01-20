#include "Interface.hpp"

Interface::Interface() {}

Interface::~Interface() {}

void Interface::draw(const Model &model, Vector3 pos)
{
    DrawModel(model, pos, 0.01f, WHITE);
}