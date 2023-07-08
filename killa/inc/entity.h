#pragma once
#include <SFML/Graphics.hpp>


namespace ent 
{
    class Entity 
    {
    private:
        sf::Vector2f inertion = sf::Vector2f(0, 0);

        int sign(float n);

    public:
        float friction = 0;
        sf::Vector2f coord = sf::Vector2f(0, 0);

        Entity(double x, double y);

        virtual void draw(sf::RenderWindow& window) {}

        sf::Vector2f getCoord();

        void setInertion(float x, float y);

        void updateInertion(float deltaTime);

        void update(float deltaTime);
    };
}