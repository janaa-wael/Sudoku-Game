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
        vector<vector<int>> getBoard(void);
        void setBoard(vector<vector<int>> &board);
        void EnterBoardValues(void);
        void PrintBoard(void);
        void ValidateConstraints(int &constraint);
};
