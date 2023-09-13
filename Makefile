Game: GameCharacter.o game.o
	c++ GameCharacter.o game.o -o Game

GameCharacter.o: GameCharacter.cpp
	c++ -c GameCharacter.cpp

game.o: game.cpp
	c++ -c game.cpp

clean:
	rm *.o Game
