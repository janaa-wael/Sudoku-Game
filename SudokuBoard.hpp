#ifndef SUDOKU_BOARD_HPP
#define SUDOKU_BOARD_HPP

#include <iostream>
#include <vector>
using namespace std;


class SudokuBoard{
    private:
        const int constraint1 = 1;
        const int constraint2 = 9;

    public:
        vector<vector<int>> board;
        SudokuBoard(); //default constructor
        SudokuBoard(vector<vector<int>>& v); //parametrized constructor
        void setCellValue(int r, int c, int val);
        const vector<vector<int>>& getBoard(void) const;
        const vector<vector<int>>& getBoard(void);
        void setBoard(vector<vector<int>> &board);
        void PrintBoard(void) const;
        void ValidateConstraints(int row, int col, int value);
        void loadFile(string s);
        void savePuzzletoFile(string fileName);
        bool checkRow(int& row, int& value);
        bool checkColumn(int& col, int& value);
        bool checkBox(int& row, int& col, int& value);
        bool validateMove(int r, int c, int val);
        SudokuBoard& operator=(const SudokuBoard& sb);
        void printBox(int&r, int& c);


};

#endif
