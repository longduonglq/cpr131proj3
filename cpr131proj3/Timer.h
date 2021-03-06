// Participants: Christopher
// Date: 
// Description: 

#pragma once
#include <vector>
using namespace std;

class Timer 
{
	private:
		long long start_time, end_time, this_time;
		long mins = 0.0, secs = 0.0; //I remembered, Quach ;)
		vector<long> timeRecords;
		vector<long> secRecords;
		vector<long> minRecords;
		long queensArray[55][4];

	public:
		// Precondition: n/a
		// Postcondition: empty init
		Timer();

		// Precondition: pass in a long val to divvy into minutes and seconds
		// Postcondition: sets minutes and second values according to time given
		void setSecsAndMins(long full_time);

		// Precondition: pass in a vector of longs
		// Postcondition: returns average of all values in the vector
		long getAverage(vector<long> vals);

		// Precondition: setRecord();
		// Postcondition: returns average time of all times recorded
		void setAverageSecsAndMins();

		// Precondition: end();
		// Postcondition: clocks record of most current time
		void setRecord();

		// Precondition: end();
		// Postcondition: clocks record of most current time at the correct match dimension
		void setQueenRecord(int boardSize);



		void printQueenArray();



		//	use these for chapter 3 projects:

		// Precondition: create a Timer class
		// Postcondition: sets initial time
		void start();

		// Precondition: start();
		// Postcondition: sets end time and the difference between start and end
		void end();

		// Precondition: start(); and a board dimension for queens
		// Postcondition: sets end time and the difference between start and end
		void end(int boardDimension);

		// Precondition: setRecord();
		// Postcondition: returns seconds clocked for (index + 1)th time recorded
		long getSecRecord(int index);

		// Precondition: setRecord();
		// Postcondition: returns minutes clocked for (index + 1)th time recorded
		long getMinRecord(int index);

		// Precondition: setRecord();
		// Postcondition: returns average of seconds of all times recorded
		long getAverageSec();

		// Precondition: setRecord();
		// Postcondition: returns average of minutes of all times recorded
		long getAverageMin();
};