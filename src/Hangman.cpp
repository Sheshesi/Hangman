#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "logo.h"
#include "Menu.h"
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(1366, 768), "Hangman", Style::Fullscreen);
    Font font;
    Logo logo;
    Music jazz;
	Sound sound;
	Sound clap;
    Menu menuShow;
	SoundBuffer buffer, buffer2;
    logo.ShowLogo(window);
    menuShow.menu(window,jazz);
    return 0;
}