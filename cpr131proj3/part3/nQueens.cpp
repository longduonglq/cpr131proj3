#include "nQueens.h"
#include "input.h"
#include <iostream>
#include <string>
using namespace std;

nQueens::nQueens()
{
	dimensions = 0;
	boardPtr = nullptr;
	queens = 0;
}
void nQueens::initiateGame()
{
	dimensions = inputInteger("Enter the board's dimensions ", true);
	int d2 = dimensions;
	boardPtr = new char* [dimensions];
	for (int i = 0; i < dimensions; i++)
		boardPtr[i] = new char[dimensions];
	for (int i = 0; i < dimensions; i++) {
		for (int j = 0; j < dimensions; j++) {
			boardPtr[i][j] = ' ';
		}
	}
}
void nQueens::displayBoard() const
{

	for (int i = 0; i < dimensions; i++) {
		for (int j = 0; j < dimensions; j++) {


			cout << '|' << boardPtr[i][j];
		}
		cout << '|' << '\n';
	}
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
		cout << "\nThere is a queen in that colomn!\n";
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
	queens++;
	return;
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
	char** tempPtr = boardPtr;
	boardPtr = nullptr;
	queens = 0;
	char yes = 'y';
	char no = 'n';
	for (int i = 0; i < dimensions; i++) {

		delete[] tempPtr[i];
	}
	delete[] tempPtr;
	char choice = inputChar("\nwould you like to play again? yes or no:", yes, no);
	if (choice == 'y') {
		initiateGame();
		return choice;
	}
}
bool nQueens::winCheck() const
{

	if (queens == dimensions)
	{
		return true;
	}
	return false;
}
