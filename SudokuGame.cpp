#include <iostream>
#include "SudokuGame.hpp"
#include "SudokuBoard.hpp"
#include "SudokuSolver.hpp"

using namespace std;

SudokuGame::SudokuGame()
: sudokuBoard()
{
}

SudokuGame::SudokuGame(SudokuBoard sudokuBoard)
: sudokuBoard(sudokuBoard)
{

}


void SudokuGame::printMenu()
{
	cout << "1) Enter a move\n2) Solve automatically\n3) Load puzzle from file\n";
	cout << "4) Save current puzzle to file\n5) Exit\n";
}

void SudokuGame::getUserMenuInput(void)
{
	cout << "Choice: ";
	cin >> menuChoice;
}

void SudokuGame::getUserBoardInput(void)
{
	cout << "Enter row (1-9), column (1-9), and value (1-9): ";
	cin >> rowChoice >> colChoice >> inputCellValue;
	sudokuBoard.ValidateConstraints(rowChoice, colChoice, inputCellValue);
}

void SudokuGame::gameLoop(void)
{
	while(1)
	{
		SudokuSolver s(sudokuBoard);
		sudokuBoard.PrintBoard();
		printMenu();
		getUserMenuInput();
		switch(menuChoice)
		{
		case 1:
			getUserBoardInput();
			sudokuBoard.ValidateConstraints(rowChoice, colChoice, inputCellValue);

			if(sudokuBoard.validateMove(rowChoice-1, colChoice-1, inputCellValue)) sudokuBoard.setCellValue(rowChoice-1, colChoice-1, inputCellValue);
			else cout << "Invalid move." << endl;
			break;
		case 2:
			//solve puzzle automatically

			s.solve();
			printMenu();
			break;
		case 3:
			//load puzzle from file
			cout << "Enter File Name" << endl;
			cin >> inputFile;
			sudokuBoard.loadFile(inputFile);
			break;
		case 4:
			cout << "Enter File Name" << endl;
			cin >> outputFile;
			sudokuBoard.savePuzzletoFile(outputFile);
			break;
		case 5:
			break;
		default:
			break;
		}

		// check input validity
	}
}
