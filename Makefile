# Makefile for stuff. How c

all: main.o
	g++ main.o -o gol -lsfml-graphics -lsfml-window -lsfml-system
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm -rf *.o gol
run:
	./gol
