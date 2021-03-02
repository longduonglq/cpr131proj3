// Participants: Christopher
// Date: 
// Description: 

#pragma once
#include <vector>
using namespace std;

class Timer {
	private:
		long long start_time, end_time, this_time;
		long mins, secs;
		vector<long> secRecords;
		vector<long> minRecords;
	public:
		// Precondition: n/a
		// Postcondition: empty init
		Timer();

		// Precondition: create a Timer class
		// Postcondition: sets initial time
		void start();
		// Precondition: start();
		// Postcondition: sets end time and the difference between start and end
		void end();

		// Precondition: end();
		// Postcondition: returns seconds part of this_time
		int getSeconds();
		// Precondition: end();
		// Postcondition: returns minutes part of this_time
		int getMinutes();
		// Precondition: end();
		// Postcondition: sets record of most current time
		void setRecord();

		// Precondition: 
		// Postcondition: 
		long getSecRecord(int index);
		// Precondition: 
		// Postcondition: 
		long getMinRecord(int index);

		// Precondition: 
		// Postcondition: 
		long getAverageSec();
		// Precondition: 
		// Postcondition: 
		long getAverageMin();
};