# Makefile for stuff

all: main.o
	cd src; g++ -Wall main.o -o gol -lsfml-graphics -lsfml-window -lsfml-system; mv gol ../
main.o: src/main.cpp
	cd src; g++ -c -Wall main.cpp
src/main.cpp: src/cell.cpp
	cd src; g++ -c -Wall cell.cpp
clean:
	cd src; rm -rf *.o
	rm -rf gol
run:
	./gol
