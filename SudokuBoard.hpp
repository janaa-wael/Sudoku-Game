#ifndef SUDOKU_BOARD_HPP
#define SUDOKU_BOARD_HPP

#include <iostream>
#include <vector>
using namespace std;


class SudokuBoard{
    private:
        const int constraint1 = 1;
        const int constraint2 = 9;
        vector<vector<int>> board;
    public:
        SudokuBoard(); //default constructor
        SudokuBoard(vector<vector<int>>& v); //parametrized constructor
        const vector<vector<int>>& getBoard(void) const;
        void setBoard(vector<vector<int>> &board);
        void PrintBoard(void) const;
        void ValidateConstraints(int &row, int& col, int& value);
        void loadFile(string s);
        void savePuzzletoFile(string fileName);
        SudokuBoard& operator=(const SudokuBoard& sb);


};

#endif
