#include "enemy.h"

using namespace en;
Enemy::Enemy(double x, double y) : Entity(x, y) {}

void Enemy::draw(sf::RenderWindow& window, pl::Player& player) 
{
    sf::CircleShape shape(radius);
    sf::Vector2f playerCoord = player.getCoord();
    int x = coord.x - playerCoord.x + windowWidth / 2;
    int y = coord.y - playerCoord.y + windowHeight / 2;
    shape.setPosition(sf::Vector2f(x - radius, y - radius));
    shape.setFillColor(sf::Color(115, 66, 34));
    window.draw(shape);
}

void Enemy::updateMovement(float deltaTime, pl::Player& player) 
{
    sf::Vector2f playerCoord = player.getCoord();
    float x = coord.x - playerCoord.x;
    float y = coord.y - playerCoord.y;
    float angle = atan2(x, y) - 3.14 / 2;

    coord.x -= cos(angle) * speed * deltaTime;
    coord.y -= sin(-angle) * speed * deltaTime;
}
void Enemy::update(float deltaTime, pl::Player& player) 
{
    updateMovement(deltaTime, player);
}
float Enemy::getRadius() 
{
    return radius;
}