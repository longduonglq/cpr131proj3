#pragma once
#include <iostream>
#include "TowerOfHanoi.h"
#include <string>

using namespace std;
void towerDriver()
{
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
	
}