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
int Timer::getSeconds() {
	int secs = this_time;
	if (this_time < 60) return secs;
	else t
	return 
}
int Timer::getMinutes() {
	//floor()
}
void Timer::setRecord(int sec, int min) {

}