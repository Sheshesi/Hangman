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
  Texture newGame, howToPlay, Quit, aboutMenu, titleTexture, hangTexture,
      manTexture, shadowTexture, options;
  manTexture.loadFromFile("images/hang/man.png");
  shadowTexture.loadFromFile("images/menu/Shadow.png");
  newGame.loadFromFile("images/menu/NewGame.png");
  howToPlay.loadFromFile("images/menu/HowToPlay.png");
  Quit.loadFromFile("images/menu/Quit.png");
  titleTexture.loadFromFile("images/Title.png");
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
      if (Keyboard::isKeyPressed(Keyboard::Space)) {
        window.close();
      }
    }
    window.clear(Color(168, 154, 98));
    window.display();
  }
}
