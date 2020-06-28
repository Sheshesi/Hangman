#include "Options.h"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include <sstream>
#include <string>
using namespace sf;

int options::Option(RenderWindow &window, Music &jazz) {
  ContextSettings settings;
  settings.antialiasingLevel = 10;
  CircleShape triangle(10.f, 3);
  CircleShape reverseTriangle(10.f, 3);
  reverseTriangle.setRotation(180);
  reverseTriangle.setPosition(735, 370);
  triangle.setPosition(715, 295);
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
  bool isOption = true;
  int volume = 100;
  Font font;
  font.loadFromFile("19183.ttf");
  Text text("", font, 50);
  Text aboutVolume("Volume", font, 50);
  SoundBuffer buffer;
  buffer.loadFromFile("Audio/Click.ogg");
  Sound click;
  click.setBuffer(buffer);
  aboutVolume.setFillColor(Color::Black);
  aboutVolume.setPosition(550, 300);
  text.setFillColor(Color::Black);
  text.setPosition(700, 300);
  Clock clock;
  while (isOption) {
    Event event;
    while (window.pollEvent(event)) {
      if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        isOption = false;
      }
    }
    window.draw(buttonBackShadow);
    window.draw(reverseTriangle);
    window.draw(triangle);
    window.draw(text);
    window.draw(aboutVolume);
    window.draw(buttonBack);
    window.display();
  }
}