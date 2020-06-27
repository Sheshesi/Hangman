#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <logo.h>
#include "SFML/Graphics.hpp"
using namespace sf;
TEST_CASE("logo_test","logo"){
    GIVEN("getPosition"){
        RenderWindow window(VideoMode(1366,768),"Title");
        Texture titleTexture;
        Sprite titleSprite;
        titleTexture.loadFromFile("images/TITLE.png");
        titleSprite.setTexture(titleTexture);
        WHEN("Using logo function"){
            Logo logo;
            logo.ShowLogo(window);
            THEN("Changed logo position"){
                FloatRect fRect = titleSprite.getLocalBounds();
                Vector2f expected(fRect.left + fRect.width / 2.0f,
                fRect.top + fRect.height / 2.0f);
                Vector2f expected(window.getSize().x / 2, window.getSize().y/2);
                REQUIRE(titleSprite.getPosition() == expected);
            }
        }
    }
}