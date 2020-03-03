#ifndef SIMULATION
#define SIMULATION

#include "Fringe.h"
#include "State.h"
#include <iostream>
#include <vector>

using namespace std;

// A class for running a search to find paths from an inital state to a goal state
class Simulation {

	public:
		Simulation(const string& filename, char mode);
		~Simulation();


		State* Run();
		State* FindPath(State* s);
		string ConstructOutput(State* s);
	
	private:
		char** grid;
		char** notnulledgrid;

		int mapsize;
		int gx;
		int gy;
		int cx;
		int cy;
		char mode;
		Fringe* fringe;
		State* gs;

};

#endif