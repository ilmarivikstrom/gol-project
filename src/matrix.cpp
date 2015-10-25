#include <cstdlib>
#include <iostream>
#include "matrix.hpp"

Matrix::Matrix(int _ySize, int _xSize) {
    ySize = _ySize;
    xSize = _xSize;
    gol_matrix.clear();
    for (int y = 0; y < ySize; y++) {
        std::vector<bool> row;
        for (int x = 0; x < xSize; x++) {
            row.push_back(false);
        }
        gol_matrix.push_back(row);
    }
}

Matrix::Matrix() {
    xSize = 50;
    ySize = 50;
    for (int y = 0; y < ySize; y++) {
        std::vector<bool> row;
        for (int x = 0; x < xSize; x++) {
            row.push_back(false);
        }
        gol_matrix.push_back(row);
    }
}

bool Matrix::getCellState(int y, int x) const {
    return gol_matrix[y][x];
}

int Matrix::getXSize() const {
    return xSize;
}

int Matrix::getYSize() const {
    return ySize;
}

void Matrix::setCellState(int y, int x, bool state) {
    gol_matrix[y][x] = state;
}

void Matrix::flipCellState(int y, int x) {
    gol_matrix[y][x] = !gol_matrix[y][x];
}

void Matrix::randomMatrix(){
    std::vector<std::vector<bool> > gol_matrix_new;
    for(int y = 0; y < getYSize(); y++){
        std::vector<bool> row;
        for(int x = 0; x < getXSize(); x++){
            int r = rand() % 6;
            std::cout << r << std::endl;
            if(r == 1)
                row.push_back(true);
            else
                row.push_back(false);
        }
        gol_matrix_new.push_back(row);
    }
    gol_matrix = gol_matrix_new;
}

void Matrix::updateMatrix() {
    std::vector<std::vector<bool> > gol_matrix_new;
    for(int y = 0; y < getYSize(); y++){
        std::vector<bool> row;
        for(int x = 0; x < getXSize(); x++){
            int count = countAdjacentCells(y, x);
            if(gol_matrix[y][x] == true){           // IF ALIVE                
                if(count < 2){
                    row.push_back(false);
                }
                if(count == 2 || count == 3){
                    row.push_back(true);
                }
                if(count > 3){
                    row.push_back(false);
                }
            }
            if(gol_matrix[y][x] == false){
                if(count == 3)
                    row.push_back(true);
                else
                    row.push_back(false);
            }
        }
        gol_matrix_new.push_back(row);
    }
    gol_matrix = gol_matrix_new;
}

void Matrix::clearMatrix() {
    for (int y = 0; y < ySize; y++) {
        for (int x = 0; x < xSize; x++) {
            gol_matrix[y][x] = false;
        }
    }
}

int Matrix::countAdjacentCells(int y, int x) {          // Counts adjacent cells of (y, x)
    int count = 0;
    if(y == 0 && x == 0){                               //UPPERLEFT
        if(gol_matrix[y+1][x] == true)
            count++;
        if(gol_matrix[y+1][x+1] == true)
            count++;
        if(gol_matrix[y][x+1] == true)
            count++;
    }else if(y == this->getYSize()-1 && x == this->getXSize()-1){ //LOWERRIGHT
        if(gol_matrix[y][x-1] == true)
            count++;
        if(gol_matrix[y-1][x-1] == true)
            count++;
        if(gol_matrix[y-1][x] == true)
            count++;
    }else if(y == this->getYSize()-1 && x == 0){                //LOWERLEFT
        if(gol_matrix[y-1][x] == true)
            count++;
        if(gol_matrix[y-1][x+1] == true)
            count++;
        if(gol_matrix[y][x+1] == true)
            count++;
    }else if(y == 0 && x == this->getXSize()-1){                //UPPERRIGHT
        if(gol_matrix[y][x-1] == true)
            count++;
        if(gol_matrix[y+1][x-1] == true)
            count++;
        if(gol_matrix[y+1][x] == true)
            count++;
    }else if(y == 0 && x != 0 && x != this->getXSize()-1){       //IF FIRST LINE
        if(gol_matrix[y][x-1] == true)
            count++;
        if(gol_matrix[y][x+1] == true)
            count++;
        if(gol_matrix[y+1][x] == true)
            count++;
        if(gol_matrix[y+1][x+1] == true)
            count++;
        if(gol_matrix[y+1][x-1] == true)
            count++;
    }else if(y == this->getYSize()-1 && x != 0 && x != this->getXSize()-1){       //IF LAST LINE
        if(gol_matrix[y][x-1] == true)
            count++;
        if(gol_matrix[y][x+1] == true)
            count++;
        if(gol_matrix[y-1][x] == true)
            count++;
        if(gol_matrix[y-1][x+1] == true)
            count++;
        if(gol_matrix[y-1][x-1] == true)
            count++;
    }else if(x == 0 && y != 0 && y != this->getYSize()-1){       //IF LEFT COLUMN
        if(gol_matrix[y-1][x] == true)
            count++;
        if(gol_matrix[y-1][x+1] == true)
            count++;
        if(gol_matrix[y][x+1] == true)
            count++;
        if(gol_matrix[y+1][x+1] == true)
            count++;
        if(gol_matrix[y+1][x] == true)
            count++;
    }else if(x == this->getXSize()-1 && y != 0 && y != this->getYSize()-1){       //IF RIGHT COLUMN
        if(gol_matrix[y-1][x] == true)
            count++;
        if(gol_matrix[y+1][x] == true)
            count++;
        if(gol_matrix[y][x-1] == true)
            count++;
        if(gol_matrix[y+1][x-1] == true)
            count++;
        if(gol_matrix[y-1][x-1] == true)
            count++;
    }else{                                                                  //IF ANYTHING ELSE
        if(gol_matrix[y][x-1] == true){
            count++;
        }
        if(gol_matrix[y-1][x-1] == true){
            count++;
        }
        if(gol_matrix[y-1][x] == true){
            count++;
        }
        if(gol_matrix[y-1][x+1] == true){
            count++;
        }
        if(gol_matrix[y][x+1] == true){
            count++;
        }
        if(gol_matrix[y+1][x+1] == true){
            count++;
        }
        if(gol_matrix[y+1][x] == true){
            count++;
        }
        if(gol_matrix[y+1][x-1] == true){
            count++;
        }
    }
    return count;
}

std::vector<std::vector<bool> > Matrix::getMatrix() {
    return gol_matrix;
}
