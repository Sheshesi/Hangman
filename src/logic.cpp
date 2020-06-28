#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <algorithm>
#include "logic.hpp"
#include "Menu.h"
using namespace sf;
using namespace std;
const int MAX_SIZE = 26; // Максимальное количество букв латинского алфавита

void matchLetter(const string &THE_WORD, char &letter, string &used, int &pos, int &wrong, Clock &clock) {
	if (THE_WORD.find(letter) != string::npos)
	{
		for (unsigned int i = 0; i < THE_WORD.size(); i++)
		{
			if (THE_WORD[i] == letter)
			{
				used[i] = THE_WORD[pos];
			}
		}
	}
	else
	{
		wrong++;
	}
	clock.restart();
}

void mainLogic::logicFunction(RenderWindow& window,vector<Sprite> &sprt, vector<Texture> &txtr, vector<Sprite> &shadow, Music &jazz, const string &THE_WORD){
    Texture hangPart_1, hangPart_2, hangPart_3, hangPart_4, rope, man, backgroundTexture;
    Sprite hangPartSprite_1, hangPartSprite_2, hangPartSprite_3, hangPartSprite_4, ropeSprite, manSprite, backgroundSprite;
    Clock clock;
    Menu menuShow;
    Sound sound, clap;
	SoundBuffer buffer, buffer_2;
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
    ropeSprite.setScale(0.8, 0.8);
    manSprite.setScale(0.8, 0.8);
    hangPartSprite_1.setScale(0.8, 0.8);
    hangPartSprite_2.setScale(0.8, 0.8);
    hangPartSprite_3.setScale(0.8, 0.8);
    hangPartSprite_4.setScale(0.8, 0.8);
    backgroundSprite.setScale(0.9, 0.9);
    string used(THE_WORD.size(),'-');
    float x = 600;
	float y = 100;
    int wrong = 0;
    bool isLogic = true;
    while (isLogic)
	{
		window.clear(Color::Black);
		window.draw(backgroundSprite);
		char letter = ' ';
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				menuShow.menu(window,sprt,txtr,shadow,jazz,THE_WORD);
			}
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		x = 600;
		for (int i = 0; i < 7; i++) {   //Выстраивание первого ряда букв
			sprt[i].setPosition(x, y);
			sprt[i].setColor(Color::White);
			shadow[i].setPosition(x + 10, y + 10);
			x += 100;
		}
		x = 600;
		for (int i = 7; i < 14; i++) {  //Выстраивание второго ряда букв
			sprt[i].setPosition(x, y + 100);
			sprt[i].setColor(Color::White);
			shadow[i].setPosition(x + 10, y + 110);
			x += 100;
		}
		x = 600;
		for (int i = 14; i < 21; i++)   //Выстраивание третьего ряда букв
		{
			sprt[i].setPosition(x, y + 200);
			sprt[i].setColor(Color::White);
			shadow[i].setPosition(x + 10, y + 210);
			x += 100;
		}
		x = 700;
		for (int i = 21; i < 26; i++) { //Выстраивание четвертого ряда букв
			sprt[i].setPosition(x, y + 300);
			sprt[i].setColor(Color::White);
			shadow[i].setPosition(x + 10, y + 310);
			x += 100;
		}
		if (IntRect(600, 100, 50, 70).contains(Mouse::getPosition(window)))
		{
			sprt[0].setPosition(610, 110);
			sprt[0].setColor(Color(200, 200, 200));
			letter = 'A';
		}
		if (IntRect(700, 100, 50, 70).contains(Mouse::getPosition(window)))
		{
			sprt[1].setPosition(710, 110);
			sprt[1].setColor(Color(200, 200, 200));
			letter = 'B';
		}
		if (IntRect(800, 100, 50, 70).contains(Mouse::getPosition(window)))
		{
			sprt[2].setPosition(810, 110);
			sprt[2].setColor(Color(200, 200, 200));
			letter = 'C';
		}
		if (IntRect(900, 100, 50, 70).contains(Mouse::getPosition(window)))
		{
			sprt[3].setPosition(910, 110);
			sprt[3].setColor(Color(200, 200, 200));
			letter = 'D';
		}
		if (IntRect(1000, 100, 50, 70).contains(Mouse::getPosition(window)))
		{
			sprt[4].setPosition(1010, 110);
			sprt[4].setColor(Color(200, 200, 200));
			letter = 'E';
		}
		if (IntRect(1100, 100, 50, 70).contains(Mouse::getPosition(window)))
		{
			sprt[5].setPosition(1110, 110);
			sprt[5].setColor(Color(200, 200, 200));
			letter = 'F';
		}
		if (IntRect(1200, 100, 50, 70).contains(Mouse::getPosition(window)))
		{
			sprt[6].setPosition(1210, 110);
			sprt[6].setColor(Color(200, 200, 200));
			letter = 'G';
		}
		if (IntRect(600, 200, 50, 70).contains(Mouse::getPosition(window)))
		{
			sprt[7].setPosition(610, 210);
			sprt[7].setColor(Color(200, 200, 200));
			letter = 'H';
		}
		if (IntRect(700, 200, 50, 70).contains(Mouse::getPosition(window)))
		{
			sprt[8].setPosition(710, 210);
			sprt[8].setColor(Color(200, 200, 200));
			letter = 'I';
		}
		if (IntRect(800, 200, 50, 70).contains(Mouse::getPosition(window)))
		{
			sprt[9].setPosition(810, 210);
			sprt[9].setColor(Color(200, 200, 200));
			letter = 'J';
		}
		if (IntRect(900, 200, 50, 70).contains(Mouse::getPosition(window)))
		{
			sprt[10].setPosition(910, 210);
			sprt[10].setColor(Color(200, 200, 200));
			letter = 'K';
		}
		if (IntRect(1000, 200, 50, 70).contains(Mouse::getPosition(window)))
		{
			sprt[11].setPosition(1010, 210);
			sprt[11].setColor(Color(200, 200, 200));
			letter = 'L';
		}
		if (IntRect(1100, 200, 50, 70).contains(Mouse::getPosition(window)))
		{
			sprt[12].setPosition(1110, 210);
			sprt[12].setColor(Color(200, 200, 200));
			if (event.type == Event::MouseButtonReleased)
			letter = 'M';
		}
		if (IntRect(1200, 200, 50, 70).contains(Mouse::getPosition(window)))
		{
			sprt[13].setPosition(1210, 210);
			sprt[13].setColor(Color(200, 200, 200));
			letter = 'N';
		}
		if (IntRect(600, 300, 50, 70).contains(Mouse::getPosition(window)))
		{
			sprt[14].setPosition(610, 310);
			sprt[14].setColor(Color(200, 200, 200));
			letter = 'O';
		}
		if (IntRect(700, 300, 50, 70).contains(Mouse::getPosition(window)))
		{
			sprt[15].setPosition(710, 310);
			sprt[15].setColor(Color(200, 200, 200));
			letter = 'P';
		}
		if (IntRect(800, 300, 50, 70).contains(Mouse::getPosition(window)))
		{
			sprt[16].setPosition(810, 310);
			sprt[16].setColor(Color(200, 200, 200));
			letter = 'Q';
		}
		if (IntRect(900, 300, 50, 70).contains(Mouse::getPosition(window)))
		{
			sprt[17].setPosition(910, 310);
			sprt[17].setColor(Color(200, 200, 200));
			letter = 'R';
		}
		if (IntRect(1000, 300, 50, 70).contains(Mouse::getPosition(window)))
		{
			sprt[18].setPosition(1010, 310);
			sprt[18].setColor(Color(200, 200, 200));
			letter = 'S';
		}
		if (IntRect(1100, 300, 50, 70).contains(Mouse::getPosition(window)))
		{
			sprt[19].setPosition(1110, 310);
			sprt[19].setColor(Color(200, 200, 200));
			letter = 'T';
		}
		if (IntRect(1200, 300, 50, 70).contains(Mouse::getPosition(window)))
		{
			sprt[20].setPosition(1210, 310);
			sprt[20].setColor(Color(200, 200, 200));
			letter = 'U';
		}
		if (IntRect(700, 400, 50, 70).contains(Mouse::getPosition(window)))
		{
			sprt[21].setPosition(710, 410);
			sprt[21].setColor(Color(200, 200, 200));
			letter = 'V';
		}
		if (IntRect(800, 400, 50, 70).contains(Mouse::getPosition(window)))
		{
			sprt[22].setPosition(810, 410);
			sprt[22].setColor(Color(200, 200, 200));
			letter = 'W';
		}
		if (IntRect(900, 400, 50, 70).contains(Mouse::getPosition(window)))
		{
			sprt[23].setPosition(910, 410);
			sprt[23].setColor(Color(200, 200, 200));
			letter = 'X';
		}
		if (IntRect(1000, 400, 50, 70).contains(Mouse::getPosition(window)))
		{
			sprt[24].setPosition(1010, 410);
			sprt[24].setColor(Color(200, 200, 200));
			letter = 'Y';
		}
		if (IntRect(1100, 400, 50, 70).contains(Mouse::getPosition(window)))
		{
			sprt[25].setPosition(1110, 410);
			sprt[25].setColor(Color(200, 200, 200));
			letter = 'Z';
		}
		int pos = THE_WORD.find(letter);
		if (event.type == Event::MouseButtonReleased)
		{
			if (event.mouseButton.button == Mouse::Left)
			{
				if (clock.getElapsedTime().asMilliseconds() > 200) {
					if (letter == 'A')
					{
						sound.play();
						sprt[0].setColor(Color::Red);
						matchLetter(THE_WORD, letter, used, pos, wrong, clock);
					}
					if (letter == 'B')
					{
						sound.play();
						matchLetter(THE_WORD, letter, used, pos, wrong, clock);
					}
					if (letter == 'C')
					{
						sound.play();
						matchLetter(THE_WORD, letter, used, pos, wrong, clock);
					}
					if (letter == 'D')
					{
						sound.play();
						matchLetter(THE_WORD, letter, used, pos, wrong, clock);
					}
					if (letter == 'E')
					{
						sound.play();
						matchLetter(THE_WORD, letter, used, pos, wrong, clock);
					}
					if (letter == 'F')
					{
						sound.play();
						matchLetter(THE_WORD, letter, used, pos, wrong, clock);
					}
					if (letter == 'G')
					{
						sound.play();
						matchLetter(THE_WORD, letter, used, pos, wrong, clock);
					}
					if (letter == 'H')
					{
						sound.play();
						matchLetter(THE_WORD, letter, used, pos, wrong, clock);
					}
					if (letter == 'I')
					{
						sound.play();
						matchLetter(THE_WORD, letter, used, pos, wrong, clock);
					}
					if (letter == 'J')
					{
						sound.play();
						matchLetter(THE_WORD, letter, used, pos, wrong, clock);
					}
					if (letter == 'K')
					{
						sound.play();
						matchLetter(THE_WORD, letter, used, pos, wrong, clock);
					}
					if (letter == 'L')
					{
						sound.play();
						matchLetter(THE_WORD, letter, used, pos, wrong, clock);
					}
					if (letter == 'M')
					{
						sound.play();
						matchLetter(THE_WORD, letter, used, pos, wrong, clock);
					}
					if (letter == 'N')
					{
						sound.play();
						matchLetter(THE_WORD, letter, used, pos, wrong, clock);
					}
					if (letter == 'O')
					{
						sound.play();
						matchLetter(THE_WORD, letter, used, pos, wrong, clock);
					}
					if (letter == 'P')
					{
						sound.play();
						matchLetter(THE_WORD, letter, used, pos, wrong, clock);
					}
					if (letter == 'R')
					{
						sound.play();
						matchLetter(THE_WORD, letter, used, pos, wrong, clock);
					}
					if (letter == 'S')
					{
						sound.play();
						matchLetter(THE_WORD, letter, used, pos, wrong, clock);
					}
					if (letter == 'Q')
					{
						sound.play();
						matchLetter(THE_WORD, letter, used, pos, wrong, clock);
					}
					if (letter == 'T')
					{
						sound.play();
						matchLetter(THE_WORD, letter, used, pos, wrong, clock);
					}
					if (letter == 'U')
					{
						sound.play();
						matchLetter(THE_WORD, letter, used, pos, wrong, clock);
					}
					if (letter == 'V')
					{
						sound.play();
						matchLetter(THE_WORD, letter, used, pos, wrong, clock);
					}
					if (letter == 'W')
					{
						sound.play();
						matchLetter(THE_WORD, letter, used, pos, wrong, clock);
					}
					if (letter == 'X')
					{
						sound.play();
						matchLetter(THE_WORD, letter, used, pos, wrong, clock);
					}
					if (letter == 'Y')
					{
						sound.play();
						matchLetter(THE_WORD, letter, used, pos, wrong, clock);
					}
					if (letter == 'Z')
					{
						sound.play();
						matchLetter(THE_WORD, letter, used, pos, wrong, clock);
					}
				}
				clock.restart();
			}
		}
		for (int i = 0; i < MAX_SIZE; i++) {
			window.draw(shadow[i]);
		}
		for (int i = 0; i < MAX_SIZE; i++) {
			window.draw(sprt[i]);
		}
		window.display();
	}
}
