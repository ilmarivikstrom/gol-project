#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>

class Matrix
{
	public:
		Matrix(int _xSize, int _ySize);
		Matrix();
		bool getCellState(int x, int y) const;
		int getXSize() const;
		int getYSize() const;
		void setCellState(int x, int y, bool state);
		void flipCellState(int x, int y);
		void updateMatrix();
		void clearMatrix();
		void countAdjacentCells(int x, int y);
		std::vector<std::vector<bool> > getMatrix();
		
	private:
		int xSize;
		int ySize;
		std::vector<std::vector<bool> > gol_matrix;
};




#endif