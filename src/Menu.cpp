#include "Menu.h"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>

using namespace sf;
void Menu::menu(RenderWindow &window, Music &jazz) {
  SoundBuffer buffer;
  buffer.loadFromFile("audio/Click.ogg");
  Sound sound;
  sound.setBuffer(buffer);
  bool isMenu = true;
  while (isMenu) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (Keyboard::isKeyPressed(Keyboard::Space)) {
        window.close();
      }
    }
    window.clear(Color(168, 154, 98));
    window.display();
  }
}
