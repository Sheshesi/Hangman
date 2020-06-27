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
}