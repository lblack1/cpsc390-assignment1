#include "State.h"
#include "CostCalc.h"
#include <iostream>
#include <vector>

using namespace std;

/** The State constructor.
* PARAMS
*	int x: The column number/x-coordinate of the agent
*	int y: The row number/y-coordinate of the agent
*	char mode: The algorithm being used to evaluate the path cost
*	double cost: The path cost
*	int steps: The number of steps taken to reach this state from the inital
*	State* parent: The state from which this state was reached
*/
State::State(int x, int y, char mode, double cost, int steps, State* parent) {

	this->x = x;
	this->y = y;	
	this->mode = mode;
	this->cost = cost;
	this->steps = steps;
	this->parent = parent;

}

/** Gets the successors of 'this' state.
* PARAMS
*	int gx: The column number/x-coordinate of the goal
*	int gy: The row number/y-coordinate of the goal
*	int mapsize: The number of rows and columns in the map area
*	char** grid: A 2D array of characters that represents the map/grid
* RETURNS
*	State**: An array of State pointers, the valid successors to the current state
*/
State** State::GetSuccessors(int gx, int gy, int mapsize, char** grid) {
	
	int validSuccessorCount = 0;
	vector< pair<int,int> > successorLocations;


	// Finding and tracking successor locations
	if ((this->y + 1) != mapsize && grid[this->y + 1][this->x] != '+' && grid[this->y + 1][this->x] != 'x') {
		validSuccessorCount++;
		successorLocations.push_back(pair<int,int>(this->x, this->y+1));
	}

	if ((this->x + 1) != mapsize && grid[this->y][this->x + 1] != '+' && grid[this->y][this->x + 1] != 'x') {
		validSuccessorCount++;
		successorLocations.push_back(pair<int,int>(this->x+1, this->y));
	}

	if ((this->y - 1) != -1 && grid[this->y - 1][this->x] != '+' && grid[this->y - 1][this->x] != 'x') {
		validSuccessorCount++;
		successorLocations.push_back(pair<int,int>(this->x, this->y-1));
	}

	if ((this->x - 1) != -1 && grid[this->y][this->x - 1] != '+' && grid[this->y][this->x - 1] != 'x') {
		validSuccessorCount++;
		successorLocations.push_back(pair<int,int>(this->x - 1 , this->y));
	}


	// Creating state objects for valid successors
	State** stateOutList = new State*[validSuccessorCount+1];

	for (int i = 0; i < validSuccessorCount; ++i) {
		pair<int, int> temp =  successorLocations.at(i);
		int tempX = temp.first;
		int tempY = temp.second;
		double tempC;
		switch(this->mode) {
			case 'e':
				tempC = CostCalc::EuclidCost(tempX, tempY, gx, gy);
				break;
			case 'E':
				tempC = CostCalc::AStarEuc(tempX, tempY, this->cost, gx, gy);
				break;
			case 'm':
				tempC = CostCalc::ManhattanCost(tempX, tempY, gx, gy);
				break;
			case 'M':
				tempC = CostCalc::AStarMan(tempX, tempY, this->cost, gx, gy);
				break;
			default:
				break;
		}
		stateOutList[i] = new State(tempX, tempY, this->mode, tempC, this->steps + 1, this);
	}
	stateOutList[validSuccessorCount] = NULL;

	return stateOutList;

}

// Returns the State's x coordinate
int State::GetX() {
	return this->x;
}

// Returns the State's y coordinate
int State::GetY() {
	return this->y;
}

// Returns the State's cost
double State::GetCost() {
	return this->cost;
}

// Returns the State's steps
int State::GetSteps() {
	return this->steps;
}

// Returns a pointer to the State's parent
State* State::GetParent() {
	return this->parent;
}
