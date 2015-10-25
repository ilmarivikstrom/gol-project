#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>

class Matrix {
public:
    Matrix(int _xSize, int _ySize);
    Matrix();
    bool getCellState(int y, int x) const;
    int getXSize() const;
    int getYSize() const;
    void setCellState(int y, int x, bool state);
    void flipCellState(int y, int x);
    void randomMatrix();
    void updateMatrix();
    void clearMatrix();
    int countAdjacentCells(int y, int x);
    std::vector<std::vector<bool> > getMatrix();

private:
    int xSize;
    int ySize;
    std::vector<std::vector<bool> > gol_matrix;
};




#endif
