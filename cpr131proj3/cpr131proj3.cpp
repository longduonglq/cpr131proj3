// cpr131proj3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Timer.h"
using namespace std;

void TimerDemo() {
    Timer myTimer;
    for (int i = 0; 1 == 1; i++) {
        myTimer.start();
        cout << "\t\ttimer started ... \n\t0 to exit (anything else to stop timer) : ";
        string something;
        cin >> something;
        if (something.at(0) == '0') break;
        myTimer.end();
        cout << "\n\n\t" <<
            myTimer.getMinRecord(i) << " minutes " <<
            myTimer.getSecRecord(i) << " seconds\n\n";
        cout << "\taverage: " <<
            myTimer.getAverageMin() << " minutes " <<
            myTimer.getAverageSec() << " seconds\n\n";
    }
}

int main() {
    TimerDemo();
}