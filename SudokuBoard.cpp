#include <iostream>
#include "OutOfBoundsConstraint.hpp"
#include "SudokuBoard.hpp"
using namespace std;

SudokuBoard::SudokuBoard() //default constructor
{
    board = std::vector<std::vector<int>>(9, std::vector<int>(9, 0));
}

SudokuBoard::SudokuBoard(vector<vector<int>>& v) //parametrized constructor
: board(v)
{

}

vector<vector<int>> SudokuBoard::getBoard(void)
{
    return board;
}
void SudokuBoard::setBoard(vector<vector<int>> &board)
{
    this->board = board;
}

void SudokuBoard::PrintBoard(void)
{
    for(int i = 0; i < constraint1; i++)
    {
        for(int j = 0; j < constraint2; j++)
        {   
            if(board[i][j] == 0) cout << '.' << " ";
            else cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
void SudokuBoard::ValidateConstraints(int &constraint)
{
    if(constraint > constraint2 || constraint < constraint1)
    {
        try{
            throw OutOfBoundsConstraint();
        }
        catch(exception& e)
        {
            cout << "Caut Exception: " << e.what() << endl;
        }
    }
}

void SudokuBoard::EnterBoardValues(void)
{
    for(int i=0; i<constraint1; i++)
    {
        for(int j=0; j<constraint2; j++)
        {
            cin >> board[i][j];
        }
    }
}
