// Participants: Christopher
// Date: 
// Description: 

#include <time.h>
#include "Timer.h"

Timer::Timer() {
	start();
}

Timer::start() {
	start_time = time;
}

Timer::end() {
	end_time = time;
}