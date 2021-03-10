#pragma once
class TicTacToe
{
private:
	char boardSlots[3][3];
	char computer;
	char player;
	char gameStat;
	int moveCounter;					//count up to 9 in order to determine a draw

public:
	TicTacToe();						//default constructor
	void displayBoard();				//Update after each move
	void resetBoard();					//Reset the board
	//char checkBoard();				    //Check for possible win/lose/draw 
	// char gameStatus();					//Check the status of the game
	void compMove();				    //Computer make a move (unused)
	void playerMove(int row, int col);  //User make a move

	//TODO: Lincoln 
	char gameCheck();			// wrap the 3 bools underneath to heck for winners
	bool didUserWin();				// return T/F
	bool didComputerWin();			// return T/F
	bool isTie();					// return T/f




	bool occupiedCheck(int pos1, int pos2);
	//void run();

	//void compMove(int row, int col); (Was used for testing)
};

void tictactoeStarter();



