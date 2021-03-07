#pragma once

#include <iostream>
#include <vector>
#include <experimental/generator>

class AI
{
public:
	const char COMPUTER_SYMBOL = 'O';
	const char USER_SYMBOL = 'X';
	const char EMPTY_SYMBOL = ' ';
	AI(char** gameBoard);
	std::pair<int, int> getBestMove();

private:
	template <typename RowTransform, typename ColTransform>
	std::vector<char> generateSequence(int row, int col, RowTransform&&, ColTransform&&);
	std::experimental::generator<std::vector<char>> allSequences();

	int utility();
	std::pair<int, std::pair<int, int>>  maximizeUtility();
	std::pair<int, std::pair<int, int>> minimizeUtility();

	char** gameBoard;
};
