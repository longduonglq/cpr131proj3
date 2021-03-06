// Participants: Christopher
// Date: 
// Description: 

#include <time.h>
#include <vector>
#include "Timer.h"

#include <iostream>
using namespace std;

Timer::Timer() 
{}

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

void Timer::end(int boardDimension)
{
	end_time = time(0);
	this_time = end_time - start_time;
	setQueenRecord(boardDimension);
}

void Timer::setRecord() 
{
	timeRecords.push_back(this_time);
	setSecsAndMins(this_time);
	secRecords.push_back(secs);
	minRecords.push_back(mins);
}

void Timer::setQueenRecord(int boardSize)
{
	boardSize--;
	queensArray[boardSize][3] = this_time;
	setSecsAndMins(this_time);
	queensArray[boardSize][1] = secs;
	queensArray[boardSize][2] = mins;
}

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
}

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