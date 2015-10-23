all: main.o
	g++ main.o -o gol -lsfml-graphics -lsfml-window -lsfml-system
main.o: main.cpp
	g++ -c /src/main.cpp
clean:
	rm -rf *.o gol
run:
	./gol
