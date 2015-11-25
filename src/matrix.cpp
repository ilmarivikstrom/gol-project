#include <cstdlib>
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

// This is for click toggling
void Matrix::flipCellState(int y, int x) {
  gol_matrix[y][x] = !gol_matrix[y][x];
}

// Creates a random matrix. rand() % x
void Matrix::randomMatrix() {
  std::vector < std::vector<bool> > gol_matrix_new;
  for (int y = 0; y < getYSize(); y++) {
    std::vector<bool> row;
    for (int x = 0; x < getXSize(); x++) {
      int r = rand() % 6;
      if (r == 1)
        row.push_back(true);
      else
        row.push_back(false);
    }
    gol_matrix_new.push_back(row);
  }
  gol_matrix = gol_matrix_new;
}

void Matrix::updateMatrix() {
  std::vector < std::vector<bool> > gol_matrix_new;
  for (int y = 0; y < getYSize(); y++) {
    std::vector<bool> row;
    for (int x = 0; x < getXSize(); x++) {
      // get adjacent cells for determining the next generation
      int count = countAdjacentCells(y, x);
      // IF ALIVE
      if (gol_matrix[y][x] == true) {
        if (count < 2) {
          row.push_back(false);
        }
        if (count == 2 || count == 3) {
          row.push_back(true);
        }
        if (count > 3) {
          row.push_back(false);
        }
      }
      // IF DEAD
      if (gol_matrix[y][x] == false) {
        if (count == 3)
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

// Counts adjacent cells of (y, x)
int Matrix::countAdjacentCells(int y, int x) {
  int count = 0;
  // UPPERLEFT
  if (y == 0 && x == 0) {
    if (gol_matrix[y + 1][x] == true)
      count++;
    if (gol_matrix[y + 1][x + 1] == true)
      count++;
    if (gol_matrix[y][x + 1] == true)
      count++;
    // LOWERRIGHT
  } else if (y == this->getYSize() - 1 && x == this->getXSize() - 1) {
    if (gol_matrix[y][x - 1] == true)
      count++;
    if (gol_matrix[y - 1][x - 1] == true)
      count++;
    if (gol_matrix[y - 1][x] == true)
      count++;
    // LOWERLEFT
  } else if (y == this->getYSize() - 1 && x == 0) {
    if (gol_matrix[y - 1][x] == true)
      count++;
    if (gol_matrix[y - 1][x + 1] == true)
      count++;
    if (gol_matrix[y][x + 1] == true)
      count++;
    // UPPERRIGHT
  } else if (y == 0 && x == this->getXSize() - 1) {
    if (gol_matrix[y][x - 1] == true)
      count++;
    if (gol_matrix[y + 1][x - 1] == true)
      count++;
    if (gol_matrix[y + 1][x] == true)
      count++;
    // IF FIRST LINE
  } else if (y == 0 && x != 0 && x != this->getXSize() - 1) {
    if (gol_matrix[y][x - 1] == true)
      count++;
    if (gol_matrix[y][x + 1] == true)
      count++;
    if (gol_matrix[y + 1][x] == true)
      count++;
    if (gol_matrix[y + 1][x + 1] == true)
      count++;
    if (gol_matrix[y + 1][x - 1] == true)
      count++;
    // IF LAST LINE
  } else if (y == this->getYSize() - 1 && x != 0 && x != this->getXSize() - 1) {
    if (gol_matrix[y][x - 1] == true)
      count++;
    if (gol_matrix[y][x + 1] == true)
      count++;
    if (gol_matrix[y - 1][x] == true)
      count++;
    if (gol_matrix[y - 1][x + 1] == true)
      count++;
    if (gol_matrix[y - 1][x - 1] == true)
      count++;
    // IF LEFT COLUMN
  } else if (x == 0 && y != 0 && y != this->getYSize() - 1) {
    if (gol_matrix[y - 1][x] == true)
      count++;
    if (gol_matrix[y - 1][x + 1] == true)
      count++;
    if (gol_matrix[y][x + 1] == true)
      count++;
    if (gol_matrix[y + 1][x + 1] == true)
      count++;
    if (gol_matrix[y + 1][x] == true)
      count++;
    // IF RIGHT COLUMN
  } else if (x == this->getXSize() - 1 && y != 0 && y != this->getYSize() - 1) {
    if (gol_matrix[y - 1][x] == true)
      count++;
    if (gol_matrix[y + 1][x] == true)
      count++;
    if (gol_matrix[y][x - 1] == true)
      count++;
    if (gol_matrix[y + 1][x - 1] == true)
      count++;
    if (gol_matrix[y - 1][x - 1] == true)
      count++;
    // IF ANYTHING ELSE
  } else {
    if (gol_matrix[y][x - 1] == true) {
      count++;
    }
    if (gol_matrix[y - 1][x - 1] == true) {
      count++;
    }
    if (gol_matrix[y - 1][x] == true) {
      count++;
    }
    if (gol_matrix[y - 1][x + 1] == true) {
      count++;
    }
    if (gol_matrix[y][x + 1] == true) {
      count++;
    }
    if (gol_matrix[y + 1][x + 1] == true) {
      count++;
    }
    if (gol_matrix[y + 1][x] == true) {
      count++;
    }
    if (gol_matrix[y + 1][x - 1] == true) {
      count++;
    }
  }
  return count;
}

std::vector<std::vector<bool> > Matrix::getMatrix() {
  return gol_matrix;
}
