.PHONY: clean game
OBJS = Hangman.o logo.o Menu.o
CPP = Hangman.cpp logo.cpp Menu.cpp
SS = g++
SSFLAGS = -Wall -Werror -std=c++11
SFML = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
SR = src/
BUL = build/
BIN = bin/

game: $(BUL)Hangman.o $(BUL)logo.o $(BUL)Menu.o
	$(SS) -o $(BIN)game $(BUL)Hangman.o $(BUL)logo.o $(BUL)Menu.o $(SFML)

$(BUL)Hangman.o: $(SR)Hangman.cpp
	$(SS) $(SSFLAGS) -I $(SR) -c $(SR)Hangman.cpp -o $(BUL)Hangman.o $(SFML)

$(BUL)logo.o: $(SR)logo.cpp
	$(SS) $(SSFLAGS) -I $(SR) -c $(SR)logo.cpp -o $(BUL)logo.o $(SFML)

$(BUL)Menu.o: $(SR)Menu.cpp
	$(SS) $(SSFLAGS) -I $(SR) -c $(SR)Menu.cpp -o $(BUL)Menu.o $(SFML)

clean:
	rm -rf $(BUL)*.o
	rm -rf $(BIN)game

run:
	$(BIN)game