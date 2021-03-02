#pragma once

class TicTacToe
{
public:
	enum Verdict {
		USER_WINS,
		USER_LOSES,
		NEITHER
	};
	// init gameBoard to 0
	TicTacToe();
	
	// run game loop
	void run();

	// set all cells in board to value
	void setBoardTo(bool value);

	// write AI move to board
	void makeAIMove();

	// write board on screen, indented by space
	void drawBoardOnScreen(int space);

	// outputs whether user wins, loses, or neither is true
	Verdict checkVerdict();

private:
	bool gameBoard[3][3];

};
