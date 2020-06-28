#include "HowToPlay.h"
#include "Menu.h"
#include "Options.h"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include "logic.hpp"
#include <vector>
#include <string>

using namespace sf;
void Menu::menu(RenderWindow &window, Music &jazz) {
  Font font;
  Clock clock;
  SoundBuffer buffer;
  howToButton howTo;
  options optionButton;
  buffer.loadFromFile("audio/Click.ogg");
  Sound sound;
  sound.setBuffer(buffer);
  font.loadFromFile("19183.ttf");
  Text text();
  Texture newGame, howToPlay, Quit, aboutMenu, titleTexture, hangTexture,
      manTexture, shadowTexture, options;
  manTexture.loadFromFile("images/hang/man.png");
  shadowTexture.loadFromFile("images/menu/Shadow.png");
  newGame.loadFromFile("images/menu/NewGame.png");
  howToPlay.loadFromFile("images/menu/HowToPlay.png");
  Quit.loadFromFile("images/menu/Quit.png");
  titleTexture.loadFromFile("images/TITLE.png");
  hangTexture.loadFromFile("images/menu/Hang.png");
  options.loadFromFile("images/menu/Options.png");
  options.setSmooth(true);
  hangTexture.setSmooth(true);
  newGame.setSmooth(true);
  howToPlay.setSmooth(true);
  Quit.setSmooth(true);
  manTexture.setSmooth(true);
  shadowTexture.setSmooth(true);
  Sprite ButtonNG(newGame), ButtonHTP(howToPlay), ButtonQ(Quit),
      ButtonO(options), TitleSprite(titleTexture), HangSprite(hangTexture),
      ManSprite(manTexture), ShadowSprite(shadowTexture);
  Sprite shadowButtonNG(newGame), shadowButtonHTP(howToPlay),
      shadowButtonQ(Quit), shadowButtonO(options);
  bool isMenu = true;
  int menuNum = 0;
  ButtonNG.setScale(0.6, 0.6);
  ButtonHTP.setScale(0.6, 0.6);
  ButtonQ.setScale(0.6, 0.6);
  ButtonO.setScale(0.6, 0.6);
  shadowButtonNG.setPosition(110, 260);
  shadowButtonHTP.setPosition(1060, 405);
  shadowButtonQ.setPosition(110, 405);
  shadowButtonO.setPosition(1060, 260);
  shadowButtonNG.setScale(0.6, 0.6);
  shadowButtonHTP.setScale(0.6, 0.6);
  shadowButtonQ.setScale(0.6, 0.6);
  shadowButtonO.setScale(0.6, 0.6);
  shadowButtonNG.setColor(Color(0, 0, 0, 64));
  shadowButtonHTP.setColor(Color(0, 0, 0, 64));
  shadowButtonQ.setColor(Color(0, 0, 0, 64));
  shadowButtonO.setColor(Color(0, 0, 0, 64));
  TitleSprite.setPosition(450, 70);
  HangSprite.setPosition(400, 200);
  HangSprite.setScale(0.8, 0.8);
  ManSprite.setScale(0.8, 0.8);
  while (isMenu) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (Keyboard::isKeyPressed(Keyboard::Tab)) {
        window.close();
      }
    }
    ButtonNG.setColor(Color::White);
    ButtonHTP.setColor(Color::White);
    ButtonQ.setColor(Color::White);
    ButtonO.setColor(Color::White);
    ButtonNG.setPosition(100, 250);
    ButtonHTP.setPosition(1050, 395);
    ButtonQ.setPosition(100, 395);
    ButtonO.setPosition(1050, 250);
    ManSprite.setPosition(687, 278);
    ShadowSprite.setPosition(575, 620);
    menuNum = 0;
    window.clear(Color(168, 154, 98));
    if (IntRect(100, 250, 203, 105).contains(Mouse::getPosition(window))) {
      ButtonNG.setColor(Color(160, 160, 160));
      ButtonNG.setPosition(110, 260);
      menuNum = 1;
    }
    if (IntRect(1050, 395, 203, 105).contains(Mouse::getPosition(window))) {
      ButtonHTP.setColor(Color(204, 204, 204));
      ButtonHTP.setPosition(1060, 405);
      menuNum = 2;
    }
    if (IntRect(100, 395, 203, 105).contains(Mouse::getPosition(window))) {
      ButtonQ.setColor(Color(214, 214, 214));
      ButtonQ.setPosition(110, 405);
      menuNum = 3;
    }
    if (IntRect(1050, 250, 203, 105).contains(Mouse::getPosition(window))) {
      ButtonO.setColor(Color(214, 214, 214));
      ButtonO.setPosition(1060, 260);
      menuNum = 4;
    }
    if (IntRect(687, 278, 70, 120).contains(Mouse::getPosition(window))) {
      if (event.type == Event::MouseButtonPressed) {
        if (event.mouseButton.button == Mouse::Left) {
          ManSprite.setPosition(687, 283);
          ShadowSprite.setPosition(580, 616);
        }
      }
    }
    if (event.type == Event::MouseButtonReleased) {
      if (event.mouseButton.button == Mouse::Left) {
        if (menuNum == 1) {
          sound.play();
          isMenu = false;
        }
        if (menuNum == 2) {
          sound.play();
          howTo.HowToPlay(window);
        }
        if (menuNum == 3) {
          sound.play();
          isMenu = false;
          window.close();
          exit(0);
        }
        if (menuNum == 4) {
          sound.play();
          optionButton.Option(window, jazz);
        }
      }
    }
    window.draw(HangSprite);
    window.draw(ShadowSprite);
    window.draw(TitleSprite);
    window.draw(shadowButtonNG);
    window.draw(shadowButtonHTP);
    window.draw(shadowButtonQ);
    window.draw(shadowButtonO);
    window.draw(ButtonNG);
    window.draw(ButtonHTP);
    window.draw(ButtonQ);
    window.draw(ButtonO);
    window.draw(ManSprite);
    window.display();
  }
}
