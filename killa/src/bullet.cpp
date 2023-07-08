#include "bullet.h"

using namespace bul;
Bullet::Bullet(double x, double y, double speed) : Entity(x, y)
{
    friction = 5;
}
void Bullet::draw(sf::RenderWindow& window, sf::Vector2f playerCoord)
{
    sf::CircleShape shape(radius);
    int x = coord.x - playerCoord.x + windowWidth / 2;
    int y = (coord.y - playerCoord.y) + windowHeight / 2;
    shape.setPosition(sf::Vector2f(x - radius, y - radius));
    shape.setFillColor(sf::Color(255, 187, 0));
    window.draw(shape);
}

int Bullet::getRadius() 
{
    return radius;
}