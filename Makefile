# Makefile for stuff

all: main.o matrix.o
	cd src; g++ -Wall main.o matrix.o -o gol -lsfml-graphics -lsfml-window -lsfml-system; mv gol ../
main.o: src/main.cpp
	cd src; g++ -c -Wall main.cpp
matrix.o: src/matrix.cpp
	cd src; g++ -c -Wall matrix.cpp
clean:
	cd src; rm -rf *.o
	rm -rf gol
run:
	./gol
