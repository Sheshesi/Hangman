#include "Options.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <string>
#include <sstream>
using namespace sf;

int options::Option(RenderWindow& window, Music& jazz) {
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
}