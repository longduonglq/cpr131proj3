//Participants: Long Doung, Lincoln Nguyen, Christopher Gomez
//date: 3/9/2021
//Description: implementation file for tictactoe.h
#include "TicTacToe.h"
#include <iostream>
#include "../input.h"
#include "ai.h"
#include "../Timer/Timer.h"
using namespace std;

TicTacToe::TicTacToe()
{
	computer = 'O';
	player = 'X';
	gameStat = 'U';			//U for unfinished
	moveCounter = 0;


	for (int i = 0; i < 3; i++)   //initiate the boardslot to all spaces
	{
		for (int j = 0; j < 3; j++)
		{
			boardSlots[i][j] = ' ';
		}
	}
}

void TicTacToe::playerMove(int row, int col)
{
	boardSlots[row - 1][col - 1] = 'X';
	moveCounter++;
	cout << "move counter is: " << moveCounter << endl;
}

void TicTacToe::compMove() //This is player2, for testing purposes
{
	AI ai(boardSlots);
	auto bestMove = ai.getBestMove();
	if (bestMove.first < 0 || bestMove.second < 0)
	{
		moveCounter++;
		return;
	}
	boardSlots[bestMove.first][bestMove.second] = computer;
	moveCounter++;
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
	moveCounter = 0;
}

bool TicTacToe::didUserWin()
{
	return AI(boardSlots).didUserWin();
}
bool TicTacToe::didComputerWin()
{
	return AI(boardSlots).didSelfWin();
}

bool TicTacToe::isTie()
{
	if (moveCounter >= 9 && !didUserWin() && !didComputerWin())
		return true;
	else
		return false;
}
char TicTacToe::gameCheck()
{
	if (didUserWin())
		return 'X';
	else if (didComputerWin())
		return 'O';
	else if (isTie())
		return 'D';
	else
		return 'N';
}
bool TicTacToe::occupiedCheck(int pos1, int pos2)
{
	if (boardSlots[pos1 - 1][pos2 - 1] != ' ')
	{
		cout << "Position is already occupied" << endl;
		return true;
	}
	else
		return false;
}
int TicTacToe::getMoveCounter() {
	return moveCounter;
}
void tictactoeStarter()
{
	int row;
	int col;

	char playGame; //Continue play again yes or no
	char yes = 'y', no = 'n';
	TicTacToe board;
	char winCheck = 'N';
	cout << "Tic-Tac-Toe" << endl;
	board.displayBoard();

	Timer ticTacTimer;
	do
	{
		if (board.getMoveCounter() == 0) ticTacTimer.start();
		do
		{

			row = inputInteger("\nEnter the board's row # (1..3) or 0 to forfeit: ", 0, 3);
			if (row == 0)
			{
				break;
			}

			col = inputInteger("\nEnter the board's column # (1..3) or 0 to forfeit: ", 0, 3);
			if (col == 0)
			{
				break;
			}
		} while (board.occupiedCheck(row, col));

		char choice = '\0';

		if (row == 0 || col == 0)
		{
			break;
		}

		board.playerMove(row, col);				//<----this is where the player will input into the 2d array 
		board.displayBoard();
		winCheck = board.gameCheck();
		if (winCheck == 'X')
		{
			cout << "User Wins" << endl;
			board.displayBoard();
			choice = inputChar("Play again? (Y-yes or N-no): ", yes, no);
		}

		if (choice == '\0')
		{
			board.compMove();
			winCheck = board.gameCheck();
			if (winCheck == 'N')
				cout << "Computer moved!" << endl;
		}

		if (winCheck == 'O')
		{
			cout << "Computer Wins" << endl;
			board.displayBoard();
			choice = inputChar("Play again? (Y-yes or N-no): ", yes, no);
		}

		if (winCheck == 'D')
		{
			cout << "It's a Draw!" << endl;
			board.displayBoard();
			choice = inputChar("Play again? (Y-yes or N-no): ", yes, no);
		}

		if (choice == 'y')
		{
			board.resetBoard();
		}

		if (choice == 'n')
		{
			break;
		}

		board.displayBoard();


	} while (true);

	ticTacTimer.end();
	cout << "\n\n\tslowest time: " <<
		ticTacTimer.getSlowestMin() << " minutes " <<
		ticTacTimer.getSlowestSec() << " seconds\n\n";
	cout << "\n\tfastest time: " <<
		ticTacTimer.getFastestMin() << " minutes " <<
		ticTacTimer.getFastestSec() << " seconds\n\n";
	cout << "\taverage time: " <<
		ticTacTimer.getAverageMin() << " minutes " <<
		ticTacTimer.getAverageSec() << " seconds\n\n";
	return;
}


//char TicTacToe::gameStatus()
//{
//	char playGame; //Continue play again yes or no
//	char yes = 'y', no = 'n';
//
//	if (checkBoard() == 'X')			//<----This is where you check for winners/loser/draw
//	{
//		displayBoard();
//		cout << "Player wins!" << endl;
//		playGame = toupper(inputChar("Play again? (Y-yes or N-no): ", yes, no));
//		if (playGame == 'Y')
//		{
//			resetBoard();
//			displayBoard();
//		}
//		else
//		{
//			//break;
//			return 'u';
//		}
//	}
//	else if (checkBoard() == 'O')
//	{
//		displayBoard();
//		cout << "Computer wins!" << endl;
//		cout << "Play again? (Y-yes or N-no)" << endl;
//		cin >> playGame;
//		if (playGame == 'y')
//		{
//			resetBoard();
//			displayBoard();
//		}
//		else
//		{
//			//break;
//			return 'u';
//		}
//	}
//	else if (checkBoard() == 'D')
//	{
//		displayBoard();
//		cout << "It is a Draw!" << endl;
//		cout << "Play again? (Y-yes or N-no)" << endl;
//		cin >> playGame;
//		if (playGame == 'Y')
//		{
//			resetBoard();
//			displayBoard();
//		}
//		else
//		{
//			//break;
//			return 'u';
//		}
//	}
//	else
//	{
//		displayBoard();
//	}
//}
