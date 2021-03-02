// Participants: Christopher
// Date: 
// Description: 

#include <time.h>
#include <vector>
#include "Timer.h"

Timer::Timer() {
	start();
}
Timer::start() {
	start_time = time;
}
Timer::end() {
	end_time = time;
	//this_time = end_time - start_time;
}
Timer::getSeconds() {
	//return ;
}
Timer::getMinutes() {
	//floor 
}