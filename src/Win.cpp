#include "Win.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
using namespace sf;
using namespace std;
bool winWindow::Win(RenderWindow& window)
{
    Image wind, yes, no;
    wind.loadFromFile("images/Win/1x/window.png");
    yes.loadFromFile("images/Win/1x/yes.png");
    no.loadFromFile("images/Win/1x/no.png");
    Texture Wind, Yes, No;
    Wind.loadFromImage(wind);
    Yes.loadFromImage(yes);
    No.loadFromImage(no);
    Sprite WIND, YES, NO;
    WIND.setTexture(Wind);
    YES.setTexture(Yes);
    NO.setTexture(No);
    WIND.setPosition(450, 240);
    bool isWin = true;
    while (isWin) {
        YES.setColor(Color::White);
        NO.setColor(Color::White);
        YES.setPosition(500, 360);
        NO.setPosition(690, 360);
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        if (IntRect(500, 360, 150, 50).contains(Mouse::getPosition(window))) {
            YES.setColor(Color(200, 200, 200));
            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    isWin = false;
                    return true;
                }
            }
        }
        if (IntRect(690, 360, 150, 50).contains(Mouse::getPosition(window))) {
            NO.setColor(Color(200, 200, 200));
            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                    isWin = false;
                    return false;
                }
            }
        }
        window.clear(Color(168, 154, 98));
        window.draw(WIND);
        window.draw(YES);
        window.draw(NO);
        window.display();
    }
    return true;
}