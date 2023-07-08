#pragma once
#include "player.h"

namespace mp 
{
    class Map 
    {
        int windowWidth = 1280;
        int windowHeight = 720;
    public:
        int cellSize = 100;
    public:
        void draw(sf::RenderWindow& window, pl::Player& player);
    };
}
