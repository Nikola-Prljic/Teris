#pragma once

#include <raylib.h>
#include "Interface.hpp"
#include <memory>
#include "../buildings/ABuildings.hpp"
#include "../map.hpp"

class KeyManager
{
    private:

    public:
        KeyManager();
        ~KeyManager();

        void update(Interface &interface, map &game_map, std::map<std::string, std::shared_ptr<ABuildings>> &models, const RayCollision &groundHitInfo, const Camera &camera);
};