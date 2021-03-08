#include "tictactoe.h"
#include <iostream>
using namespace std;

TicTacToe::TicTacToe()
{
	computer = 'O';
	player = 'X';


	for (int i = 0; i < 3; i++)   //initiate the boardslot to all spaces
	{
		for (int j = 0; j < 3; j++)
		{
			boardSlots[i][j] = ' ';
		}
	}
}

void TicTacToe::run()
{
	int row;
	int col;
	TicTacToe test1;

	cout << "Tic-Tac-Toe" << endl;
	test1.displayBoard();




	do
	{
		cout << "Enter the board's row # (1..3) or 0 to forfeit: " << endl;
		cin >> row;
		if (row == 0)
		{
			break;
		}

		cout << "Enter the board's column # (1..3) or 0 to forfeit: " << endl;
		cin >> col;
		if (col == 0)
		{
			break;
		}

		test1.playerMove(row, col);				//this is where the player will input into the 2d array 

		test1.displayBoard();					//Update after each move
	} while (true);

	return ;
}

//void TicTacToe::initBoard() //useless, only meant to see the board at the beginning 
//{
//	// Upper outline
//	cout << char(201) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(187) << endl;
//
//	// Second row of outline
//	cout << char(186) << " " << "1" << " " << char(186) << " " << "2" << " " << char(186) << " " << "3" << " " << char(186) << endl;
//	cout << char(204) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(185) << endl;
//
//	// Third row of outline
//	cout << char(186) << " " << "4" << " " << char(186) << " " << "5" << " " << char(186) << " " << "6" << " " << char(186) << endl;
//	cout << char(204) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(185) << endl;
//
//	// Lower outline
//	cout << char(186) << " " << "7" << " " << char(186) << " " << "8" << " " << char(186) << " " << "9" << " " << char(186) << endl;
//	cout << char(200) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(188) << endl;
//
//}

void TicTacToe::playerMove(int row, int col)
{
	boardSlots[row - 1][col - 1] = 'X';
}

void TicTacToe::displayBoard()
{
	// Upper outline
	cout << char(201) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(203) << char(205) << char(205) << char(205) << char(187) << endl;

	// Second row of outline
	cout << char(186) << " " << boardSlots[0][0] << " " << char(186) << " " << boardSlots[0][1] << " " << char(186) << " " << boardSlots[0][2] << " " << char(186) << endl;
	cout << char(204) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(185) << endl;

	// Third row of outline
	cout << char(186) << " " << boardSlots[1][0] << " " << char(186) << " " << boardSlots[1][1] << " " << char(186) << " " << boardSlots[1][2] << " " << char(186) << endl;
	cout << char(204) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(206) << char(205) << char(205) << char(205) << char(185) << endl;

	// Lower outline
	cout << char(186) << " " << boardSlots[2][0] << " " << char(186) << " " << boardSlots[2][1] << " " << char(186) << " " << boardSlots[2][2] << " " << char(186) << endl;
	cout << char(200) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(202) << char(205) << char(205) << char(205) << char(188) << endl;
}


void TicTacToe::resetBoard() // reset the board
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			boardSlots[i][j] = ' ';
		}
	}
}

void tictactoeStarter()
{
	auto ttt = TicTacToe();
	ttt.run();
	return;
}
