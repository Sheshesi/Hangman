.PHONY: clean game
OBJS = Hangman.o logo.o Menu.o
CPP = Hangman.cpp logo.cpp Menu.cpp
SS = g++
SSFLAGS = -Wall -Werror -std=c++11
SFML = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
SR = src/
TRD = thirdparty/
BUL = build/
BIN = bin/
BUL_TEST = build/test/
all: $(BIN)game $(BIN)check

$(BIN)game: $(BUL)Hangman.o $(BUL)logo.o $(BUL)Menu.o $(BUL)HowToPlay.o $(BUL)Options.o $(BUL)logic.o $(BUL)Win.o $(BUL)Lose.o $(BIN)check
	$(SS) -o $(BIN)game $(BUL)Hangman.o $(BUL)logo.o $(BUL)Menu.o $(BUL)HowToPlay.o $(BUL)Options.o $(BUL)logic.o $(BUL)Win.o $(BUL)Lose.o $(SFML)

$(BUL)Hangman.o: $(SR)Hangman.cpp
	$(SS) $(SSFLAGS) -I $(SR) -c $(SR)Hangman.cpp -o $(BUL)Hangman.o $(SFML)

$(BUL)logo.o: $(SR)logo.cpp
	$(SS) $(SSFLAGS) -I $(SR) -c $(SR)logo.cpp -o $(BUL)logo.o $(SFML)

$(BUL)Menu.o: $(SR)Menu.cpp
	$(SS) $(SSFLAGS) -I $(SR) -c $(SR)Menu.cpp -o $(BUL)Menu.o $(SFML)

$(BUL)HowToPlay.o: $(SR)HowToPlay.cpp
	$(SS) $(SSFLAGS) -I $(SR) -c $(SR)HowToPlay.cpp -o $(BUL)HowToPlay.o $(SFML)

$(BUL)Options.o: $(SR)Options.cpp
	$(SS) $(SSFLAGS) -I $(SR) -c $(SR)Options.cpp -o $(BUL)Options.o $(SFML)

$(BUL)logic.o: $(SR)logic.cpp
	$(SS) $(SSFLAGS) -I $(SR) -c $(SR)logic.cpp -o $(BUL)logic.o $(SFML)

$(BUL)Win.o: $(SR)Win.cpp
	$(SS) $(SSFLAGS) -I $(SR) -c $(SR)Win.cpp -o $(BUL)Win.o $(SFML)

$(BUL)Lose.o: $(SR)Lose.cpp
	$(SS) $(SSFLAGS) -I $(SR) -c $(SR)Lose.cpp -o $(BUL)Lose.o $(SFML)

$(BIN)check: $(BUL_TEST)logo_test.o $(BUL)logo.o $(BUL_TEST)option_test.o $(BUL)Options.o
	$(SS) $(BUL_TEST)logo_test.o $(BUL)logo.o $(BUL_TEST)option_test.o $(BUL)Options.o -o $(BIN)check $(SFML)

$(BUL_TEST)logo_test.o: test/logo_test.cpp
	$(SS) -I $(TRD) -I src -c test/logo_test.cpp -o $(BUL_TEST)logo_test.o $(SFML)

$(BUL_TEST)option_test.o: test/option_test.cpp
	$(SS) -I $(TRD) -I src -c test/option_test.cpp -o $(BUL_TEST)option_test.o $(SFML)

testing: 
	$(BIN)check

clean:
	rm -rf $(BUL)*.o
	rm -rf $(BIN)game
run:
	$(BIN)game