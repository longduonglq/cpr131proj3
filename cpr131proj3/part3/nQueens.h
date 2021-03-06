#pragma once
class nQueens
{
private:
	char** boardPtr;
	size_t dimensions;
	int queens;
	int moves;
public:
	nQueens();
	int getQueens();

	int getDimensions();

	int getMoves();

	void setQueens(int newQueenQuantity);

	void setDimensions(int newDimension);

	void setMoves(int newMoveQuantity);
	
	/*nQueens(size_t dimensions);*/
	void initiateGame(); //asks for size, and creates a new array 2 dimensional array to those standards, and assigns board pointer to it
	void addQueen();
	void removeQueen();
	void displayBoard() const;
	bool occupiedCheck(int pos1, int pos2);							//pos1=row pos2 = colunm
	bool horizantalCheck(int pos1, int pos2);
	bool diagonalCheck(int pos1, int pos2);
	bool verticalCheck(int pos1, int pos2);
	char resetGame();
	bool winCheck() const;
};


