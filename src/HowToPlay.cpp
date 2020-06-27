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
}
