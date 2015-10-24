#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>

enum class CellState {ALIVE, DEAD};	// For cell state

class Cell	// Cell class declaration begins
{
	public:
		Cell(){}
		Cell(sf::Texture& aliveTexture, sf::Texture& deadTexture, CellState state, sf::Vector2i position);
		~Cell(){}
		
		// Getter declarations
		CellState getState() const;
		sf::Vector2i getPosition() const;
		
	private:
		CellState state;
		sf::Vector2i position;
		sf::Texture aliveTexture;
		sf::Texture deadTexture;
		
};






#endif
