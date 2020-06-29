#include "Win.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
using namespace sf;
using namespace std;
bool winWindow::Win(RenderWindow& window) {
    Image wind, yes, no;
	wind.loadFromFile("images/Win/1x/window.png");
	yes.loadFromFile("images/Win/1x/yes.png");
	no.loadFromFile("images/Win/1x/no.png");
    Texture Wind, Yes, No;
	Wind.loadFromImage(wind);
	Yes.loadFromImage(yes);
	No.loadFromImage(no);
    Sprite WIND, YES, NO;
	WIND.setTexture(Wind);
	YES.setTexture(Yes);
	NO.setTexture(No);
	WIND.setPosition(450, 240);
}