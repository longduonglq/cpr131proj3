// Participants: Christopher
// Date: 
// Description: 

#pragma once
#include <vector>

class Timer {
	public:
		// Precondition: 
		// Postcondition: 
		Timer();

		// Precondition: 
		// Postcondition: 
		void start();
		// Precondition: 
		// Postcondition: 
		void end();

		// Precondition: 
		// Postcondition: 
		int getSeconds();
		// Precondition: 
		// Postcondition: 
		int getMinutes();

	private:
		long long start_time, end_time, this_time;

};