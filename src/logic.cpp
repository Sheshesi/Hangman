#include "Menu.hpp"
#include "logic.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
using namespace sf;
using namespace std;
const int MAX_SIZE = 26; // Максимальное количество букв латинского алфавита
const int MAX_WRONG = 6; //Максимальное количество допустимых ошибок

struct themesChoise {
  string themeOne = "Character";
  string themeTwo = "Sport";
  string themeThree = "Plants";
  string themeFour = "Economy";
  string themeFive = "Instruments";
  string themeSix = "Transport";
  string themeSeven = "Profession";
  string themeEight = "Locations";
  string themeNine = "Animals";
} themeNumber;

string choiseTheTheme(int num, string *path) {
  num = rand() % 9 + 1;
  if (num == 1) {
    *path = themeNumber.themeOne;
  }
  if (num == 2) {
    *path = themeNumber.themeTwo;
  }
  if (num == 3) {
    *path = themeNumber.themeThree;
  }
  if (num == 4) {
    *path = themeNumber.themeFour;
  }
  if (num == 5) {
    *path = themeNumber.themeFive;
  }
  if (num == 6) {
    *path = themeNumber.themeSix;
  }
  if (num == 7) {
    *path = themeNumber.themeSeven;
  }
  if (num == 8) {
    *path = themeNumber.themeEight;
  }
  if (num == 9) {
    *path = themeNumber.themeNine;
  }
  return *path;
}

void loadFromFile(vector<Sprite> &sprt, vector<Texture> &txtr,
                  vector<Sprite> &shadow) {
  vector<string> symbol;
  char letter = 'A';
  string word[26];
  string way = "images/alphabet/";
  for (unsigned int i = 0; i < MAX_SIZE; i++) {
    word[i] = letter;
    letter++;
    symbol.push_back(way + word[i] + ".png");
  }
  for (unsigned int i = 0; i < MAX_SIZE; i++) {
    txtr[i].loadFromFile(symbol[i]);
    txtr[i].setSmooth(true);
    sprt[i].setTexture(txtr[i]);
    shadow[i].setTexture(txtr[i]);
    sprt[i].setScale(0.8, 0.8);
    sprt[i].setColor(Color::White);
    shadow[i].setScale(0.8, 0.8);
    shadow[i].setColor(Color(0, 0, 0, 64));
  }
}

void choiseTheWord(ifstream &themeFile, string str, vector<string> &words) {
  int i = 0;
  if (!themeFile.is_open()) {
    exit(0);
  } else {
    while (!themeFile.eof()) {
      str = "";
      getline(themeFile, str);
      words.push_back(str);
      i++;
    }
  }
}

void matchLetter(string &the_word, char &letter, string &used, int &pos,
                 int &wrong, Clock &clock) {
  if (the_word.find(letter) != string::npos) {
    for (unsigned int i = 0; i < the_word.size(); i++) {
      if (the_word[i] == letter) {
        used[i] = the_word[pos];
      }
    }
  } else {
    wrong++;
  }
  clock.restart();
}

void mainLogic::logicFunction(RenderWindow &window, vector<Sprite> &sprt,
                              vector<Texture> &txtr, vector<Sprite> &shadow,
                              Music &jazz, string &the_word, string &path,
                              int num, ifstream &themeFile, string str,
                              vector<string> &words) {
  Texture hangPart_1, hangPart_2, hangPart_3, hangPart_4, rope, man,
      backgroundTexture;
  Sprite hangPartSprite_1, hangPartSprite_2, hangPartSprite_3, hangPartSprite_4,
      ropeSprite, manSprite, backgroundSprite;
  Clock clock;
  Menu menuShow;
  Sound sound, clap;
  SoundBuffer buffer, buffer_2;
  Font font;
  srand((unsigned)time(NULL));
  int i = rand() % 20;
  choiseTheTheme(num, &path);
  themeFile.open(path);
  choiseTheWord(themeFile, str, words);
  the_word = words[i];
  loadFromFile(sprt, txtr, shadow);
  buffer_2.loadFromFile("audio/Clap.ogg");
  buffer.loadFromFile("audio/Click.ogg");
  clap.setBuffer(buffer_2);
  sound.setBuffer(buffer);
  font.loadFromFile("19183.ttf");
  hangPart_1.loadFromFile("images/hang/1 board.png");
  hangPart_2.loadFromFile("images/hang/2 board.png");
  hangPart_3.loadFromFile("images/hang/3 board.png");
  hangPart_4.loadFromFile("images/hang/4 board.png");
  rope.loadFromFile("images/hang/rope.png");
  man.loadFromFile("images/hang/man.png");
  backgroundTexture.loadFromFile("images/background.png");
  hangPart_1.setSmooth(true);
  hangPart_2.setSmooth(true);
  hangPart_3.setSmooth(true);
  hangPart_4.setSmooth(true);
  man.setSmooth(true);
  rope.setSmooth(true);
  hangPartSprite_1.setTexture(hangPart_1);
  hangPartSprite_2.setTexture(hangPart_2);
  hangPartSprite_3.setTexture(hangPart_3);
  hangPartSprite_4.setTexture(hangPart_4);
  ropeSprite.setTexture(rope);
  manSprite.setTexture(man);
  backgroundSprite.setTexture(backgroundTexture);
  hangPartSprite_1.setPosition(97, 180);
  hangPartSprite_2.setPosition(70, 180);
  hangPartSprite_3.setPosition(70, 385);
  hangPartSprite_4.setPosition(70, 510);
  ropeSprite.setPosition(287, 170);
  manSprite.setPosition(282, 245);
  ropeSprite.setScale(0.8, 0.8);
  manSprite.setScale(0.8, 0.8);
  hangPartSprite_1.setScale(0.8, 0.8);
  hangPartSprite_2.setScale(0.8, 0.8);
  hangPartSprite_3.setScale(0.8, 0.8);
  hangPartSprite_4.setScale(0.8, 0.8);
  backgroundSprite.setScale(0.9, 0.9);
  string used(the_word.size(), '-');
  Text wordToDisplay(used, font, 144);
  string themeToDisplay = "Theme: " + path;
  Text theme(themeToDisplay, font, 25);
  theme.setPosition(75, 680);
  theme.setFillColor(Color::Black);
  wordToDisplay.setPosition(70, 520);
  wordToDisplay.setFillColor(Color::Blue);
  float x = 600;
  float y = 100;
  int wrong = 0;
  bool isLogic = true;
  bool draw_1 = false, draw_2 = false, draw_3 = false, draw_4 = false,
       draw_5 = false, draw_6 = false;
  while (isLogic) {
    window.clear(Color::Black);
    window.draw(backgroundSprite);
    char letter = ' ';
    sf::Event event;
    while (window.pollEvent(event)) {
      if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        menuShow.menu(window, sprt, txtr, shadow, jazz, the_word, path, num,
                      themeFile, str, words);
      }
      if (event.type == sf::Event::Closed) {
        isLogic = false;
        window.close();
      }
    }
    x = 600;
    for (int i = 0; i < 7; i++) { //Выстраивание первого ряда букв
      sprt[i].setPosition(x, y);
      shadow[i].setPosition(x + 10, y + 10);
      x += 100;
    }
    x = 600;
    for (int i = 7; i < 14; i++) { //Выстраивание второго ряда букв
      sprt[i].setPosition(x, y + 100);
      shadow[i].setPosition(x + 10, y + 110);
      x += 100;
    }
    x = 600;
    for (int i = 14; i < 21; i++) //Выстраивание третьего ряда букв
    {
      sprt[i].setPosition(x, y + 200);
      shadow[i].setPosition(x + 10, y + 210);
      x += 100;
    }
    x = 700;
    for (int i = 21; i < 26; i++) { //Выстраивание четвертого ряда букв
      sprt[i].setPosition(x, y + 300);
      shadow[i].setPosition(x + 10, y + 310);
      x += 100;
    }
    if (IntRect(600, 100, 50, 70).contains(Mouse::getPosition(window))) {
      sprt[0].setPosition(610, 110);
      letter = 'a';
    }
    if (IntRect(700, 100, 50, 70).contains(Mouse::getPosition(window))) {
      sprt[1].setPosition(710, 110);
      letter = 'b';
    }
    if (IntRect(800, 100, 50, 70).contains(Mouse::getPosition(window))) {
      sprt[2].setPosition(810, 110);
      letter = 'c';
    }
    if (IntRect(900, 100, 50, 70).contains(Mouse::getPosition(window))) {
      sprt[3].setPosition(910, 110);
      letter = 'd';
    }
    if (IntRect(1000, 100, 50, 70).contains(Mouse::getPosition(window))) {
      sprt[4].setPosition(1010, 110);
      letter = 'e';
    }
    if (IntRect(1100, 100, 50, 70).contains(Mouse::getPosition(window))) {
      sprt[5].setPosition(1110, 110);
      letter = 'f';
    }
    if (IntRect(1200, 100, 50, 70).contains(Mouse::getPosition(window))) {
      sprt[6].setPosition(1210, 110);
      letter = 'g';
    }
    if (IntRect(600, 200, 50, 70).contains(Mouse::getPosition(window))) {
      sprt[7].setPosition(610, 210);
      letter = 'h';
    }
    if (IntRect(700, 200, 50, 70).contains(Mouse::getPosition(window))) {
      sprt[8].setPosition(710, 210);
      letter = 'i';
    }
    if (IntRect(800, 200, 50, 70).contains(Mouse::getPosition(window))) {
      sprt[9].setPosition(810, 210);
      letter = 'j';
    }
    if (IntRect(900, 200, 50, 70).contains(Mouse::getPosition(window))) {
      sprt[10].setPosition(910, 210);
      letter = 'k';
    }
    if (IntRect(1000, 200, 50, 70).contains(Mouse::getPosition(window))) {
      sprt[11].setPosition(1010, 210);
      letter = 'l';
    }
    if (IntRect(1100, 200, 50, 70).contains(Mouse::getPosition(window))) {
      sprt[12].setPosition(1110, 210);
      letter = 'm';
    }
    if (IntRect(1200, 200, 50, 70).contains(Mouse::getPosition(window))) {
      sprt[13].setPosition(1210, 210);
      letter = 'n';
    }
    if (IntRect(600, 300, 50, 70).contains(Mouse::getPosition(window))) {
      sprt[14].setPosition(610, 310);
      letter = 'o';
    }
    if (IntRect(700, 300, 50, 70).contains(Mouse::getPosition(window))) {
      sprt[15].setPosition(710, 310);
      letter = 'p';
    }
    if (IntRect(800, 300, 50, 70).contains(Mouse::getPosition(window))) {
      sprt[16].setPosition(810, 310);
      letter = 'q';
    }
    if (IntRect(900, 300, 50, 70).contains(Mouse::getPosition(window))) {
      sprt[17].setPosition(910, 310);
      letter = 'r';
    }
    if (IntRect(1000, 300, 50, 70).contains(Mouse::getPosition(window))) {
      sprt[18].setPosition(1010, 310);
      letter = 's';
    }
    if (IntRect(1100, 300, 50, 70).contains(Mouse::getPosition(window))) {
      sprt[19].setPosition(1110, 310);
      letter = 't';
    }
    if (IntRect(1200, 300, 50, 70).contains(Mouse::getPosition(window))) {
      sprt[20].setPosition(1210, 310);
      letter = 'u';
    }
    if (IntRect(700, 400, 50, 70).contains(Mouse::getPosition(window))) {
      sprt[21].setPosition(710, 410);
      letter = 'v';
    }
    if (IntRect(800, 400, 50, 70).contains(Mouse::getPosition(window))) {
      sprt[22].setPosition(810, 410);
      letter = 'w';
    }
    if (IntRect(900, 400, 50, 70).contains(Mouse::getPosition(window))) {
      sprt[23].setPosition(910, 410);
      letter = 'x';
    }
    if (IntRect(1000, 400, 50, 70).contains(Mouse::getPosition(window))) {
      sprt[24].setPosition(1010, 410);
      letter = 'y';
    }
    if (IntRect(1100, 400, 50, 70).contains(Mouse::getPosition(window))) {
      sprt[25].setPosition(1110, 410);
      letter = 'z';
    }
    int pos = the_word.find(letter);
    if (event.type == Event::MouseButtonReleased) {
      if (event.mouseButton.button == Mouse::Left) {
        if (clock.getElapsedTime().asMilliseconds() > 200) {
          if (letter == 'a') {
            sound.play();
            sprt[0].setColor(Color::Red);
            matchLetter(the_word, letter, used, pos, wrong, clock);
          }
          if (letter == 'b') {
            sound.play();
            sprt[1].setColor(Color::Red);
            matchLetter(the_word, letter, used, pos, wrong, clock);
          }
          if (letter == 'c') {
            sound.play();
            sprt[2].setColor(Color::Red);
            matchLetter(the_word, letter, used, pos, wrong, clock);
          }
          if (letter == 'd') {
            sound.play();
            sprt[3].setColor(Color::Red);
            matchLetter(the_word, letter, used, pos, wrong, clock);
          }
          if (letter == 'e') {
            sound.play();
            sprt[4].setColor(Color::Red);
            matchLetter(the_word, letter, used, pos, wrong, clock);
          }
          if (letter == 'f') {
            sound.play();
            sprt[5].setColor(Color::Red);
            matchLetter(the_word, letter, used, pos, wrong, clock);
          }
          if (letter == 'g') {
            sound.play();
            sprt[6].setColor(Color::Red);
            matchLetter(the_word, letter, used, pos, wrong, clock);
          }
          if (letter == 'h') {
            sound.play();
            sprt[7].setColor(Color::Red);
            matchLetter(the_word, letter, used, pos, wrong, clock);
          }
          if (letter == 'i') {
            sound.play();
            sprt[8].setColor(Color::Red);
            matchLetter(the_word, letter, used, pos, wrong, clock);
          }
          if (letter == 'j') {
            sound.play();
            sprt[9].setColor(Color::Red);
            matchLetter(the_word, letter, used, pos, wrong, clock);
          }
          if (letter == 'k') {
            sound.play();
            sprt[10].setColor(Color::Red);
            matchLetter(the_word, letter, used, pos, wrong, clock);
          }
          if (letter == 'l') {
            sound.play();
            sprt[11].setColor(Color::Red);
            matchLetter(the_word, letter, used, pos, wrong, clock);
          }
          if (letter == 'm') {
            sound.play();
            sprt[12].setColor(Color::Red);
            matchLetter(the_word, letter, used, pos, wrong, clock);
          }
          if (letter == 'n') {
            sound.play();
            sprt[13].setColor(Color::Red);
            matchLetter(the_word, letter, used, pos, wrong, clock);
          }
          if (letter == 'o') {
            sound.play();
            sprt[14].setColor(Color::Red);
            matchLetter(the_word, letter, used, pos, wrong, clock);
          }
          if (letter == 'p') {
            sound.play();
            sprt[15].setColor(Color::Red);
            matchLetter(the_word, letter, used, pos, wrong, clock);
          }
          if (letter == 'q') {
            sound.play();
            sprt[16].setColor(Color::Red);
            matchLetter(the_word, letter, used, pos, wrong, clock);
          }
          if (letter == 'r') {
            sound.play();
            sprt[17].setColor(Color::Red);
            matchLetter(the_word, letter, used, pos, wrong, clock);
          }
          if (letter == 's') {
            sound.play();
            sprt[18].setColor(Color::Red);
            matchLetter(the_word, letter, used, pos, wrong, clock);
          }
          if (letter == 't') {
            sound.play();
            sprt[19].setColor(Color::Red);
            matchLetter(the_word, letter, used, pos, wrong, clock);
          }
          if (letter == 'u') {
            sound.play();
            sprt[20].setColor(Color::Red);
            matchLetter(the_word, letter, used, pos, wrong, clock);
          }
          if (letter == 'v') {
            sound.play();
            sprt[21].setColor(Color::Red);
            matchLetter(the_word, letter, used, pos, wrong, clock);
          }
          if (letter == 'w') {
            sound.play();
            sprt[22].setColor(Color::Red);
            matchLetter(the_word, letter, used, pos, wrong, clock);
          }
          if (letter == 'x') {
            sound.play();
            sprt[23].setColor(Color::Red);
            matchLetter(the_word, letter, used, pos, wrong, clock);
          }
          if (letter == 'y') {
            sound.play();
            sprt[24].setColor(Color::Red);
            matchLetter(the_word, letter, used, pos, wrong, clock);
          }
          if (letter == 'z') {
            sound.play();
            sprt[25].setColor(Color::Red);
            matchLetter(the_word, letter, used, pos, wrong, clock);
          }
        }
        clock.restart();
      }
    }
    wordToDisplay.setString(used);
    if (wrong > MAX_WRONG) {
      isLogic = false;
      menuShow.menu(window, sprt, txtr, shadow, jazz, the_word, path, num,
                    themeFile, str, words);
      window.close();
    }
    for (int i = 0; i < MAX_SIZE; i++) {
      window.draw(shadow[i]);
    }
    for (int i = 0; i < MAX_SIZE; i++) {
      window.draw(sprt[i]);
    }
    if (wrong == 1) {
      draw_1 = true;
    }
    if (wrong == 2) {
      draw_2 = true;
    }
    if (wrong == 3) {
      draw_3 = true;
    }
    if (wrong == 4) {
      draw_4 = true;
    }
    if (wrong == 5) {
      draw_5 = true;
    }
    if (wrong == 6) {
      draw_6 = true;
    }
    if (draw_5) {
      window.draw(ropeSprite);
    }
    if (draw_6) {
      window.draw(manSprite);
    }
    if (draw_3) {
      window.draw(hangPartSprite_3);
    }
    if (draw_2) {
      window.draw(hangPartSprite_2);
    }
    if (draw_4) {
      window.draw(hangPartSprite_1);
    }
    if (draw_1) {
      window.draw(hangPartSprite_4);
    }
    window.draw(theme);
    window.draw(wordToDisplay);
    window.display();
  }
}
