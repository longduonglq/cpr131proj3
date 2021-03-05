#pragma once
#include "input.h"
#include "nQueens.h"
#include <iostream>
#include <string>
using namespace std;
void nQueensDriver();
void nQueensDriver()
{
	nQueens game;
	int menuOption;
	game.initiateGame();
	do
	{
		game.displayBoard();
		cout << "Game options:\n";
		cout << "1: Place a Queen\n";
		cout << "2: Remove an existing queen\n";
		cout << "0: restart or return to game select\n";
		menuOption = inputInteger("Option: ", 0, 2);
		char choice ='y';
		switch (menuOption)
		{
		case 0: choice=game.resetGame(); break;
		case 1: game.addQueen(); break;
		case 2: game.removeQueen(); break;

		default: cout << "\t\t    ERROR-Invalid Option. Please re-enter."; break;
		}
		if (choice == 'n')
			break;
		if (game.winCheck())
		{ 
			cout << "\n You have won! \n";
			choice = game.resetGame(); 
		}
		cout << '\n';
		system("pause");
	} while (true);
}