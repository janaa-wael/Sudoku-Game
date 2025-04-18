#ifndef SUDOKU_GAME_HPP
#define SUDOKU_GAME_HPP


#include <iostream>
#include "SudokuBoard.hpp"

using namespace std;

class SudokuGame{
	private:
		SudokuBoard sudokuBoard;
		int menuChoice;
		int rowChoice;
		int colChoice;
		int inputCellValue;
		string inputFile;
		string outputFile;
	public:
		SudokuGame();
		SudokuGame(SudokuBoard sudokuBoard);
		void printMenu();
		void getUserBoardInput(void);
		void getUserMenuInput(void);
		void gameLoop(void);
};

#endif
