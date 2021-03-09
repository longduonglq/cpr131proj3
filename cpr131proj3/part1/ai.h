#pragma once

#include <iostream>
#include <vector>
#include <array>
#include <experimental/generator>

class AI
{
public:
	const char COMPUTER_SYMBOL = 'O';
	const char USER_SYMBOL = 'X';
	const char EMPTY_SYMBOL = ' ';
	const int LENGTHY_COST = 2;
	const int BIG_NUMBER = 10000;
	const double RANDOM_FACTOR = 0.5;
	AI(char gameBoard[][3]);
	std::pair<int, int> getBestMove();

	bool didUserWin();
	bool didSelfWin();

private:
	bool probabilisticBoolean(double p);
	template <typename RowTransform, typename ColTransform>
	std::vector<char> generateSequence(int row, int col, RowTransform&&, ColTransform&&);
	std::experimental::generator<std::vector<char>> allSequences();

	int utility();
	std::pair<int, std::pair<int, int>>  maximizeUtility();
	std::pair<int, std::pair<int, int>> minimizeUtility();

	std::array<std::array<char, 3>, 3> gameBoard;
};
