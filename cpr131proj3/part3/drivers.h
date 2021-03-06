// Participants: Andrew Thompson and Gabriela Lopez
// Date: 02-23-21
// Description: n-Queens driver

#pragma once
#include "input.h"
#include "nQueens.h"
#include <iostream>
#include <string>
using namespace std;
void nQueensDriver();
//Precondition: N/A
//Postcondition: prints project title and collaborator names
void queenHeader()
{
	cout << '\t' << char(201) << string(65, char(205)) << char(187) << '\n';
	cout << '\t' << char(186) << "     \t\t\t  CMPR131: n-Queens                       " << char(186) << '\n';
	cout << '\t' << char(186) << " Made by:                                                        " << char(186) << '\n';
	cout << '\t' << char(186) << " - Gabriela Lopez\t- Andrew Thompson\t- Lincoln Nguyen  " << char(186) << '\n';
	cout << '\t' << char(186) << " - Long Duong\t\t- Christopher Gomez\t- Gia Minh Hoang  " << char(186) << '\n';
	cout << '\t' << char(186) << " - Duyen Tran                                                    " << char(186) << '\n';
	cout << "\t" << char(200) << string(65, char(205)) << char(188) << "\n";
}

//Precondition: N/A
//Postcondition: contains all the n-Queens game solution
void nQueensDriver()
{
	/*Timer myTimer*/
	nQueens game;
	int menuOption;
	game.initiateGame();
	game.initTimer();
	do
	{
		system("cls");
		/*myTimer.start();*/
		queenHeader();
		game.displayBoard();
		cout << "Game options:\n";
		cout << "1: Place a Queen\n";
		cout << "2: Remove an existing queen\n";
		cout << "0: restart or return to game select\n";
		menuOption = inputInteger("Option: ", 0, 2);
		char choice = '\0';
		switch (menuOption)
		{
		case 0: choice = game.resetGame(); break;
		case 1: game.addQueen(); break;
		case 2: game.removeQueen(); break;
		default: cout << "\t\t    ERROR-Invalid Option. Please re-enter."; break;
		}
		if (game.winCheck())
		{
			game.timerGrab();

			if (game.getMoves() == 1)
				cout << "You have won! You solved " << game.getQueens() << "-Queens in " << game.getMoves() << " move.";
			else
				cout << "You have won! You solved " << game.getQueens() << "-Queens in " << game.getMoves() << " moves.";
			choice = game.resetGame();

		}
		if (choice == 'n')
		{
			game.dispTimes();
			break;
		}
		if (choice == 'y')
		{
			game.initiateGame();
			game.initTimer();

		}
		cout << '\n';
		system("pause");

	} while (true);

}