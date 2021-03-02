// Participants: Christopher
// Date: 
// Description: 

#include <time.h>
#include <vector>
#include "Timer.h"

using namespace std; //DEBUG
#include <iostream> //DEBUG

//TO DO: error handling?
//example: shouldn't be allowed to start() twice in a row without end()'ing...

Timer::Timer() {}
void Timer::start() {
	start_time = time(0);
	//DEBUG:
	cout << "\nThe time was " << start_time;
}
void Timer::end() {
	end_time = time(0);
	//DEBUG:
	cout << "\nThe time is " << end_time;
	this_time = end_time - start_time;
	setRecord();
}

void Timer::setRecord() {
	secs = this_time;
	if (secs >= 60) {
		int reps = 1;
		for (reps; secs >= 60; reps++) secs -= 60;
		mins = reps;
	}
	secRecords.push_back(secs);
	minRecords.push_back(mins);
}
long Timer::getSecRecord(int index) {
	return secRecords[index];
}
long Timer::getMinRecord(int index) {
	return minRecords[index];
}

long Timer::getAverage(vector<long> vals) {
	long avg = 0;
	int i = 0;
	for (i; i < vals.size(); i++)
		avg += vals[i];
	return avg / i;
}
long Timer::getAverageSec() {
	return getAverage(secRecords);
}
long Timer::getAverageMin() {
	return getAverage(minRecords);
}