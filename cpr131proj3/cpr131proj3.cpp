// cpr131proj3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Timer.h"
#include "part3/drivers.h"
using namespace std;

void startTimer() 
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
}

int main() 
{
    startTimer();
    //nQueensDriver();
    /*	while (true)
	{
		for (int x = 0; x < 4; x++)
		{
			for (int y = 0; y < 4; y++)
			{
				cout << "\t";
				cout << queensArray[x][y];
			}
			cout << endl;
		}

        for (int column = 0; column < 55; column++)
        {
        for (int row = 0; row < 4; row++)
        {
            queensArray[column][row];
        }
    }
	}*/
}