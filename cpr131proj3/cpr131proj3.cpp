// Participants: Gabriela Lopez, Andrew Thompson, Long Duong, Christopher Gomez, Gia Minh Hoang, Duyen Tran and Lincoln Nguyen
// Date: 03-02-21
// Description: Chapter 3 Solution

#include <iostream>
#include <string>
//#include "Timer.h"
#include "part3/drivers.h"
#include "part1/tictactoe.h"

using namespace std;

//Precondition: N/A
//Postcondition: Prints menu and returns user int option selected
int menuOption();

/*void startTimer()
{
	Timer myTimer;                                      //create class
	for (int i = 0; 1 == 1; i++)
	{
		myTimer.start();                                //start timer
		nQueensDriver();
		myTimer.end();                                  //end timer
		cout << "\n\n\t" <<
			myTimer.getMinRecord(i) << " minutes " <<   //get minutes at index
			myTimer.getSecRecord(i) << " seconds\n\n";  //get seconds at index
		cout << "\taverage: " <<
			myTimer.getAverageMin() << " minutes " <<   //get average minutes
			myTimer.getAverageSec() << " seconds\n\n";  //get average seconds
		system("pause");
		break;
	}
}*/

int main()
{
	do
	{
		switch (menuOption())
		{
		case 0:  exit(0);
		case 1:  system("cls"); tictactoeStarter();     break;
			//case 2:  system("cls"); towers();  break;
		case 3:  system("cls"); nQueensDriver(); break; //startTimer();
		default: cout << "\t\t    ERROR-Invalid Option. Please re-enter."; break;
		}
		cout << '\n';
		system("pause");
	} while (true);
	return 0;
}

int menuOption() 
{
	system("cls");
	cout << '\n';
	cout << '\t' << char(201) << string(42, char(205)) << char(187) << '\n';
	cout << '\t' << char(186) << "    \t    CMPR131: Chapter 3             " << char(186) << '\n';
	cout << '\t' << char(186) << "      \t\t  Made by:                 " << char(186) << '\n';
	cout << '\t' << char(186) << " - Gabriela Lopez\t- Andrew Thompson  " << char(186) << '\n';
	cout << '\t' << char(186) << " - Lincoln Nguyen\t- Long Duong       " << char(186) << '\n';
	cout << '\t' << char(186) << " - Christopher Gomez\t- Gia Minh Hoang   " << char(186) << '\n';
	cout << '\t' << char(186) << " - Duyen Tran                             " << char(186) << '\n';
	cout << "\t" << char(204) << string(42, char(205)) << char(185) << "\n";
	cout << "\t" << char(186) << "   1: Tic-Tac-Toe                         " << char(186) << "\n";
	cout << "\t" << char(186) << "   2: Tower of Hanoi                      " << char(186) << "\n";
	cout << "\t" << char(186) << "   3: n-Queens                            " << char(186) << "\n";
	cout << "\t" << char(199) << string(42, char(196)) << char(182) << "\n";
	cout << "\t" << char(186) << "   0: Exit                                " << char(186) << "\n";
	cout << "\t" << char(200) << string(42, char(205)) << char(188) << "\n";

	int option = inputInteger("\t    Option: ", 0, 3);
	cin.clear();
	return option;
}