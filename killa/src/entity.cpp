#include "entity.h"

using namespace ent;
    
int Entity::sign(float n) 
{
    if (n >= 0) {
        return 1;
    }
    return -1;
}
 
Entity::Entity(double x, double y) 
{
    coord.x = x;
    coord.y = y;
}

    

sf::Vector2f Entity::getCoord() 
{
    return coord;
}

void Entity::setInertion(float x, float y) 
{
    inertion.x = x;
    inertion.y = y;
}

void Entity::updateInertion(float deltaTime) 
{
    coord.x += inertion.x * deltaTime;
    coord.y += inertion.y * deltaTime;

    if (abs(inertion.x) > 5 * deltaTime) 
    {
        inertion.x -= friction * deltaTime * sign(inertion.x);
    }
    else 
    {
        inertion.x = 0;
    }

    if (abs(inertion.y) > 5 * deltaTime) 
    {
        inertion.y -= friction * deltaTime * sign(inertion.y);
    }
    else 
    {
        inertion.y = 0;
    }
}

void Entity::update(float deltaTime) 
{
    updateInertion(deltaTime);
}