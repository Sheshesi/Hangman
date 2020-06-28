#include "Menu.h"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "logo.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <string>
using namespace sf;
using namespace std;
const int MAX_SIZE = 26;

struct themesChoise{
  string themeOne = "Character";
  string themeTwo = "Sport";
  string themeThree = "Plants";
  string themeFour = "Economy";
  string themeFive = "Instruments";
  string themeSix = "Transport";
  string themeSeven = "Profession";
  string themeEight = "Locations";
  string themeNine = "Animals";
}themeNumber;

string choiseTheTheme(int themes, string* path) {
	themes = rand() % 9 + 1;
	if (themes == 1)
	{
		*path = themeNumber.themeOne;
	}
	if (themes == 2)
	{
		*path = themeNumber.themeTwo;
	}
	if (themes == 3)
	{
		*path = themeNumber.themeThree;
	}
	if (themes == 4)
	{
		*path = themeNumber.themeFour;
	}
	if (themes == 5)
	{
		*path = themeNumber.themeFive;
	}
	if (themes == 6)
	{
		*path = themeNumber.themeSix;
	}
	if (themes == 7)
	{
		*path = themeNumber.themeSeven;
	}
	if (themes == 8)
	{
		*path = themeNumber.themeEight;
	}
	if (themes == 9)
	{
		*path = themeNumber.themeNine;
	}
	return *path;
}

void loadFromFile(vector<Sprite> &sprt, vector<Image> &img, vector<Texture> &txtr, vector<Sprite> &shadow) {
	vector<string> symbol;
	char letter = 'A';
	int x = 600;
	int y = 100;
	string word[26];
	string way = "images/alphabet/";
	for (int i = 0; i < MAX_SIZE; i++) {
		word[i] = letter;
		letter++;
		symbol.push_back(way + word[i] + ".png");
	}
	for (int i = 0; i < MAX_SIZE; i++) {
		img[i].loadFromFile(symbol[i]);
		txtr[i].loadFromImage(img[i]);
		txtr[i].setSmooth(true);
		sprt[i].setTexture(txtr[i]);
		shadow[i].setTexture(txtr[i]);
		sprt[i].setScale(0.8, 0.8);
		shadow[i].setScale(0.8, 0.8);
		shadow[i].setColor(Color(0, 0, 0, 64));
	}
}

int main() {
  RenderWindow window(VideoMode(1366, 768), "Hangman");
  Font font;
  Logo logo;
  Music jazz;
  Sound sound;
  Sound clap;
  Menu menuShow;
  SoundBuffer buffer, buffer2;
  jazz.openFromFile("audio/Jazz.ogg");
  logo.ShowLogo(window);
  jazz.play();
  jazz.setLoop(true);
  menuShow.menu(window, jazz);
  return 0;
}