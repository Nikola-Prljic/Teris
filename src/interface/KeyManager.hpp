#pragma once

#include <raylib.h>
#include "Interface.hpp"
#include <memory>
#include "../buildings/ABuildings.hpp"

class KeyManager
{
    private:

    public:
        KeyManager();
        ~KeyManager();

        void update(Interface *interface, std::map<std::string, std::shared_ptr<ABuildings>> &models);
};