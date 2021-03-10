// Date: 02-23-21
// Description: n-Queens implementation
//

#include "nQueens.h"
#include "../input.h"
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

nQueens::nQueens()
{
	dimensions = 0;
	boardPtr = NULL;
	timePtr = NULL;
	queens = 0;
	moves = 0;
	initialTime = 0.0;
	sizeOftimeStrg = 25;
}
nQueens::~nQueens()
{

	for (int i = 0; i < dimensions; i++)
		delete[] boardPtr[i];
	delete[] boardPtr;

	for (int i = 0; i < 5; i++)
	{
		delete[] timePtr[i];
	}
	delete[] timePtr;

}
int nQueens::getQueens()
{
	return queens;
}
int nQueens::getDimensions()
{
	return dimensions;
}
int nQueens::getMoves()
{
	return moves;
}

void nQueens::setQueens(int newQueenQuantity)
{
	queens = newQueenQuantity;
}
void nQueens::setDimensions(int newDimension)
{
	dimensions = newDimension;
}
void nQueens::setMoves(int newMoveQuantity)
{
	moves = newMoveQuantity;
}

void nQueens::initiateGame()
{

	dimensions = inputInteger("Enter the board's dimensions: ", true);
	int d2 = dimensions;
	boardPtr = new char* [dimensions];
	for (int i = 0; i < dimensions; i++)
	{
		boardPtr[i] = new char[dimensions];
	}
	for (int i = 0; i < dimensions; i++)
	{
		for (int j = 0; j < dimensions; j++)
		{
			boardPtr[i][j] = ' ';
		}
	}

}
void nQueens::initTimer()
{
	if (initialTime == 0.0) {
		if (dimensions > sizeOftimeStrg)
		{
			sizeOftimeStrg = sizeOftimeStrg + dimensions;
		}
		initialTime = time(0);
		timePtr = new long* [5];
		for (int i = 0; i < 5; i++)
		{
			timePtr[i] = new long[sizeOftimeStrg];
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < sizeOftimeStrg; j++)
			{
				timePtr[i][j] = 0;
			}
		}
		/*for (int i = 0; i < 4; i++) code used for testing.
		{
			cout << '\n';
			for (int j = 0; j < sizeOftimeStrg; j++)
			{
				cout << timePtr[i][j] << ' ';
			}
		}*/
	}
	else if (initialTime != 0.0 && sizeOftimeStrg < dimensions)
	{
		initialTime = time(0);
		int oldSize = sizeOftimeStrg;
		sizeOftimeStrg = sizeOftimeStrg + dimensions;
		long** tempPtr = timePtr;
		timePtr = new long* [5];
		for (int i = 0; i < 5; i++)
		{
			timePtr[i] = new long[sizeOftimeStrg];
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < oldSize; j++)
			{
				timePtr[i][j] = tempPtr[i][j];
			}
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = oldSize; j < sizeOftimeStrg; j++)
			{
				timePtr[i][j] = 0;
			}
		}
		for (int i = 0; i < 5; i++)
		{
			delete[] tempPtr[i];
		}
		delete[] tempPtr;
	}
	else if (initialTime != 0.0 && sizeOftimeStrg > dimensions)
	{
		initialTime = time(0);
	}
}
void nQueens::timerGrab()
{
	long timeHolder = time(0);
	timeHolder = timeHolder - initialTime;
	if (timePtr[0][dimensions] == 0.0)
	{
		timePtr[0][dimensions] = timePtr[0][dimensions] + 1.0;
		timePtr[1][dimensions] = timeHolder;
		timePtr[2][dimensions] = timeHolder;
		timePtr[3][dimensions] = moves;
		timePtr[4][dimensions] = moves;
		return;
	}
	if (timePtr[0][dimensions] != 0)
	{
		timePtr[0][dimensions] = timePtr[0][dimensions] + 1;
		if (timePtr[1][dimensions] > timeHolder)
		{
			timePtr[1][dimensions] = timeHolder;
			timePtr[3][dimensions] = moves;
			return;
		}
		if (timePtr[2][dimensions] < timeHolder)
		{
			timePtr[2][dimensions] = timeHolder;
			timePtr[4][dimensions] = moves;
			return;
		}

	};
}
void nQueens::displayBoard() const
{
	cout << dimensions << " Queens\n";
	cout << char(201) << string((dimensions * 2 - 1), char(205)) << char(187) << "\n";
	for (int i = 0; i < dimensions; i++)
	{
		cout << char(186);
		for (int j = 0; j < dimensions; j++)
		{
			if (j != 0)
				cout << char(179) << boardPtr[i][j];
			else
				cout << boardPtr[i][j];
		}
		cout << char(186) << '\n';
	}
	cout << char(200) << string((dimensions * 2 - 1), char(205)) << char(188) << "\n";
}
void nQueens::dispTimes() const
{
	bool data = false;
	cout << "\tGame statistics\n\n";
	for (int i = 0; i < sizeOftimeStrg; i++)
	{
		if (timePtr[0][i] != 0)
		{
			data = true;
			cout << '\n' << timePtr[0][i] << " Games using " << i << " queens were played \n";
			cout << "\tThe fastest time was " << timePtr[1][i] << " seconds in " << timePtr[3][i] << " moves \n";
			cout << "\tThe slowest time was " << timePtr[2][i] << " seconds in " << timePtr[4][i] << " moves \n";
		}
	}
	if (!data)
	{
		cout << "\tNo game data collected!\n";
	}
	return;
}
void nQueens::addQueen()
{

	int pos1, pos2;
	pos1 = inputInteger("\nPlease enter the desired row: ", 1, dimensions) - 1;
	pos2 = inputInteger("\nPlease enter the desired column: ", 1, dimensions) - 1;
	if (occupiedCheck(pos1, pos2))
	{
		cout << "\nThat space is occupied!\n";
		return;
	}
	if (verticalCheck(pos1, pos2))
	{
		cout << "\nThere is a queen in that column!\n";
		return;
	}
	if (horizantalCheck(pos1, pos2))
	{
		cout << "\nThere is a queen in that row!\n";
		return;
	}
	if (diagonalCheck(pos1, pos2))
	{
		cout << "\nThere is a queen on a diagonal from that point!\n";
		return;
	}
	boardPtr[pos1][pos2] = 'Q';
	moves++;
	queens++;

}

void nQueens::removeQueen()
{
	int pos1, pos2;
	pos1 = inputInteger("\nPlease enter the row of the queen: ", 1, dimensions) - 1;
	pos2 = inputInteger("\nPlease enter the column of the queen: ", 1, dimensions) - 1;
	if (!occupiedCheck(pos1, pos2))
	{
		cout << "\nThere is no queen at that position!\n";
		return;
	}
	else
	{
		boardPtr[pos1][pos2] = ' ';
		cout << "\nQueen removed!\n";
		moves++;
		queens--;
		return;
	}

}

bool nQueens::occupiedCheck(int pos1, int pos2)
{
	if (boardPtr[pos1][pos2] == 'Q')
		return true;
	else
		return false;
}

bool nQueens::diagonalCheck(int pos1, int pos2)
{
	for (int row = pos1, colomn = pos2; row < dimensions && colomn < dimensions; row++, colomn++)
	{
		if (boardPtr[row][colomn] == 'Q')
		{
			return true;
		}
	}
	for (int row = pos1, colomn = pos2; row >= 0 && colomn >= 0; row--, colomn--)
	{
		if (boardPtr[row][colomn] == 'Q')
		{
			return true;
		}
	}
	for (int row = pos1, colomn = pos2; row < dimensions && colomn >= 0; row++, colomn--)
	{
		if (boardPtr[row][colomn] == 'Q')
		{
			return true;
		}
	}
	for (int row = pos1, colomn = pos2; row >= 0 && colomn < dimensions; row--, colomn++)
	{
		if (boardPtr[row][colomn] == 'Q')
		{
			return true;
		}
	}
	return false;
}

bool nQueens::horizantalCheck(int pos1, int pos2)
{
	for (int colomn = 0; colomn < dimensions; colomn++)
	{
		if (boardPtr[pos1][colomn] == 'Q')
		{
			return true;
		}
	}
	return false;
}

bool nQueens::verticalCheck(int pos1, int pos2)
{

	for (int row = 0; row < dimensions; row++)
	{
		if (boardPtr[row][pos2] == 'Q')
		{
			return true;
		}
	}
	return false;
}

char nQueens::resetGame()
{
	//	char** tempPtr = boardPtr; destructor handles resetting, no longer using these lines
	//	boardPtr = NULL;
	queens = 0;
	moves = 0;
	char yes = 'y';
	char no = 'n';
	/*for (int i = 0; i < dimensions; i++)
		delete[] tempPtr[i];
	delete[] tempPtr;*/
	char choice = inputChar("\nwould you like to play again? yes or no:", yes, no);

	return choice;
}

bool nQueens::winCheck() const
{

	if (queens == dimensions)
	{
		return true;
	}
	return false;
}
