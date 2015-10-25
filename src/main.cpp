#define X_MATRIX_SIZE 50
#define Y_MATRIX_SIZE 50
#define CELLSIZE 10
#define FPS 60

#include <SFML/Graphics.hpp>
#include <iostream>
#include "matrix.hpp"

int main()
{	
	sf::Vector2i SCREEN(X_MATRIX_SIZE * CELLSIZE, Y_MATRIX_SIZE * CELLSIZE);
	sf::RenderWindow window(sf::VideoMode(SCREEN.x, SCREEN.y), "Game of life v0.01");
	window.setFramerateLimit(FPS);
	
	// Creating matrix object
	Matrix matrix(Y_MATRIX_SIZE, X_MATRIX_SIZE);
	std::cout << matrix.getCellState(1, 1) << std::endl;
	// Testing member function setCellState
	matrix.setCellState(1, 1, true);
	std::cout << matrix.getCellState(1, 1) << std::endl;
	// Testing member function clearMatrix
	matrix.clearMatrix();
	std::cout << matrix.getCellState(1, 1) << std::endl;
	//Testing member function flipCellState
	matrix.flipCellState(1, 1);
	std::cout << matrix.getCellState(1, 1) << std::endl;
	
	
	// Game loop
	while(window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear();
		
		window.display();
	}
	
	return EXIT_SUCCESS;
	
}

