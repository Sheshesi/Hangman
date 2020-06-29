#include "SFML/Graphics.hpp"
#include <HowToPlay.hpp>
#include <catch.hpp>
using namespace sf;
TEST_CASE("Instruction test", "instruction")
{
    GIVEN("button")
    {
        RenderWindow window(VideoMode(1366, 768), "Hangman");
        Texture testButtonTexture, buttonTexture;
        Sprite testButtonSprite, buttonBack;
        testButtonTexture.loadFromFile("images/menu/Back.png");
        buttonTexture.loadFromFile("images/menu/Back.png");
        buttonBack.setTexture(buttonTexture);
        testButtonSprite.setTexture(testButtonTexture);
        testButtonSprite.setColor(Color::White);
        WHEN("Option function")
        {
            howToButton howTo;
            howTo.HowToPlay(window);
            THEN("Changed logo position")
            {
                REQUIRE(testButtonSprite.getColor() == buttonBack.getColor());
            }
        }
    }
}