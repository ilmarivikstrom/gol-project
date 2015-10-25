#define X_MATRIX_SIZE 50
#define Y_MATRIX_SIZE 50
#define CELLSIZE 10
#define FPS 60

#include <SFML/Graphics.hpp>
#include <iostream>
#include "matrix.hpp"

int main() {
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

    // Testing member function flipCellState
    matrix.flipCellState(1, 1);
    std::cout << matrix.getCellState(1, 1) << std::endl;

    // Loading textures
    sf::Texture aliveTexture;
    if (!aliveTexture.loadFromFile("res/alive.png"))
        return -1;

    sf::Texture deadTexture;
    if (!deadTexture.loadFromFile("res/dead.png"))
        return -1;

    // Creating a vector that contains Vector2i data about sprite positions e.g. (0, 0), (O, 10),..., (490, 490)
    std::vector<sf::Vector2i> spritePosVec;
    for (int y = 0; y < Y_MATRIX_SIZE; y++) {
        for (int x = 0; x < X_MATRIX_SIZE; x++) {
            sf::Vector2i place;
            place.y = y * CELLSIZE;
            place.x = x * CELLSIZE;
            spritePosVec.push_back(place);
        }
    }

    // Creating spriteVector which contains all the sprites in the right position. Sets all cells to deadTexture
    std::vector<sf::Sprite> spriteVector;
    for (auto i : spritePosVec) {
        sf::Sprite new_sprite;
        new_sprite.setTexture(deadTexture);
        new_sprite.setPosition(i.x, i.y);
        spriteVector.push_back(new_sprite);
    }



    // Game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // Displaying all the cells that are in the spriteVector
        for (auto i : spriteVector) {
            window.draw(i);
        }
        window.display();
    }

    return EXIT_SUCCESS;

}

