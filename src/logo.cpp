#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "logo.hpp"
using namespace sf;
using namespace std;
void Logo::ShowLogo(RenderWindow &window) {
  Music music;
  Texture titleTexture;
  Sprite titleSprite;
  Clock clock;
  music.openFromFile("audio/Logo.ogg");
  music.play();
  titleTexture.loadFromFile("images/TITLE.png");
  titleTexture.setSmooth(true);
  titleSprite.setTexture(titleTexture);
  titleSprite.setColor(Color::White);
  FloatRect fRect = titleSprite.getLocalBounds();
  titleSprite.setOrigin(fRect.left + fRect.width / 2.0f,
                        fRect.top +
                            fRect.height / 2.0f); //Определение центра спрайта
  titleSprite.setPosition(window.getSize().x / 2,
                          window.getSize().y /
                              2); //Выставление спрайта по центру экрана
  float scale = 0.8; //Изначальный масштаб для спрайта
  float fadeBegin = 0; //Изначальная прозрачность спрайта
  float fadeEnd = 240; //Конечная прозрачность спрайта
  bool isShowLogo = true;
  Event event;
  while (isShowLogo) {
    while (window.pollEvent(event)) {
      if (Keyboard::isKeyPressed(Keyboard::Escape) ||
          Keyboard::isKeyPressed(Keyboard::Space)) {
        isShowLogo = false;
      }
    }
    float time = clock.getElapsedTime().asMicroseconds(); //Определение времени
                                                          //как микросекунды
    clock.restart();    //Перезапуск времени
    time = time / 4500; //Скорость игры
    window.clear();     //Очистка экрана
    if (fadeBegin < 240) {
      fadeBegin += 0.3 * time;
      titleSprite.setColor(Color(255, 255, 255, fadeBegin));
      scale += 0.0001 * time;
      titleSprite.setScale(scale, scale);
      window.draw(titleSprite);
      window.display();
    } else {
      if (fadeEnd > 0) {
        fadeEnd -= 0.5 * time;
        titleSprite.setColor(Color(255, 255, 255, fadeEnd));
        window.draw(titleSprite);
        window.display();
      } else {
        isShowLogo = false;
      }
    }
  }
}
