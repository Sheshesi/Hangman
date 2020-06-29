#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;
using namespace std;
class mainLogic{
public:
    void logicFunction(RenderWindow& window,vector<Sprite> &sprt, vector<Texture> &txtr, vector<Sprite> &shadow, Music &jazz, string &the_word, string &path, int num, ifstream &themeFile, string str, vector<string> &words);
};