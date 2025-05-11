#include "SudokuSolver.hpp"
#include "SudokuBoard.hpp"
#include <vector>
// Constructor initializes the board pointer
SudokuSolver::SudokuSolver(SudokuBoard& board) : board(&board) {}

// Public interface to solve the sudoku
bool SudokuSolver::solveSudoku() {
    return solve();
}

// Finds the next empty cell (0 represents empty)
bool SudokuSolver::findEmptyCell(int& row, int& col) const {
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (board->board[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

// Checks if a number can be placed at given position
bool SudokuSolver::isValid(int row, int col, int num) const {


    // Check row
    for (int c = 0; c < 9; c++) {
        if (board->board[row][c] == num) return false;
    }

    // Check column
    for (int r = 0; r < 9; r++) {
        if (board->board[r][col] == num) return false;
    }

    // Check 3x3 box
    int boxStartRow = row - row % 3;
    int boxStartCol = col - col % 3;
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (board->board[boxStartRow + r][boxStartCol + c] == num) return false;
        }
    }

    return true;
}

// Recursive backtracking solver
bool SudokuSolver::solve() {
    int row, col;

    // If no empty cell left, puzzle is solved
    if (!findEmptyCell(row, col)) {
        return true;
    }


    // Try digits 1-9
    for (int num = 1; num <= 9; num++) {
        if (isValid(row, col, num)) {
            // Try placing the number
            board->board[row][col] = num;

            // Recursively solve the rest
            if (solve()) {
                return true;
            }

            // If we get here, the placement didn't lead to a solution
            board->board[row][col] = 0; // Backtrack
        }
    }

    // Trigger backtracking
    return false;
}

