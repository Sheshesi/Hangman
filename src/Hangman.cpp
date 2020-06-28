#include "Menu.h"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "logo.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <string>
#include "logic.hpp"
#include <iostream>
using namespace sf;
using namespace std;
const int MAX_SIZE = 26; // Максимальное количество букв латинского алфавита
const int MAX_WORDS = 20; // Максимальное количество слов в текстовых файлах

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

string choiseTheTheme(int num, string* path) {
	num = rand() % 9 + 1;
	if (num == 1)
	{
		*path = themeNumber.themeOne;
	}
	if (num == 2)
	{
		*path = themeNumber.themeTwo;
	}
	if (num == 3)
	{
		*path = themeNumber.themeThree;
	}
	if (num == 4)
	{
		*path = themeNumber.themeFour;
	}
	if (num == 5)
	{
		*path = themeNumber.themeFive;
	}
	if (num == 6)
	{
		*path = themeNumber.themeSix;
	}
	if (num == 7)
	{
		*path = themeNumber.themeSeven;
	}
	if (num == 8)
	{
		*path = themeNumber.themeEight;
	}
	if (num == 9)
	{
		*path = themeNumber.themeNine;
	}
	return *path;
}

void loadFromFile(vector<Sprite> &sprt, vector<Texture> &txtr, vector<Sprite> &shadow) {
	cout << "Hui" << endl;
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
		shadow[i].setScale(0.8, 0.8);
		shadow[i].setColor(Color(0, 0, 0, 64));
	}
}

void choiseTheWord(ifstream &themeFile, string str, vector<string> &words){
  int i = 0;
  if (!themeFile.is_open())
	{
		exit(0);
	}
	else
	{
		while (!themeFile.eof())
		{
			str = "";
			getline(themeFile, str);
			words.push_back(str);
			i++;
		}
	}
}

int main() {
  RenderWindow window(VideoMode(1366, 768), "Hangman");
  srand((unsigned)time(NULL));
  Font font;
  Logo logo;
  Music jazz;
  Sound sound;
  Sound clap;
  Menu menuShow;
  mainLogic logic;
  SoundBuffer buffer, buffer2;
  string path, str, the_word;
  ifstream themeFile;
  vector<string> words;
  vector<Sprite> shadow(MAX_SIZE, Sprite());
  vector<Sprite> sprt(MAX_SIZE, Sprite());
  vector<Texture> txtr(MAX_SIZE, Texture());
  int num = 0;
  int i = rand()% 20;
  jazz.openFromFile("audio/Jazz.ogg");
  logo.ShowLogo(window);
  jazz.play();
  jazz.setLoop(true);
  choiseTheTheme(num,&path);
  themeFile.open(path);
  choiseTheWord(themeFile,str,words);
  the_word = words[i];
  loadFromFile(sprt, txtr, shadow);
  menuShow.menu(window,jazz);
  logic.logicFunction(window,sprt,txtr,shadow,jazz,the_word);
  return 0;
}