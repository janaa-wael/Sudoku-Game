#ifndef SUDOKU_SOLVER
#define SUDOKU_SOLVER

#include "SudokuBoard.hpp"
class SudokuSolver{
private:
	SudokuBoard* board;
public:
	SudokuSolver(SudokuBoard& board);
	bool isValid(int row, int col, int num) const;
	bool findEmptyCell(int& row, int& col) const;
	bool solve();
	bool solveSudoku();

};

#endif
