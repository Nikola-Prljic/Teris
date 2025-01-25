#pragma once

#include <string>
#include <raylib.h>
#include <raymath.h>

class button
{
    private:

        std::string _name;
        Rectangle _hit_box;
        bool _is_active;

    public:
        button(const std::string &name, const Rectangle &hit_box);
        ~button();

        Rectangle getHitBox();
        bool getIsActive() const;

        void setActive(const bool &is_active);

        std::string getName() const;

};
