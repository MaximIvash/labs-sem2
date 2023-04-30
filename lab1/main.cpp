#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <ctime>
using namespace std;


class AnimatedText {
private:
    std::string text;
    size_t duration;
public:
    AnimatedText(const string& newText, const int& newDuration)
    {
        text = newText;
        duration = newDuration;
    }
    string getText(int currTime)
    {
        int time = currTime % (duration + 1);
        string tempText = text.substr(0, text.length() * time / duration);
        return tempText;
    }
};

int main() {
    AnimatedText ani = AnimatedText("Hello, it's me !", 3);
    sf::RenderWindow window(sf::VideoMode(400, 200), "SFML works!");

    sf::Text text;
    sf::Font font;
    font.loadFromFile("Halogen_0.ttf");
    text.setFont(font);
    text.setCharacterSize(55);
    text.setColor(sf::Color::Red);


    float currTime;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        currTime = std::clock();
        text.setPosition(0, 0);
        text.setString(ani.getText(currTime / 1000 + 1));

        window.clear();
        window.draw(text);
        window.display();
    }

    return 0;
}