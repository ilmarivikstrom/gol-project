#include "cell.hpp"

Cell::Cell(){}

Cell::Cell(sf::Texture& aliveTexture, sf::Texture& deadTexture, CellState new_state, sf::Vector2i new_position){
	state = new_state;
	position = new_position;
	if(new_state == ALIVE){
		texture = aliveTexture;
	}else{
		texture = deadTexture;
	}
}

Cell::~Cell(){}

CellState Cell::getState() const{
	return state;
}

sf::Vector2i Cell::getPosition() const{
	return position;
}
