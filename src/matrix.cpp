#include "matrix.hpp"
#include <iostream>

Matrix::Matrix(int _ySize, int _xSize){
	ySize = _ySize;
	xSize = _xSize;
	gol_matrix.clear();
	for(int y = 0; y < ySize; y++){
		for(int x = 0; x < xSize; x++){
			// Set cell [y][x] to false here somehow.
		}
	}
	
}

Matrix::Matrix(){
	xSize = 50;
	ySize = 50;
	for(int y = 0; y < ySize; y++){
		for(int x = 0; x < xSize; x++){
			// Set cell [y][x] to false here somehow.
		}
	}
}

bool Matrix::getCellState(int x, int y) const{
	return gol_matrix[y][x];
}

int Matrix::getXSize() const{
	return xSize;
}

int Matrix::getYSize() const{
	return ySize;
}

void Matrix::setCellState(int x, int y, bool state){
	gol_matrix[y][x] = state;
}

void Matrix::flipCellState(int x, int y){
	gol_matrix[y][x] = !gol_matrix[y][x];
}

void updateMatrix(){
	// implement matrix iteration and update logic here
}

void clearMatrix(){
	// implement matrix iteration and setting to false logic here
}

void countAdjacentCells(int x, int y){
	// implement matrix iteration and finding the state of nearest cells logic here
}

std::vector<std::vector<bool> > Matrix::getMatrix(){
	return gol_matrix;
}
