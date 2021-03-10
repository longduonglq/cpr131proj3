//Participants: Long Duong 
//description: Ai for tictactoe
//date: 03/09/2020

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

	// Preconditions: NA
	// Postconditions: Copy c-style array to c++ array
	AI(char gameBoard[][3]);

	// Preconditions: Instance is initialized
	// Postconditions: Return the best move as a pair
	std::pair<int, int> getBestMove();

	// Preconditions: Instance is initialized
	// Postconditions: Returns if user wins
	bool didUserWin();

	// Preconditions: Instance is initialized
	// Postconditions: Returns if computer wins
	bool didSelfWin();

private:
	// Preconditions: NA
	// Postconditions: Returns true with probability p
	bool probabilisticBoolean(double p);

	// Preconditions: NA
	// Postconditions: Generate a sequence in the board starting at row, col and transformed by transformer provided.
	template <typename RowTransform, typename ColTransform>
	std::vector<char> generateSequence(int row, int col, RowTransform&&, ColTransform&&);

	// Preconditions: Instance was initialized
	// Postconditions: Returns all possible sequence in the board
	std::experimental::generator<std::vector<char>> allSequences();

	// Preconditions: Instance was initialized
	// Postconditions: Returns a number that evaluates how preferable a game state is to a computer 
	int utility();

	// Preconditions: Instance was initialized
	// Postconditions: Pick a move that maximize the utility for a computer 
	std::pair<int, std::pair<int, int>>  maximizeUtility();

	// Preconditions: Instance was initialized 
	// Postconditions:  Pick a move that minimize the utility for a computer 
	std::pair<int, std::pair<int, int>> minimizeUtility();

	std::array<std::array<char, 3>, 3> gameBoard;
};
