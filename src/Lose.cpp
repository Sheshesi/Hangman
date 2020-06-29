#include "Lose.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
using namespace sf;
using namespace std;
bool loseWindow::Lose(RenderWindow& window)
{
	Image wind, yes, no;
	wind.loadFromFile("images/Lose/1x/window.png");
	yes.loadFromFile("images/Lose/1x/Yes.png");
	no.loadFromFile("images/Lose/1x/No.png");
    Texture Wind, Yes, No;
	Wind.loadFromImage(wind);
	Yes.loadFromImage(yes);
	No.loadFromImage(no);
}