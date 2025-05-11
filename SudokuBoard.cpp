#include <iostream>
#include <cmath>
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

void SudokuBoard::setCellValue(int r, int c, int val)
{
	board[r][c] = val;
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
void SudokuBoard::ValidateConstraints(int row, int col, int value)
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

void SudokuBoard::loadFile(string fileName)
{
	ifstream file(fileName);
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
	cout << "File written successfully." << endl;
}


void SudokuBoard::savePuzzletoFile(string fileName)
{
	ofstream file(fileName);

	if(!file)
	{
		cerr << "File doesn't exist!" << endl;
		return;
	}

	int character;
	for(int i = 0 ; i < constraint2; i++)
	{
		for(int j = 0; j < constraint2; j++)
		{
			character = board[i][j];
			if(j%3==0) file << " | ";
			file << character;
			file << " ";
		}
		if(i && i%3==0) file << " |\n-------------------------------------\n";
		else file << " |\n";
	}
	file.close();
	cout << "File written successfully." << endl;
}


bool SudokuBoard::checkRow(int& row, int& value)
{

	for(const auto& c : board[row])
	{
		if(c == value)
		{
			cout << "Element exists in the same row" << endl;
			return false;
		}
	}
	return true;
}


bool SudokuBoard::checkColumn(int& col, int& value)
{
	for(int i=0 ; i<constraint2; i++)
	{
		if(value == board[i][col])
		{
			cout << "Element exists in the same column" << endl;
			return false;
		}
	}
	return true;
}

void SudokuBoard::printBox(int&r, int& c)
{
	for(int i = r-1; i < r+2 ; i++)
	{
		for(int j = c; j < c+3; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

bool SudokuBoard::checkBox(int& row, int& col, int& value) {
	int boxStartRow = (row / 3) * 3;  // 0, 3, or 6
	int boxStartCol = (col / 3) * 3;  // 0, 3, or 6

	for(int i = boxStartRow; i < boxStartRow + 3; i++) {
		for(int j = boxStartCol; j < boxStartCol + 3; j++) {
			if(value == board[i][j]) {
				cout << "Element exists in the same box" << endl;
				return false;
			}
		}
	}
	return true;
}

bool SudokuBoard::validateMove(int r, int c, int val)
{
	return checkBox(r,c,val) && checkRow(r,val) && checkColumn(c,val);
}

SudokuBoard& SudokuBoard::operator=(const SudokuBoard& sb)
{
	if(this != &sb)
	{
		board = sb.getBoard();
	}
	return *this;
}

