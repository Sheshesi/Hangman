#include "Menu.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "logic.hpp"
#include "logo.hpp"
#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace sf;
using namespace std;
const int MAX_SIZE = 26; // Максимальное количество букв латинского алфавита
const int MAX_WORDS = 20; // Максимальное количество слов в текстовых файлах

int main() {
  RenderWindow window(VideoMode(1366, 768), "Hangman");
  srand((unsigned)time(NULL));
  Font font;
  Logo logo;
  Music jazz;
  Sound sound;
  Sound clap;
  Menu menuShow;
  SoundBuffer buffer, buffer2;
  string path, str, the_word;
  ifstream themeFile;
  vector<string> words;
  vector<Sprite> shadow(MAX_SIZE, Sprite());
  vector<Sprite> sprt(MAX_SIZE, Sprite());
  vector<Texture> txtr(MAX_SIZE, Texture());
  int num = 0;
  jazz.openFromFile("audio/Jazz.ogg");
  logo.ShowLogo(window);
  jazz.play();
  jazz.setLoop(true);
  menuShow.menu(window, sprt, txtr, shadow, jazz, the_word, path, num,
                themeFile, str, words);
  return 0;
}
