install:guesstheword

guesstheword:main.o table.o random.o guess.o global.o
	g++ main.o table.o global.o guess.o -o guesstheword

main.o:main.cpp
	g++ -c main.cpp -o main.o

global.o:global.h global.cpp
	g++ -c global.cpp -o global.o

table.o:table.h table.cpp
	g++ -c table.cpp -o table.o

guess.o:guess.h guess.cpp
	g++ -c guess.cpp -o guess.o

clean:
	rm -rf table.o main.o global.o guess.o guesstheword