#include <iostream>
#include <fstream>
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


const vector<vector<int>>& SudokuBoard::getBoard(void) const
		{
	return board;
		}

void SudokuBoard::setBoard(vector<vector<int>> &board)
{
	this->board = board;
}

void SudokuBoard::PrintBoard(void) const
{
	for(int i = 0; i < constraint2; i++)
	{
		for(int j = 0; j < constraint2; j++)
		{
			if(board[i][j] == 0) cout << '.' << " ";
			else cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
void SudokuBoard::ValidateConstraints(int &row, int &col, int& value)
{
	if(row > constraint2 || row < constraint1)
	{
		try{
			throw OutOfBoundsConstraint();
		}
		catch(exception& e)
		{
			cout << "Caught Exception: " << e.what() << endl;
			cout << "Row must be between 1 and 9.\n";
		}
	}
	if(col > constraint2 || col < constraint1)
	{
		try{
			throw OutOfBoundsConstraint();
		}
		catch(exception& e)
		{
			cout << "Caught Exception: " << e.what() << endl;
			cout << "Column must be between 1 and 9.\n";
		}
	}
	if(value > constraint2 || value < constraint1)
	{
		try{
			throw OutOfBoundsConstraint();
		}
		catch(exception& e)
		{
			cout << "Caught Exception: " << e.what() << endl;
			cout << "Value must be between 1 and 9.\n";
		}
	}
}

void SudokuBoard::loadFile(string s)
{
	ifstream file(s);
	if(!file)
	{
		cerr << "File doesn't exist!" << endl;
		return;
	}
	int character;
	for (int row = 0; row < constraint2; ++row)
	{
		for (int col = 0; col < constraint2; ++col)
		{
			if (!(file >> character)) {
				cerr << "File does not contain enough values." << endl;
				return;
			}
			board[row][col] = character;
		}
	}
	file.close();
}

SudokuBoard& SudokuBoard::operator=(const SudokuBoard& sb)
{
	if(this != &sb)
	{
		board = sb.getBoard();
	}
	return *this;
}

