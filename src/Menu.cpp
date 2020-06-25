#include "Menu.h"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>

using namespace sf;
void Menu::menu(RenderWindow &window, Music &jazz) {
  Font font;
  Clock clock;
  SoundBuffer buffer;
  buffer.loadFromFile("audio/Click.ogg");
  Sound sound;
  sound.setBuffer(buffer);
  font.loadFromFile("19183.ttf");
  Text text("Author: Shegross\n Version(0.1)", font);
  text.setCharacterSize(30);
  text.setStyle(sf::Text::Regular);
  text.setFillColor(Color::White);
  text.setPosition(1100, 680);
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
