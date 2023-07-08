#pragma once
#include "bullet.h"
#include "entity.h"

namespace pl 
{
    class Player : public ent::Entity 
    {
    int windowWidth = 1280;
    int windowHeight = 720;
    public:
        double speed = 0;

        Player();

        void draw(sf::RenderWindow& window);

        void move(double dx, double dy, double deltaTime);

        bul::Bullet shot(sf::RenderWindow& window);
    };
}