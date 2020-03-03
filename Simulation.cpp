#include "Simulation.h"
#include "Fringe.h"
#include "FileNotFoundException.h"
#include "BuggeredFormatException.h"

#include <iostream>
#include <fstream>

using namespace std;

/** The constructor
* PARAMS
*	string filename: The location of a properly formatted text file
*	char mode: A char representing the cost evaluation algorithm being used
*/
Simulation::Simulation(const string& filename, char mode) {

	this->mode = mode;

	ifstream filein;
	filein.open(filename);
	if(!filein) {
		throw FileNotFoundException("Could not open " + filename);
	}

	string temp;
	getline(filein, temp);
	this->mapsize = stoi(temp);
	char** grid = new char*[this->mapsize];
	cx = -1;
	cy = -1;
	gx = -1;
	gy = -1;

	for (int i = 0; i < this->mapsize; ++i) {
		grid[i] = new char[this->mapsize]; // x = j, y = i
		getline(filein, temp);
		for (int j = 0; j < this->mapsize; ++j) {
			switch (temp[j]){
				case '.':
				case '+':
				case 'x':
					grid[i][j] = temp[j];
					break;
				case 'i':
					cx = j;
					cy = i;
					grid[i][j] = temp[j];
					break;
				case 'g':
					gx = j;
					gy = i;
					grid[i][j] = temp[j];
					break;
				default:
					throw BuggeredFormatException("Unrecognized character in text file grid: " + temp[j]);
					break;
			}
		}

	}

	filein.close();

	fringe = new Fringe();

	State* initial = new State(cx, cy, mode, 0, 0, NULL);
	fringe->insert(initial);

	gs = new State(gx, gy, mode, 0, 0, NULL);

	notnulledgrid = grid;

}

/** The destructor
*/
Simulation::~Simulation() {

	delete grid;

	for (int i = 0; i < mapsize; ++i) {
		delete notnulledgrid[i];
	}
	delete notnulledgrid;

	delete fringe;

}

/** Starts the recursion to find a path to the goal state
* RETURNS
*	State*: A pointer to the state that matches the goal state (uses the States' parents to trace back the path)
*/
State* Simulation::Run() {
	return FindPath(fringe->pop());
}

/** Recursively finds a path from the given state to the goal state
* PARAMS
*	State* s: The state to find a path from
* RETURNS
*	State*: A pointer to the state that matches the goal state (uses the States' parents to trace back the path)
*/
State* Simulation::FindPath(State* s) {

	if (*s == *gs) {
		return s;
	} else {
		fringe->insert(s->GetSuccessors(gx, gy, mapsize, notnulledgrid));
		return FindPath(fringe->pop());
	}

}

/** Constructs output demonstrating the path found from the initial state to the goal state
* PARAMS
*	State* s: A pointer to the state object at the goal state
* RETURNS
*	string: A string, the output (includes marked grid, name of cost algorithm, and cost of path)
*/
string Simulation::ConstructOutput(State* s) {

	int totalCost = s->GetSteps();
	State* currState = s->GetParent();
	while (currState->GetParent() != NULL) {
		int j = currState->GetX();
		int i = currState->GetY();	
		notnulledgrid[i][j] = 'o';
		currState = currState->GetParent();
	}

	string out = "";
	for (int i = 0; i < mapsize; ++i) {
		for (int j = 0; j < mapsize; ++j) {
			out += notnulledgrid[i][j];
		}
		out += '\n';
	}

	out += "Cost for ";
	switch (this->mode) {
		case 'e':
			out += "Euclidian Distance Greedy Algorithm: ";
			break;
		case 'E':
			out += "Euclidian Distance A* Algorithm: ";
			break;
		case 'm':
			out += "Manhattan Distance Greedy Algorithm: ";
			break;
		case 'M':
			out += "Manhattan Distance A* Algorithm: ";
			break;
	}
	out += to_string(totalCost);

	return out;

}
	