#pragma once
//Participants: Duyen tran, gia minh, And andrew Thompson
//description: header file for the TowersOfHanoi class
//date: 3/9/2021
#include <vector>
using namespace std;
class towerOfHanoi
{
private:
	int disk;
	int* A;     
	int* B;
	int* C;
	long timeStorage[25][5];
public:
	//preconditions:N/A
	//postconditions:creates a default towerOfHanoi object 
	towerOfHanoi();
	//preconditions: A tower of hanoi object, and the termination of the tower program
	//postconditions: returns the contents of A, B, and C to the free store
	~towerOfHanoi();
	//preconditions: a towerOfHanoi Object
	//postconditions: returns the amount of disks
	int getDisk();
	//preconditions: game is running
	//postconditions: asks the user for the amount of disks they would like to use, and initiates the game to that
	void getInputDisk();
	//preconditions: The game is running
	//postconditions: gets the places the user would like to send the disks
	void getInputTower(char& from, char& to);
	//preconditions: the game is running and locations of towers have been input
	//postconditions: moves the disk from start to end
	void moveTower(char start, char end);
	//preconditions: a towers of hanoi object
	//postconditions: displays the towers and disks 
	void dispTowers() const;
	//preconditions: a towers of hanoi object
	//postconditions: checks the contents of the first tower,returns true if 'empty'(all items are 0) false if not
	bool AEmpty() const;
	//preconditions: a towers of hanoi object
	//postconditions: checks the contents of the second tower,returns true if 'empty'(all items are 0) false if not
	bool BEmpty() const;
	//preconditions: a towers of hanoi object
	//postconditions: checks the contents of the third tower,returns true if 'empty'(all items are 0) false if not
	bool CEmpty() const;
	//preconditions: a towers of hanoi object.
	//postconditions: returns the top of tower a(1), b(2) or c(3),
	int getTop(int ptr) const;
	//preconditions: a towers of hanoi object
	//postconditions: returns the index of the top item tower a(1), b(2) or c(3),
	int getTopIndex(int ptr) const;
	//preconditions:a towers of hanoi Object
	//postconditions: returns the size of tower a
	int getAsize() const;
	///preconditions:a towers of hanoi Object
	//postconditions: returns the size of tower c
	int getCsize() const;
	//preconditions: a towers of hanoi object, and the game has been running
	//postconditions: returns true if the player wins
	bool winCheck() const;
	//preconditions: the user chose to restart the game 
	//postconditions: resets the board
	void resetGame();
	
};