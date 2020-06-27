.PHONY: clean game
OBJS = Hangman.o logo.o Menu.o
CPP = Hangman.cpp logo.cpp Menu.cpp
SS = g++
SSFLAGS = -Wall -Werror -std=c++11
SFML = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
SR = src/
BUL = build/
BIN = bin/
BUL_TEST = build/test/
all: $(BIN)game $(BIN)check

$(BIN)game: $(BUL)Hangman.o $(BUL)logo.o $(BUL)Menu.o $(BUL)HowToPlay.o $(BIN)check
	$(SS) -o $(BIN)game $(BUL)Hangman.o $(BUL)logo.o $(BUL)Menu.o $(BUL)HowToPlay.o $(SFML)

$(BUL)Hangman.o: $(SR)Hangman.cpp
	$(SS) $(SSFLAGS) -I $(SR) -c $(SR)Hangman.cpp -o $(BUL)Hangman.o $(SFML)

$(BUL)logo.o: $(SR)logo.cpp
	$(SS) $(SSFLAGS) -I $(SR) -c $(SR)logo.cpp -o $(BUL)logo.o $(SFML)

$(BUL)Menu.o: $(SR)Menu.cpp
	$(SS) $(SSFLAGS) -I $(SR) -c $(SR)Menu.cpp -o $(BUL)Menu.o $(SFML)

$(BUL)HowToPlay.o: $(SR)HowToPlay.cpp
	$(SS) $(SSFLAGS) -I $(SR) -c $(SR)HowToPlay.cpp -o $(BUL)HowToPlay.o $(SFML)


$(BIN)check: $(BUL_TEST)logo_test.o $(BUL)logo.o
	$(SS) $(BUL_TEST)logo_test.o $(BUL)logo.o -o $(BIN)check $(SFML)

$(BUL_TEST)logo_test.o: test/logo_test.cpp
	$(SS) -I thirdparty -I src -c test/logo_test.cpp -o $(BUL_TEST)logo_test.o $(SFML)

testing:
	$(BIN)check

clean:
	rm -rf $(BUL)*.o
	rm -rf $(BIN)game
	rm -rf $(BIN)check

run:
	$(BIN)game