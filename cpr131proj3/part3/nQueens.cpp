#include "nQueens.h"
#include "input.h"
#include <iostream>
#include <string>
using namespace std;

nQueens::nQueens()
{
	dimensions = 0;
	boardPtr = nullptr;
}
void nQueens::initiateGame()
{
	dimensions = inputInteger("Enter the board's dimensions ", true);
	int d2 = dimensions;
	boardPtr = new char*[dimensions];
	for (int i = 0; i < dimensions; i++)
		boardPtr[i] = new char[dimensions];
	for (int i = 0; i < dimensions; i++) {
		for (int j = 0; j < dimensions; j++) {

			
			boardPtr[i][j] = ' ';
		}
	}
}
void nQueens::displayBoard()
{
	
	for (int i = 0; i < dimensions; i++) {
		for (int j = 0; j < dimensions; j++) {


			cout << '|' << boardPtr[i][j];
		}
		cout << '|'<<'\n';
	}
}
void nQueens::addQueen()
{
	int pos1, pos2;
	pos1 = inputInteger("\nPlease enter the desired row: ",1 , dimensions)-1;
	pos2 = inputInteger("\nPlease enter the desired column: ", 1, dimensions)-1;
	boardPtr[pos1][pos2]= 'Q';
}
