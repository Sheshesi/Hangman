#include "Menu.h"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "logo.h"
using namespace sf;
int main() {
  RenderWindow window(VideoMode(1366, 768), "Hangman");
  Font font;
  Logo logo;
  Music jazz;
  Sound sound;
  Sound clap;
  Menu menuShow;
  SoundBuffer buffer, buffer2;
  jazz.openFromFile("audio/Jazz.ogg");
  logo.ShowLogo(window);
  jazz.play();
  jazz.setLoop(true);
  menuShow.menu(window, jazz);
  return 0;
}