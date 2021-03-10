#pragma once
#include <iostream>
#include "TowerOfHanoi.h"
#include <string>
#include "../input.h"
#include "../timer/Timer.h"

using namespace std;
void towerDriver()
{
	Timer myTimer;
	myTimer.start();
	myTimer.end();

	int numberOfGames = 0;
	do
	{
		numberOfGames++;
		myTimer.start();

		towerOfHanoi game;
		game.getInputDisk();
		char from, to;
		int oriSizeA = game.getAsize();
		int count = 0;
		game.dispTowers();
		do
		{

			game.getInputTower(from, to);
			if (tolower(from) == 'q' || tolower(to) == 'q')
				break;
			game.moveTower(from, to);
			count++;
			game.dispTowers();
			if (game.winCheck())
				break;
		} while (true);

		cout << "\nWin.\nNumber of moves: " << count << "\n";
		
		char yes = 'y', no = 'n';
		char playAgain = inputChar("Do you want to play again (y/n): ", 'y', 'n');
		if (playAgain == no)
		{
			myTimer.end();
			myTimer.displayTimeRecords();
			break;
		}
		
		myTimer.end();
	} while (true);
	return;
}