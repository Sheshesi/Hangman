#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <logo.h>
#include "SFML/Graphics.hpp"
using namespace sf;
TEST_CASE("logo_test","logo"){
    GIVEN("getPosition"){
        RenderWindow window(VideoMode(1366,768),"Hangman");
        Texture titleTexture, testTexture;
        Sprite titleSprite, testSprite;
        titleTexture.loadFromFile("images/TITLE.png");
        testTexture.loadFromFile("images/TITLE.png");
        titleSprite.setTexture(titleTexture);
        testSprite.setTexture(testTexture);
        WHEN("Using logo function"){
            Logo logo;
            logo.ShowLogo(window);
            THEN("Changed logo position"){
                REQUIRE(titleSprite.getScale() == testSprite.getScale());
            }
        }
    }
}