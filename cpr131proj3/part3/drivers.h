#pragma once
#include "input.h"
#include "nQueens.h"
#include <iostream>
#include <string>
using namespace std;
void nQueensDriver();
void timer(int finish);

void timer(int finish)
{
	Timer myTimer;                                      //create class
	for (int i = 0; 1 == 1; i++)
	{
		myTimer.start();                                //start timer
		if (finish == 0) break;
		myTimer.end();                                  //end timer
		cout << "\n\n\t" <<
			myTimer.getMinRecord(i) << " minutes " <<   //get minutes at index
			myTimer.getSecRecord(i) << " seconds\n\n";  //get seconds at index
		cout << "\taverage: " <<
			myTimer.getAverageMin() << " minutes " <<   //get average minutes
			myTimer.getAverageSec() << " seconds\n\n";  //get average seconds
	}
}

void nQueensDriver()
{
	Timer myTimer;
	nQueens game;
	int matchCounter = 0; //times the game has been played
	int menuOption;
	do
	{
		system("cls");
		game.initiateGame();
		game.displayBoard();
		myTimer.start();
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
		if (game.winCheck())
		{ 
			if(game.getMoves() == 1)
			cout << "You have won! You solved "<< game.getQueens() << "-Queens in " << game.getMoves() << " move.";
			else
				cout << "You have won! You solved " << game.getQueens() << "-Queens in " << game.getMoves() << " moves.";
			myTimer.end(game.getDimensions());
			choice = game.resetGame(); 
		}
		if (choice == 'n')
			break;
		cout << '\n';
		system("pause");
	} while (true);
	//myTimer.printQueenArray();
}