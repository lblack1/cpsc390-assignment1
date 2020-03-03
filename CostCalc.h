#ifndef COSTCALC
#define COSTCALC

#include <iostream>
#include "State.h"

using namespace std;

// A class that condenses the cost evaluation techniques to allow for easy switching between search algorithms.
class CostCalc {

	public:
		static double EuclidCost(int x, int y, int gx, int gy);
		static double ManhattanCost(int x, int y, int gx, int gy);
		static double AStarEuc(int x, int y, double parCost, int gx, int gy);
		static double AStarMan(int x, int y, double parCost, int gx, int gy);

};

#endif