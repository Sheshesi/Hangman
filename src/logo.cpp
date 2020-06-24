#include "logo.h"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
using namespace sf;
void Logo::ShowLogo(RenderWindow& window)
{
    bool isShowLogo = true;
    Event event;
    while (isShowLogo) {
        while (window.pollEvent(event)) {
            if (Keyboard::isKeyPressed(Keyboard::Escape)
                || Keyboard::isKeyPressed(Keyboard::Space)) {
                isShowLogo = false;
            }
        }
    }
}