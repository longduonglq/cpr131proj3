#pragma once

#include "ai.h"

class TicTacToe
{
private:
	char boardSlots[3][3];
	char computer;
	char player;

public:
	TicTacToe();						//default constructor
	void run();
	//void initBoard();					//Initate the board only to show the numbers
	void displayBoard();				//Update after each move
	void resetBoard();					//Reset the board
	char checkBoard();				    //Check for possible win/lose/draw
	void compMove();				    //Computer make a move
	void playerMove(int row, int col);  //User make a move

};

void tictactoeStarter();
