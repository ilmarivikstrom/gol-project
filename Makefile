# Makefile for stuff

all: main.o matrix.o
	cd src; g++ -Wall main.o matrix.o -o gol -lsfml-graphics -lsfml-window -lsfml-system; mv gol ../
main.o: src/main.cpp
	cd src; g++ -std=c++11 -c -Wall main.cpp
matrix.o: src/matrix.cpp
	cd src; g++ -std=c++11 -c -Wall matrix.cpp
clean:
	cd src; rm -rf *.o
	rm -rf gol
run:
	./gol

debug:
	cd src; g++ -Wall --debug=a main.o matrix.o -o gol -lsfml-graphics -lsfml-window -lsfml-system; mv gol ../