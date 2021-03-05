#pragma once

#include "../Timer.h"

class TicTacToe
{
public:
	enum Verdict {
		USER_WINS,
		USER_LOSES,
		IN_PROGRESS
	};
	enum PIXEL : char {
		PLAYER = 'o',
		COMPUTER = 'x',
		EMPTY = ' '
	};

	// init gameBoard to 0
	TicTacToe();
	
	// run game loop
	void run();

	// set all cells in board to value
	void setBoardTo(char value);

	// write AI move to board
	void makeAIMove();

	// write board on screen, indented by space
	void drawBoardOnScreen(int space);

	// outputs whether user wins, loses, or neither is true
	Verdict checkVerdict();

	// add user move into gameBoard
	void addUserMove(int row, int col);

	// reset to prepare for new game
	void resetGame();

private:
	char gameBoard[3][3];
	Timer timer;
};
