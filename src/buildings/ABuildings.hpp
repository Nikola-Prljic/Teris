#pragma once

#include <string>
#include <raylib.h>
#include <raymath.h>
#include <memory>
#include <iostream>

class ABuildings 
{
    protected:

        Model model;
        Texture2D texture;

        BoundingBox hit_box;
        BoundingBox hit_box_pos;

        std::string model_path;
        std::string model_texture_path;
        
        Vector3 pos;
        

        ABuildings();
        virtual void f() = 0;
    
    public:
        int yaw;

        virtual std::shared_ptr<ABuildings> clone() const = 0;
        ABuildings(const std::string &model_path, const std::string &model_texture_path);
        virtual ~ABuildings();

        void load_model();
        void unload_model();

        const Model &getModel() const;
        const BoundingBox &getHitBox() const;
        const BoundingBox &getHitBoxPos() const;
        Vector3 getPos();
        
        void setPos(const RayCollision &groundHitInfo);
        void setHitBoxPos(const RayCollision &groundHitInfo);


        void rotate();

        ABuildings(const ABuildings& other);

        // road specific funktions
        virtual void rotateX(const bool &x) {
            std::cout << "WTF" << std::endl;
        }
};