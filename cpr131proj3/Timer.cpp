// Participants: Christopher
// Date: 03/02/21
// Description: Timer implementation

#include <time.h>
#include <vector>
#include "Timer.h"

#include <iostream>
using namespace std;

Timer::Timer() 
{
	/*gameCounter.push_back(0.0);
	seconds.push_back(0.0);*/
}

long Timer::getAverage(vector<long> vals) 
{
	long avg = 0;
	int i = 0;
	for (i; i < vals.size(); i++)
		avg += vals[i];
	return avg / i;
}

void Timer::setSecsAndMins(long full_time) 
{
	secs = full_time;
	if (secs >= 60) 
	{
		int reps = 0;
		for (reps; secs >= 60; reps++) secs -= 60;
		mins = reps;
	}
}

void Timer::setAverageSecsAndMins() 
{
	long avg = getAverage(timeRecords);
	setSecsAndMins(avg);
}

void Timer::start() 
{
	start_time = time(0);
}

void Timer::end() 
{
	end_time = time(0);
	this_time = end_time - start_time;
	setRecord();
}

/*void Timer::end(int boardDimension)
{
	end_time = time(0);
	this_time = end_time - start_time;
	setQueenRecord(boardDimension);
}*/

void Timer::setRecord() 
{
	timeRecords.push_back(this_time);
	setSecsAndMins(this_time);
	secRecords.push_back(secs);
	minRecords.push_back(mins);
}

/*long Timer::getAverage(int boardSize)
{
	setSecsAndMins(this_time);
	seconds[boardSize] = seconds[boardSize] + secs;
	gameCounter[boardSize] = gameCounter[boardSize] + 1;
	cout << "\nSECONDS: " << seconds[boardSize] << ".\n";
	cout << "\nGAME COUNTER: " << gameCounter[boardSize] << ".\n";
	long avg = seconds[boardSize]/gameCounter[boardSize];
	
	return avg;
}

void Timer::setQueenRecord(int boardSize)
{
	boardSize--;
	queensArray[boardSize][2] = getAverage(boardSize);
	//row 2 will be array of all the int times
	setSecsAndMins(this_time);
	queensArray[boardSize][0] = secs;
	queensArray[boardSize][1] = mins;
}

//get total of seconds
//get average of seconds between matches

void Timer::printQueenArray()
{
	for (int column = 0; column < 55; column++)
	{
		for (int row = 0; row < 4; row++)
		{
			cout << "\t";
			cout << queensArray[column][row];
		}
		cout << endl;
	}
}*/

long Timer::getSecRecord(int index) 
{
	return secRecords[index];
}

long Timer::getMinRecord(int index) 
{
	return minRecords[index];
}

long Timer::getAverageSec() 
{
	setAverageSecsAndMins();
	return secs;
}

long Timer::getAverageMin() 
{
	setAverageSecsAndMins();
	return mins;
}

void Timer::displayTimeRecords()
{
	cout << '\n' << mins << " minutes and " << secs << " seconds played this match.\n";
}