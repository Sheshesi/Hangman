#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "logic.hpp"
using namespace sf;
using namespace std;
void mainLogic::logicFunction(RenderWindow& window,vector<Sprite> &sprt, vector<Texture> &txtr, vector<Sprite> &shadow){
    Texture hangPart_1, hangPart_2, hangPart_3, hangPart_4, rope, man, backgroundTexture;
    Sprite hangPartSprite_1, hangPartSprite_2, hangPartSprite_3, hangPartSprite_4, ropeSprite, manSprite, backgroundSprite;
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
    
}