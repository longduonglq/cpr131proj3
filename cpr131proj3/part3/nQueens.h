#pragma once
class nQueens
{
private:
	char **boardPtr;
	size_t dimensions;
public:
	nQueens();
	/*nQueens(size_t dimensions);*/
	void initiateGame(); //asks for size, and creates a new array 2 dimensional array to those standards, and assigns board pointer to it
	void addQueen();
	void removeQueen();
	void displayBoard();
	bool horizantalCheck();
	bool diagonalCheck();
	bool verticalCheck();
	void gameDriver();
};

