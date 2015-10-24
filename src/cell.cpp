#include "cell.hpp"

//Cell::Cell(){}

// Constructor
Cell::Cell(sf::Texture& aliveTexture, sf::Texture& deadTexture, CellState new_state, sf::Vector2i new_position){
	state = new_state;
	position = new_position;
	if(new_state == ALIVE){
		//PUT ON ALIVETEXTURE
	}else{
		//PUT ON DEADTEXTURE
	}
}

// Getter implementations
CellState Cell::getState() const{
	return state;
}
sf::Vector2i Cell::getPosition() const{
	return position;
}

// Setter implementations
void Cell::setState(CellState new_state){
	this->state = new_state;
}
