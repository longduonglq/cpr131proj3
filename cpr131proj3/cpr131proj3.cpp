// cpr131proj3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Timer.h"
using namespace std;

void TimerDemo() {
    Timer myTimer;                                      //create class
    for (int i = 0; 1 == 1; i++) {
        myTimer.start();                                //start timer
        cout << "\t\ttimer started ... \n\t0 to exit (anything else to stop timer) : ";
        string something;
        cin >> something;
        if (something.at(0) == '0') break;
        myTimer.end();                                  //end timer
        cout << "\n\n\t" <<
            myTimer.getMinRecord(i) << " minutes " <<   //get minutes at index
            myTimer.getSecRecord(i) << " seconds\n\n";  //get seconds at index
        cout << "\taverage: " <<
            myTimer.getAverageMin() << " minutes " <<   //get average minutes
            myTimer.getAverageSec() << " seconds\n\n";  //get average seconds
    }
}

int main() {
    TimerDemo();
}