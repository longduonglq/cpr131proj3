//Participants: Duyen tran, gia minh, And andrew Thompson
//description: Implementation file of the TowersOfHanoi class
//date: 3/9/2021
#include "TowerOfHanoi.h"
#include "../input.h"
#include <iostream>
#include<iomanip>
#include <string>
using namespace std;

towerOfHanoi::towerOfHanoi()
{
	disk = 0;
	A = NULL;
	B = NULL;
	C = NULL;
}
towerOfHanoi::~towerOfHanoi()
{
	delete[] A;
	delete[] B;
	delete[] C;

}

int towerOfHanoi::getDisk()
{
	return disk;
}
bool towerOfHanoi::AEmpty() const
{
	
	for (int i = 0; i < disk; i++)
	{
		if (A[i] != 0)
			return false;
	}
	return true;

}
bool towerOfHanoi::BEmpty() const
{
	
	for (int i = 0; i < disk; i++)
	{
		if (B[i] != 0)
			return false;
	}
	return true;
}
bool towerOfHanoi::CEmpty() const
{
	
	for (int i = 0; i < disk; i++)
	{
		if (C[i] != 0)
			return false;
	}
	return true;
}
int towerOfHanoi::getCsize() const
{
	int size = 0;
	for (int i = 0; i < disk; i++)
	{
		if (C[i] != 0)
			size++;
	}
	return size;
}
int towerOfHanoi::getAsize() const
{
	int size = 0;
	for (int i = 0; i < disk; i++)
	{
		if (A[i] != 0)
			size++;
	}
	return size;
}
bool towerOfHanoi::winCheck() const
{
	if (getCsize() == disk)
		return true;
	else
		return false;
}
int towerOfHanoi::getTop(int ptr) const
{
	if (ptr == 1)
	{
		for (int i = 0; i < disk; i++)
		{
			if (A[i] != 0)
				return A[i];
				
		}
		return 0;
	}
	if (ptr == 2)
	{
		for (int i = 0; i < disk; i++)
		{
			if (B[i] != 0)
				return B[i];

		}
		return 0;
	}
	if (ptr == 3)
	{
		for (int i = 0; i < disk; i++)
		{
			if (C[i] != 0)
				return C[i];

		}
		return 0;
	}

}
int towerOfHanoi::getTopIndex(int ptr) const
{
	if (ptr == 1)
	{
		for (int i = 0; i < disk; i++)
		{
			if (A[i] != 0)
				return i;

		}
		return 0;
	}
	if (ptr == 2)
	{
		for (int i = 0; i < disk; i++)
		{
			if (B[i] != 0)
				return i;

		}
		return 0;
	}
	if (ptr == 3)
	{
		for (int i = 0; i < disk; i++)
		{
			if (C[i] != 0)
				return i;

		}
		return 0;
	}

}
// input the disk into tower
void towerOfHanoi::getInputDisk()
{
	disk = inputInteger("enter number of disks from 1...64: ", 1, 64);
	int reverse = disk;
	A = new int[disk];
	B = new int[disk];
	C = new int[disk];
		
	// reverse the input. Ex: if user input 5, then the function will push_back 5>4>3>2>1 into the vector
	// so that when we use pop_back the smallest will be popped out.
	for (int i = 0; i <disk; i++)
	{
		A[i] = i + 1;
		B[i] = 0;
		C[i] = 0;
	}
}
void towerOfHanoi::dispTowers() const
{
	for (int i = 0; i <disk; i++)
	{
		cout << A[i] << setw(17) << B[i] << setw(17) << C[i] << endl;
	}

}
// asking user where to move the disks
void towerOfHanoi::getInputTower(char& from, char& to)
{
	string valid = "abcq";
	from = inputChar("Select the top disk from the start peg (A, B, C, or Q-quit): ", valid);
	to = inputChar("Select the end peg (A, B, C or Q-quit) to move the selected disk: ", valid);
}

 /*depends on the answer from getInputTower(char& from, char& to)
 function will move disk from A->B, or B->... accordingly to the user input 
recusivly functions*/
void towerOfHanoi::moveTower(char start, char end)
{

	//move from Tower A -> Tower B
	if (start == 'a' && end == 'b')
	{
		//If tower A is empty, there will be no disk to move to B (giver)
		if (AEmpty())
		{
			cout << "\n\tERROR: Cannot make the move. There is no disk in the selected peg-A. Please choose again.\n\n";
			getInputTower(start, end);
			moveTower(start, end);
		}
		// if B is empty, push_back disk from tower A (receiver)
		else if (BEmpty())
		{
			B[disk-1] = A[getTopIndex(1)];
			A[getTopIndex(1)] = 0;
		}
		// rule: only smaller disk can be placed on top
		else if (getTop(1) < getTop(2))
		{
			B[getTopIndex(2)-1] = A[getTopIndex(1)];
			A[getTopIndex(1)] = 0;
		}
		else
		{
			cout << "\nERROR: Cannot make the move. Top disk ";
			cout << A[getTopIndex(1)]<< " is larger than top disk ";
			cout << B[getTopIndex(2)];
			cout << "\n\t	Please choose again.\n\n";

			getInputTower(start, end);
			moveTower(start, end);

		}
	}
	// move from A->C
	else if (start == 'a' && end == 'c')
	{
	if (AEmpty())
	{
		cout << "\n\tERROR: Cannot make the move. There is no disk in the selected peg-A. Please choose again.\n\n";
		getInputTower(start, end);
		moveTower(start, end);
	}
	else if (CEmpty())
	{
		C[disk-1]=A[getTopIndex(1)];
		A[getTopIndex(1)]=0;
	}
	else if (A[getTopIndex(1)] < C[getTopIndex(3)])
	{
		C[getTopIndex(3)-1]=A[getTopIndex(1)];
		A[getTopIndex(1)] = 0;
	}
	/*else if (C.back() == 0)
	{
		C.pop_back();
		C.push_back(A.back());
		A.pop_back();
		A.push_back(0);
	}*/
	else
	{
		cout << "\nERROR: Cannot make the move. Top disk ";
		cout << A[getTopIndex(1)] << " is larger than top disk ";
		cout << C[getTopIndex(3)];
		cout << "\n\t	Please choose again.\n\n";

		getInputTower(start, end);
		moveTower(start, end);
	}
	}
	// move from B->A
	else if (start == 'b' && end == 'a')
	{
	if (BEmpty())
	{
		cout << "\n\tERROR: Cannot make the move. There is no disk in the selected peg-B. Please choose again.\n\n";
		getInputTower(start, end);
		moveTower(start, end);
	}
	else if (AEmpty())
	{
		A[disk-1]=B[getTopIndex(2)];
		B[getTopIndex(2)] = 0;
	}
	else if (B[getTopIndex(2)] < A[getTopIndex(1)])
	{
		A[getTopIndex(1)-1]=B[getTopIndex(2)];
		B[getTopIndex(2)] = 0;
	}
	else
	{
		cout << "\nERROR: Cannot make the move. Top disk ";
		cout << B[getTopIndex(2)] << " is larger than top disk ";
		cout << A[getTopIndex(1)];
		cout << "\n\t	Please choose again.\n\n";

		getInputTower(start, end);
		moveTower(start, end);
	}
	}
	// move from B->C
	else if (start == 'b' && end == 'c')
	{
	if (BEmpty())
	{
		cout << "\n\tERROR: Cannot make the move. There is no disk in the selected peg-B. Please choose again.\n\n";
		getInputTower(start, end);
		moveTower(start, end);
	}
	else if (CEmpty())
	{
		C[disk-1]=B[getTopIndex(2)];
		B[getTopIndex(2)] = 0;
	}
	else if (B[getTopIndex(2)] < C[getTopIndex(3)])
	{
		C[getTopIndex(3)-1]=B[getTopIndex(2)];
		B[getTopIndex(2)] = 0;
	}
	else
	{
		cout << "\nERROR: Cannot make the move. Top disk ";
		cout << B[getTopIndex(2)] << " is larger than top disk ";
		cout << C[getTopIndex(3)];
		cout << "\n\t	Please choose again.\n\n";

		getInputTower(start, end);
		moveTower(start, end);
	}
	}
	// move from C->A
	else if (start == 'c' && end == 'a')
	{
	if (CEmpty())
	{
		cout << "\n\tERROR: Cannot make the move. There is no disk in the selected peg-C. Please choose again.\n\n";
		getInputTower(start, end);
		moveTower(start, end);
	}
	else if (AEmpty())
	{
		A[disk-1]=C[getTopIndex(3)];
		C[getTopIndex(3)] = 0;
	}
	else if (C[getTopIndex(3)] < A[getTopIndex(1)])
	{
		A[getTopIndex(1)-1]=C[getTopIndex(3)];
		C[getTopIndex(3)] = 0;
	}
	else
	{
		cout << "\nERROR: Cannot make the move. Top disk ";
		cout << C[getTopIndex(3)] << " is larger than top disk ";
		cout << A[getTopIndex(1)];
		cout << "\n\t	Please choose again.\n\n";

		getInputTower(start, end);
		moveTower(start, end);
	}
	}
	// move from C->B
	else if (start == 'c' && end == 'b')
	{
	if (CEmpty())
	{
		cout << "\n\tERROR: Cannot make the move. There is no disk in the selected peg-C. Please choose again.\n\n";
		getInputTower(start, end);
		moveTower(start, end);
	}
	else if (BEmpty())
	{
		B[disk-1]=C[getTopIndex(3)];
		C[getTopIndex(3)] = 0;
	}
	else if (C[getTopIndex(3)] < B[getTopIndex(2)])
	{
		B[getTopIndex(2)-1]=C[getTopIndex(3)];
		C[getTopIndex(3)] = 0;
	}
	else
	{
		cout << "\nERROR: Cannot make the move. Top disk ";
		cout << C[getTopIndex(3)] << " is larger than top disk ";
		cout << B[getTopIndex(2)];
		cout << "\n\t	Please choose again.\n\n";

		getInputTower(start, end);
		moveTower(start, end);
	}
	}
}