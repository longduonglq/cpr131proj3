#include "ai.h"
#include <cassert>
#include <algorithm>

using namespace std;

#define EXPR(MY_EXPR) [](int X){ return MY_EXPR; }
#define IN_RANGE(X, a, b) ((a <= X && X < b))

AI::AI(char _gameBoard[][3])
{
	for (int i = 0; i < 3; i++)
		std::copy(_gameBoard[i], _gameBoard[i] + 3, gameBoard[i].begin());
}

std::pair<int, int> AI::getBestMove()
{
	return maximizeUtility().second;
}

int AI::utility()
{
	int totalUtility = 0;
	for (auto&& seq : allSequences())
	{
		int numComputerSymbols = std::count(seq.cbegin(), seq.cend(), COMPUTER_SYMBOL);
		int numUserSymbols = std::count(seq.cbegin(), seq.cend(), USER_SYMBOL);
		int numEmptySymbols = std::count(seq.cbegin(), seq.cend(), EMPTY_SYMBOL);
		if (numComputerSymbols == 3)
			totalUtility += 1000;
		else if (numUserSymbols == 3)
			totalUtility -= 1000;
		else
			totalUtility += (numComputerSymbols + numEmptySymbols - numUserSymbols);
	}
	return totalUtility;
}

std::pair<int, std::pair<int, int>> AI::maximizeUtility()
{
	if (all_of(gameBoard.begin(), gameBoard.begin() + 3, 
		[](auto& arr) { return all_of(arr.begin(), arr.begin() + 3, [](char e) { return e != ' '; }); }))
		return  std::make_pair(utility(), make_pair(-1, -1));

	double maxUtility = -std::numeric_limits<double>::infinity();
	std::pair<int, int> bestMove;
	for (int row = 0; row < 3; row ++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (gameBoard[row][col] == EMPTY_SYMBOL)
			{
				gameBoard[row][col] = COMPUTER_SYMBOL;
				int currUtil;
				tie(currUtil, ignore) = minimizeUtility();
				if (currUtil > maxUtility)
				{
					maxUtility = currUtil;
					bestMove = make_pair(row, col);
				}
				gameBoard[row][col] = EMPTY_SYMBOL;
			}
		}
	}
	return make_pair(static_cast<int>(maxUtility - LENGTHY_COST), bestMove);
}

std::pair<int, std::pair<int, int>> AI::minimizeUtility()
{
	if (all_of(gameBoard.begin(), gameBoard.begin() + 3,
		[](auto& arr) { return all_of(arr.begin(), arr.begin() + 3, [](char e) { return e != ' '; }); }))
		return  std::make_pair(utility(), make_pair(-1, -1));

	double minUtility = std::numeric_limits<double>::infinity();
	std::pair<int, int> bestMove;
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (gameBoard[row][col] == EMPTY_SYMBOL)
			{
				gameBoard[row][col] = USER_SYMBOL;
				int currUtil;
				tie(currUtil, ignore) = maximizeUtility();
				if (currUtil < minUtility)
				{
					minUtility = currUtil;
					bestMove = make_pair(row, col);
				}
				gameBoard[row][col] = EMPTY_SYMBOL;
			}
		}
	}
	return make_pair(static_cast<int>(minUtility - LENGTHY_COST), bestMove);
}

template <typename RowTransform, typename ColTransform>
std::vector<char> AI::generateSequence(int row, int col, RowTransform&& rowTf, ColTransform&& colTf)
{
	auto res = std::vector<char>();
	res.reserve(3);
	while (IN_RANGE(row, 0, 3) && IN_RANGE(col, 0, 3))
	{
		res.push_back(gameBoard[row][col]);
		row = rowTf(row);
		col = colTf(col);
	}
	assert(res.size() == 3);
	return res;
}

std::experimental::generator<std::vector<char>> AI::allSequences()
{
	for (int i = 0; i < 3; i++)
	{
		co_yield generateSequence(0, i, EXPR(X + 1), EXPR(X));
		co_yield generateSequence(i, 0, EXPR(X), EXPR(X + 1));
	}
	co_yield generateSequence(0, 0, EXPR(X + 1), EXPR(X + 1));
	co_yield generateSequence(0, 2, EXPR(X + 1), EXPR(X - 1));
}


