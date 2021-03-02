// Participants: Christopher
// Date: 
// Description: 

#pragma once
#include <vector>
using namespace std;

class Timer {
	private:
		vector<int> secRecord;
		vector<int> minRecord;
		long long start_time, end_time, this_time;

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
		// Precondition: 
		// Postcondition: 
		void setRecord(int sec, int min);
};