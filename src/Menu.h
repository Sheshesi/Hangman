#pragma once
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include <vector>

using namespace std;
using namespace sf;

class Menu {
public:
  void menu(RenderWindow& window,vector<Sprite> &sprt, vector<Texture> &txtr, vector<Sprite> &shadow, Music &jazz, string &the_word, string &path, int num, ifstream &themeFile, string str, vector<string> &words);
};