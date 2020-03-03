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
		/* These two pointers are meant to be the same, but for some reason the
		*  grid pointer kept getting nulled out by the time it reached functions beyond the constructor.
		*  I still have no idea why that was happening, but simply copying the address to a different
		*  variable seemed to fix it. C++ works in mysterious ways.
		*/
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
