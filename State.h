#ifndef STATE_H
#define STATE_H

#include "CostCalc.h"
#include <iostream>
#include <vector>

// State - evaluation operators, successor function
using namespace std;

class State {

	public:

		State(int x, int y, char mode, double cost, int steps, State* parent); 

		State** GetSuccessors(int gx, int gy, int mapsize, char** grid);

		int GetX();
		int GetY();
		double GetCost();
		int GetSteps();
		State* GetParent();

		bool operator==(const State& s) {
			return (this->x == s.x && this->y == s.y);
		}
		bool operator<(const State& s) {
			return cost < s.cost;
		}

	private:
		int x;
		int y;
		char mode;
		double cost;
		int steps;
		State* parent;

};

#endif
