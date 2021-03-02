// Participants: Christopher
// Date: 
// Description: 

#include <time.h>
#include <vector>
#include "Timer.h"

Timer::Timer() {
	start();
}
void Timer::start() {
	start_time = time(0);
}
void Timer::end() {
	end_time = time(0);
	this_time = end_time - start_time;
}

int Timer::getMinutes() {
	if (this_time >= 60) {
		int reps = 1;
		for (reps; secs > 60; reps++) secs -= 60;
		mins = reps;
	}
	return mins;
}
void Timer::setRecord() {
	secs = this_time;
	mins = getMinutes();
	secRecords.push_back(sec);
	minRecords.push_back(min);
}

long Timer::getSecRecord(int index) {
	return secRecords<index>;
}
long Timer::getMinRecord(int index) {
	return minRecords<index>;
}

long Timer::getAverageSec() {
	long avg = 0;
	int i = 0;
	for (i; i < secRecords.size(); i++)
		avg += secRecords<i>;
	return avg / i;
}
long Timer::getAverageSec() {
	long avg = 0;
	int i = 0;
	for (i; i < minRecords.size(); i++)
		avg += minRecords<i>;
	return avg / i;
}