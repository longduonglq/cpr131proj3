#include "TicTacToe.h"
#include <iostream>
#include "input.h"
#include "ai.h"
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

void TicTacToe::compMove(int row, int col) //This is player2, for testing purposes
{
	boardSlots[row - 1][col - 1] = 'O';
	moveCounter++;
	cout << "move counter is: " << moveCounter << endl;
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
	return false;
}

char TicTacToe::checkBoard()  //Check for possible win/lose/draw
{
	//checking XXX for each rows
	if (boardSlots[0][0] == 'X' && boardSlots[0][1] == 'X' && boardSlots[0][2] == 'X')
		return 'X';
	else if (boardSlots[1][0] == 'X' && boardSlots[1][1] == 'X' && boardSlots[1][2] == 'X')
		return 'X';
	else if (boardSlots[2][0] == 'X' && boardSlots[2][1] == 'X' && boardSlots[2][2] == 'X')
		return 'X';

	//checking XXX for each col
	else if (boardSlots[0][0] == 'X' && boardSlots[1][0] == 'X' && boardSlots[2][0] == 'X')
		return 'X';
	else if (boardSlots[0][1] == 'X' && boardSlots[1][1] == 'X' && boardSlots[2][1] == 'X')
		return 'X';
	else if (boardSlots[0][2] == 'X' && boardSlots[1][2] == 'X' && boardSlots[2][2] == 'X')
		return 'X';

	//checking XXX for the diagonals
	else if (boardSlots[0][0] == 'X' && boardSlots[1][1] == 'X' && boardSlots[2][2] == 'X')
		return 'X';
	else if (boardSlots[0][2] == 'X' && boardSlots[1][1] == 'X' && boardSlots[2][0] == 'X')
		return 'X';

	//-----------------------------------------------------------------------------------//

	//checking OOO for each rows
	else if (boardSlots[0][0] == 'O' && boardSlots[0][1] == 'O' && boardSlots[0][2] == 'O')
		return 'O';
	else if (boardSlots[1][0] == 'O' && boardSlots[1][1] == 'O' && boardSlots[1][2] == 'O')
		return 'O';
	else if (boardSlots[2][0] == 'O' && boardSlots[2][1] == 'O' && boardSlots[2][2] == 'O')
		return 'O';

	//checking OOO for each col
	else if (boardSlots[0][0] == 'O' && boardSlots[1][0] == 'O' && boardSlots[2][0] == 'O')
		return 'O';
	else if (boardSlots[0][1] == 'O' && boardSlots[1][1] == 'O' && boardSlots[2][1] == 'O')
		return 'O';
	else if (boardSlots[0][2] == 'O' && boardSlots[1][2] == 'O' && boardSlots[2][2] == 'O')
		return 'O';

	//checking OOO for the diagonals
	else if (boardSlots[0][0] == 'O' && boardSlots[1][1] == 'O' && boardSlots[2][2] == 'O')
		return 'O';
	else if (boardSlots[0][2] == 'O' && boardSlots[1][1] == 'O' && boardSlots[2][0] == 'O')
		return 'O';

	//No Wins
	else if (moveCounter == 8)
		return 'D';

	// Game is unfinished
	else
		return 'U';
}

char TicTacToe::gameStatus()
{
	char playGame; //Continue play again yes or no
	char yes = 'y', no = 'n';

	if (checkBoard() == 'X')			//<----This is where you check for winners/loser/draw
	{
		displayBoard();
		cout << "Player wins!" << endl;
		playGame = toupper(inputChar("Play again? (Y-yes or N-no): ", yes, no));
		if (playGame == 'Y')
		{
			resetBoard();
			displayBoard();
		}
		else
		{
			//break;
			return 'u';
		}
	}
	else if (checkBoard() == 'O')
	{
		displayBoard();
		cout << "Computer wins!" << endl;
		cout << "Play again? (Y-yes or N-no)" << endl;
		cin >> playGame;
		if (playGame == 'y')
		{
			resetBoard();
			displayBoard();
		}
		else
		{
			//break;
			return 'u';
		}
	}
	else if (checkBoard() == 'D')
	{
		displayBoard();
		cout << "It is a Draw!" << endl;
		cout << "Play again? (Y-yes or N-no)" << endl;
		cin >> playGame;
		if (playGame == 'Y')
		{
			resetBoard();
			displayBoard();
		}
		else
		{
			//break;
			return 'u';
		}
	}
	else
	{
		displayBoard();
	}
}