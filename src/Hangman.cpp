#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "logo.h"
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(1366, 768), "Hangman", Style::Fullscreen);
    Logo logo;
    logo.ShowLogo(window);
    return 0;
}