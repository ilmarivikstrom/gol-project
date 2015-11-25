#define X_MATRIX_SIZE 100
#define Y_MATRIX_SIZE 100
#define CELLSIZE 10
#define FPS 20

#include <SFML/Graphics.hpp>
#include <unistd.h>
#include "matrix.hpp"

int main() {
  sf::Vector2i SCREEN(X_MATRIX_SIZE * CELLSIZE, Y_MATRIX_SIZE * CELLSIZE);
  sf::RenderWindow window(sf::VideoMode(SCREEN.x, SCREEN.y), \
                          "Game of Life v0.10. Author Ilmari Vikstroem");
  window.setFramerateLimit(FPS);
  // Creating matrix object
  Matrix board(Y_MATRIX_SIZE, X_MATRIX_SIZE);
  // Loading textures
  sf::Texture aliveTexture;
  if (!aliveTexture.loadFromFile("../res/alive.png"))
    return -1;
  sf::Texture deadTexture;
  if (!deadTexture.loadFromFile("../res/dead.png"))
    return -1;
  /* Creating a vector that contains Vector2i data about sprite positions 
   * e.g. (0, 0), (O, 10),..., (490, 490) */
  std::vector<sf::Vector2i> spritePosVec;
  for (int y = 0; y < Y_MATRIX_SIZE; y++) {
    for (int x = 0; x < X_MATRIX_SIZE; x++) {
      sf::Vector2i place;
      place.y = y * CELLSIZE;
      place.x = x * CELLSIZE;
      spritePosVec.push_back(place);
    }
  }
  std::vector<sf::Sprite> spriteVector;
  sf::Sprite sprite;
  board.randomMatrix();
  // **********Game loop**********
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    for (auto i : spritePosVec) {
      if (board.getCellState(i.y / CELLSIZE, i.x / CELLSIZE) == false)
        sprite.setTexture(deadTexture);
      else
        sprite.setTexture(aliveTexture);
      sprite.setPosition(i.x, i.y);
      
      spriteVector.push_back(sprite);
    }

    board.updateMatrix();

    window.clear();

    // Displaying all the cells that are in the spriteVector
    for (auto i : spriteVector) {
      window.draw(i);
    }
    spriteVector.clear();

    window.display();
  }
  return EXIT_SUCCESS;
}
