#include "player.h"

using namespace pl;

Player::Player() : ent::Entity(0, 0) 
{
    
    speed = 500;
    friction = 500;
}

void Player::draw(sf::RenderWindow& window) 
{
    float radius = 30;
    sf::CircleShape shape(radius);
    shape.setPosition(sf::Vector2f(windowWidth / 2 - radius, windowHeight / 2 - radius));
    shape.setFillColor(sf::Color(255, 204, 64));
    window.draw(shape);
};

void Player::move(double dx, double dy, double deltaTime) 
{
    double angleK = cos(3.14 / 4);
    if (dx != 0 && dy != 0) {
        dx *= angleK;
        dy *= angleK;
    }
    coord.x += dx * speed * deltaTime;
    coord.y += dy * speed * deltaTime;
}

bul::Bullet Player::shot(sf::RenderWindow& window) 
{
    float mouseX = sf::Mouse::getPosition(window).x - windowWidth / 2;
    float mouseY = sf::Mouse::getPosition(window).y - windowHeight / 2;
    float angle = atan2(mouseX, mouseY) - 3.14 / 2;
    float inertion = 300;
    setInertion(-inertion * cos(angle), -inertion * sin(-angle));

    float bulletSpeed = 1300;
    bul::Bullet bullet(coord.x, coord.y, bulletSpeed);
    bullet.setInertion(bulletSpeed * cos(angle), bulletSpeed * sin(-angle));

    return bullet;
}