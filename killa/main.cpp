#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <windows.h>
#include <ctime>
#include <vector>
#include "entity.h"
#include "bullet.h"
#include "player.h"
#include "enemy.h"
#include "map.h"


int main()
{   
    int windowWidth = 1280;
    int windowHeight = 720;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "killa");
    sf::Clock deltaClock;
    double deltaTime = 0;
    double enemyTime = 0;
    double cdTime = 0;

    window.setVerticalSyncEnabled(true);
    pl::Player player;
    mp::Map map;
    std::vector<bul::Bullet> bullets;
    std::vector<en::Enemy> enemies;

    double dx = 0, dy = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {   
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                dy = -1;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                dy = 1;
            }
            else {
                dy = 0;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
            {
                dx = -1;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                dx = 1;
            }
            else 
            {
                dx = 0;
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (cdTime > 0.1)) 
            {
                cdTime = 0;
                bul::Bullet bullet = player.shot(window);
                bullets.push_back(bullet);
            }
        }

        window.clear();
        player.move(dx, dy, deltaTime);
        player.update(deltaTime);

        size_t bulletsSize = bullets.size();
        for (int i = 0; i < bulletsSize; i++) 
        {
            bullets[i].update(deltaTime);
        }

        size_t enemiesSize = enemies.size();
        for (int i = 0; i < enemiesSize; i++) 
        {
            enemies[i].update(deltaTime, player);
        }

        for (int i = 0; i < bulletsSize; i++) 
        {
            sf::Vector2f bulletCoord = bullets[i].getCoord();
            float bulletRadius = bullets[i].getRadius(); 
            
            enemiesSize = enemies.size();
            for (int j = 0; j < enemiesSize; j++) 
            {

                sf::Vector2f enemyCoord = enemies[j].getCoord();
                float enemyRadius = enemies[j].getRadius();

                float distance = sqrt(std::pow(enemyCoord.x - bulletCoord.x, 2) + std::pow(enemyCoord.y - bulletCoord.y, 2));
                if (distance < (enemyRadius + bulletRadius / 2))
                {
                    enemies.erase(enemies.begin() + j);
                    break;
                }
            }
        }

        deltaTime = deltaClock.getElapsedTime().asSeconds();
        enemyTime += deltaTime;
        cdTime += deltaTime;
        deltaClock.restart();

        if (enemyTime > 0.35) 
        {
            enemyTime = 0;

            float angle = (rand() % 62) / 10;
            int range = 800;
            sf::Vector2f playerCoord = player.getCoord();

            en::Enemy newEnemy = en::Enemy(range * cos(angle) + player.coord.x, range * sin(angle) + player.coord.y);
            enemies.push_back(newEnemy);
        } 

        map.draw(window, player);
        for (int i = 0; i < bulletsSize; i++) 
        {
            bullets[i].draw(window, player.getCoord());
        }
        enemiesSize = enemies.size();
        for (int i = 0; i < enemiesSize; i++) 
        {
            enemies[i].draw(window, player);
        }
        player.draw(window);


        if (bulletsSize > 10) 
        {
            bullets.erase(bullets.begin());
        }

        window.display();
    }
    return 0;
}