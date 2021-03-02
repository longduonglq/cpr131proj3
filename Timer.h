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
		int getMinutes();
		// Precondition: 
		// Postcondition: 
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