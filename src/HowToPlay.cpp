#include "HowToPlay.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
using namespace sf;

void howToButton::HowToPlay(RenderWindow& window)
{
    Texture backButton, backButtonShadow;
    backButton.loadFromFile("images/menu/Back.png");
    backButtonShadow.loadFromFile("images/menu/Back.png");
    backButtonShadow.setSmooth(true);
    backButton.setSmooth(true);
    Sprite buttonBack(backButton), buttonBackShadow(backButtonShadow);
    buttonBackShadow.setScale(0.6, 0.6);
    buttonBackShadow.setColor(Color(0, 0, 0, 64));
    buttonBackShadow.setPosition(560, 550);
    buttonBack.setScale(0.6, 0.6);
    bool isHowTo = true;
    Font font;
    font.loadFromFile("19183.ttf");
    Text text(" Welcome to Hangman!\n Your purpose: guess the word.\n You have six attempt's.\n How to enter the letters:\n Push on the buttons with letters at the main screen.\n", font, 50);
    while (isHowTo) {
        Event event;
        while (window.pollEvent(event)) {
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                isHowTo = false;
            }
        }
        window.clear(Color(168, 154, 98));
        buttonBack.setPosition(550, 540);
        if (IntRect(550, 540, 203, 105).contains(Mouse::getPosition(window))) {
            buttonBack.setPosition(560, 550);
            if (event.type == Event::MouseButtonReleased) {
                if (event.mouseButton.button == Mouse::Left) {
                    isHowTo = false;
                }
            }
        }
        window.draw(buttonBackShadow);
        window.draw(text);
        window.draw(buttonBack);
        window.display();
    }
}