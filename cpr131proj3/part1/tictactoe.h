//Participants: Long Doung, Lincoln Nguyen, Christopher Gomez
//date: 3/9/2021
//Description: headerfile for tictactoe.h

#pragma once
class TicTacToe
{
private:
	char boardSlots[3][3];
	char computer;
	char player;
	char gameStat;
	int moveCounter;					                        //count up to 9 in order to determine a draw

public:
	//Preconditions: N/A
	//Postconditions: creates a default tictactoe object
	TicTacToe();						
	//Preconditions: A tictactoe object
	//Postconditions: displays the board
	void displayBoard();				                       //Update after each move
	//Preconditions: a tictactoe objectr
	//Postconditions: resets the board to a blank grid
	void resetBoard();					                       //Reset the board
	//Preconditions: game is running and the user entered some moves
	//Postconditions: sets a spot on the board to X					
	void playerMove(int row, int col);                         //User make a move
	//Preconditions:a tictactoe object
	//Postconditions:returns the amount of moves 
	int getMoveCounter();                                       //access moveCounter
	//Preconditions: the game is running and both the computer and player have moved
	//Postconditions: returns X upon player win, O upon computer win, D upon draw, and N if none apply
	char gameCheck();			                                // wrap the 3 bools underneath to check for winners
	//Preconditions: the game is running
	//Postconditions: returns true if the player got 3 X's in a row
	bool didUserWin();				                            // return T/F
	//Preconditions: the game is running
	//Postconditions: returns true if the computer got 3 O's in a row
	bool didComputerWin();			                            // return T/F
	//Preconditions: the game is running
	//Postconditions: returns true if all moves are done and there are no winners.
	bool isTie();					                            // return T/f
	//Preconditions: The game is running, and the user input a move
	//Postconditions: returns true if a spot is occupied by anything but a ' ', false if not
	bool occupiedCheck(int pos1, int pos2);

};
//Preconditions: The main project program calls this function
//Postconditions: a game of tictactoe will start and be driven by this function

void tictactoeStarter();



