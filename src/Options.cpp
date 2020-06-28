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
  buffer.loadFromFile("audio/Click.ogg");
  Sound click;
  click.setBuffer(buffer);
  aboutVolume.setFillColor(Color::Black);
  aboutVolume.setPosition(550, 300);
  std::ostringstream setVolume;
  text.setFillColor(Color::Black);
  text.setPosition(700, 300);
  setVolume << volume;
  Clock clock;
  int volumePath;
  while (isOption) {
    Event event;
    while (window.pollEvent(event)) {
      if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        isOption = false;
      }
    }
    Text text("", font, 50);
    std::ostringstream setVolume;
    setVolume << volume;
    triangle.setFillColor(Color::Red);
    reverseTriangle.setFillColor(Color::Red);
    text.setString(setVolume.str());
    text.setFillColor(Color::Black);
    text.setPosition(700, 300);
    jazz.setVolume(volume);
    window.clear(Color(168, 154, 98));
    buttonBack.setPosition(550, 540);
    volumePath = 0;
    if (IntRect(550, 540, 203, 105).contains(Mouse::getPosition(window))) {
      buttonBack.setPosition(560, 550);
      if (event.type == Event::MouseButtonReleased) {
        if (event.mouseButton.button == Mouse::Left) {
          click.play();
          isOption = false;
        }
      }
    }
    if (IntRect(715, 295, 20, 20).contains(Mouse::getPosition(window))) {
      triangle.setFillColor(Color(150, 0, 0));
      volumePath = 1;
    }
    if (IntRect(715, 350, 20, 20).contains(Mouse::getPosition(window))) {
      reverseTriangle.setFillColor(Color(150, 0, 0));
      volumePath = 2;
    }
    if (event.type == Event::MouseButtonReleased) {
      if (event.mouseButton.button == Mouse::Left) {
        if (clock.getElapsedTime().asMilliseconds() > 50) {
          if (volumePath == 1) {
            click.play();
            if (volume >= 100) {
            } else {
              volume += 10;
            }
          }
          if (volumePath == 2) {
            click.play();
            if (volume > 0) {
              volume = volume - 10;
            }
          }
        }
        clock.restart();
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
  return volume;
}