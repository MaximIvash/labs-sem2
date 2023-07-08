#pragma once
#include "entity.h"



namespace bul
{
    
    class Bullet : public ent::Entity
    {
    private:
        int windowWidth = 1280;
        int windowHeight = 720;
    public:
        int radius = 20;

        Bullet(double x, double y, double speed);

        void draw(sf::RenderWindow& window, sf::Vector2f playerCoord);

        int getRadius();
    };
}

