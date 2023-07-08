#include "map.h"
using namespace mp;

void Map::draw(sf::RenderWindow& window, pl::Player& player) 
{
    sf::Vector2f playerCoord = player.getCoord();
    int cellX = playerCoord.x / cellSize;
    int cellY = playerCoord.y / cellSize;

    for (int i = -1; i < (windowWidth / cellSize + 2); i++) 
    {
        for (int j = -1; j < (windowHeight / cellSize + 2); j++) 
        {
            sf::RectangleShape shape;
            shape.setSize(sf::Vector2f(cellSize, cellSize));
            shape.setPosition(sf::Vector2f(-(int)playerCoord.x % cellSize + i * cellSize, -(int)playerCoord.y % cellSize + j * cellSize));

            if (abs(i + cellX) % 2 == abs(j + cellY) % 2) 
            {
                shape.setFillColor(sf::Color(76, 87, 216));
            }
            else 
            {
                shape.setFillColor(sf::Color(114 + rand() % 5, 121 + rand() % 5, 216 + rand() % 5));
            }

            window.draw(shape);
        }
    }
}