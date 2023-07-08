#pragma once
#include "entity.h"
#include "player.h"

namespace en 
{
    class Enemy : public ent::Entity
    {
    private:
        int windowWidth = 1280;
        int windowHeight = 720;
    public:
        float speed = 300;
        float radius = 70;

        Enemy(double x, double y);

        void draw(sf::RenderWindow& window, pl::Player& player);

        void updateMovement(float deltaTime, pl::Player& player);

        void update(float deltaTime, pl::Player& player);

        float getRadius();
    };
}