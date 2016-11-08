install:guesstheword

guesstheword:main.o table.o random.o guess.o
	g++ main.o table.o random.o guess.o -o guesstheword

main.o:mainloop.cpp
	g++ -c mainloop.cpp -o main.o

table.o:table.h table.cpp
	g++ -c table.cpp -o table.o

random.o:random.h random.cpp
	g++ -c random.cpp -o random.o

guess.o:guess.h guess.cpp
	g++ -c guess.cpp -o guess.o
clean:
	rm -rf table.o main.o random.o guess.o guesstheword