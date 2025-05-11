#include <iostream>
#include "SudokuBoard.hpp"
#include "SudokuGame.hpp"
#include "SudokuSolver.hpp"
#include <vector>
using namespace std;

int main()
{
	vector<vector<int>> board = {
	    {5, 3, 0, 0, 7, 0, 0, 0, 0},
	    {6, 0, 0, 1, 9, 5, 0, 0, 0},
	    {0, 9, 8, 0, 0, 0, 0, 6, 0},

	    {8, 0, 0, 0, 6, 0, 0, 0, 3},
	    {4, 0, 0, 8, 0, 3, 0, 0, 1},
	    {7, 0, 0, 0, 2, 0, 0, 0, 6},

	    {0, 6, 0, 0, 0, 0, 2, 8, 0},
	    {0, 0, 0, 4, 1, 9, 0, 0, 5},
	    {0, 0, 0, 0, 8, 0, 0, 7, 9}
	};

    SudokuBoard s(board);
    SudokuGame Game(s);
    SudokuSolver Solver();
    Game.gameLoop();
}
