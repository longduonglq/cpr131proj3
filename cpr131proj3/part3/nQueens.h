// Participants: Andrew Thompson and Gabriela Lopez
// Date: 02-23-21
// Description: n-Queens header

#pragma once

class nQueens
{
private:
	char** boardPtr;
	size_t dimensions;
	int queens;
	int moves;
	long** timePtr;
	long initialTime;
	size_t sizeOftimeStrg;
public:
	//Precondition: declare a queen object
	//Postcondition: initializes all variables
	nQueens();
	//Precondition: N/a
	//Postcondition: destructor for queen objects.
	~nQueens();
	//Precondition: N/A
	//Postcondition: returns the number of queens placed in the board
	int getQueens();

	//Precondition: N/A
	//Postcondition: returns the size of the board nxn
	int getDimensions();

	//Precondition: N/A
	//Postcondition: returns the number of moves done in the match
	int getMoves();

	//Precondition: an int number of queens
	//Postcondition: sets a new balue of queens
	void setQueens(int newQueenQuantity);

	//Precondition: an int number for new board dimension
	//Postcondition: sets the new board dimension
	void setDimensions(int newDimension);

	//Precondition: an int number of movements
	//Postcondition: sets a number of movements
	void setMoves(int newMoveQuantity);

	/*nQueens(size_t dimensions);*/
	void initiateGame(); //asks for size, and creates a new array 2 dimensional array to those standards, and assigns board pointer to it

	//Precondition: N/A
	//Postcondition: ask user where they want a queen and does all the validations to check if there is a queen in the spot they have chosen,
	//adds queen to board
	void addQueen();

	//Precondition: N/A
	//Postcondition: ask user where is the queen they want to remove and validates the existence of it, removes queen
	void removeQueen();

	//Precondition: N/A
	//Postcondition: prints board
	void displayBoard() const;

	//Precondition: int numbers of row position and column position
	//Postcondition: checks if there is a queen in the position selected
	bool occupiedCheck(int pos1, int pos2);							//pos1=row pos2 = colunm

	//Precondition: int numbers of row position and column position
	//Postcondition: checks horizontally if there is a queen in the position selected
	bool horizantalCheck(int pos1, int pos2);

	//Precondition: int numbers of row position and column position
	//Postcondition: checks diagonally if there is a queen in the position selected
	bool diagonalCheck(int pos1, int pos2);

	//Precondition: int numbers of row position and column position
	//Postcondition: checks vertically if there is a queen in the position selected
	bool verticalCheck(int pos1, int pos2);

	//Precondition: N/A
	//Postcondition: game has been won, resets all variables, releases dynamic memory used and ask user to play again
	char resetGame();

	//Precondition: N/A
	//Postcondition: compares the number of queens in board and the dimension, if both are equal the game finishes
	bool winCheck() const;
	//Preconditions: a nQueens object has been created
	//Postconditions: creates a storage object for game data, as well as keeping track of the time when a new game starts
	void initTimer();
	//Preconditions: A game of n-queens has been started, and the user selects no for continue
	//postconditions: displays all game time data from that session of play for all n-size boards, or displays a message if there was no data stored.
	void dispTimes() const;
	//Preconditions: A game of n-queens has been started, and the user selects no for continue
	//postconditions: displays all game time data from that session of play for all n-size boards, or displays a message if there was no data stored.
	void timerGrab();
};

