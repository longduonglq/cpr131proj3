// cpr131proj3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Timer.h"
using namespace std;

int main() {
    Timer myTimer;
    myTimer.start();
    string something;
    cin >> something;
    myTimer.end();
}

