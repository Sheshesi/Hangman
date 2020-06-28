#pragma once
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include <vector>

using namespace std;
using namespace sf;

class Menu {
public:
  void menu(RenderWindow &window, vector<Sprite> &sprt, vector<Texture> &txtr, vector<Sprite> &shadow, Music &jazz, const string &THE_WORD);
};