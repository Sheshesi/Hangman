#include "SFML/Graphics.hpp"
#include <Options.hpp>
#include <catch.hpp>
using namespace sf;
TEST_CASE("volume_test", "volume")
{
    GIVEN("getVolume")
    {
        RenderWindow window(VideoMode(1366, 768), "Hangman");
        Music jazz;
        int volume = 100;
        WHEN("Option function")
        {
            options optionButton;
            optionButton.Option(window, jazz);
            THEN("Changed logo position")
            {
                REQUIRE(volume == jazz.getVolume());
            }
        }
    }
}