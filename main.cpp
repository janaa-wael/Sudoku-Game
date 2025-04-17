#include <iostream>
#include "SudokuBoard.hpp"
#include "SudokuGame.hpp"
#include "SudokuSolver.hpp"
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> board(9, std::vector<int>(9, 0));
    SudokuBoard* s = new SudokuBoard(board);
    s->PrintBoard();
}