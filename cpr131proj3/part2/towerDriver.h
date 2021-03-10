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
			cout << "\n\n\tslowest time: " <<
				myTimer.getSlowestMin() << " minutes " <<
				myTimer.getSlowestSec() << " seconds\n\n";
			cout << "\tfastest time: " <<
				myTimer.getFastestMin() << " minutes " <<
				myTimer.getFastestSec() << " seconds\n\n";
			cout << "\taverage time: " <<
				myTimer.getAverageMin() << " minutes " <<
				myTimer.getAverageSec() << " seconds\n\n";
			break;
		}
		
		myTimer.end();
	} while (true);
	return;
}