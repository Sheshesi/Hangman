#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "logic.hpp"
using namespace sf;
using namespace std;
void mainLogic::logicFunction(RenderWindow& window,vector<Sprite> &sprt, vector<Texture> &txtr, vector<Sprite> &shadow){
    Texture hangPart_1, hangPart_2, hangPart_3, hangPart_4, rope, man;
    Sprite hangPartSprite_1, hangPartSprite_2, hangPartSprite_3, hangPartSprite_4, ropeSprite, manSprite;
    hangPart_1.loadFromFile("images/hang/1 board.png");
    hangPart_2.loadFromFile("images/hang/2 board.png");
    hangPart_3.loadFromFile("images/hang/3 board.png");
    hangPart_4.loadFromFile("images/hang/4 board.png");
    rope.loadFromFile("images/hang/rope.png");
    man.loadFromFile("images/hang/man.png");
}