#include "CostCalc.h"
#include <iostream>
#include <cmath>

using namespace std;

/* The greedy Euclidian cost algorithm
* PARAMS
*	int x: The x-coordinate of the current state
*	int y: The y-coordinate of the current state
* 	int gx: The x-coordinate of the goal state
*	int gy: The y-coordinate of the goal state
* RETURNS
*	double: The cost of the current state
*/
double CostCalc::EuclidCost(int x, int y, int gx, int gy){
	double temp = sqrt( pow((gx-x), 2) + pow((gy-y), 2));
	return temp;
}

/* The greedy Manhattan cost algorithm
* PARAMS
*	int x: The x-coordinate of the current state
*	int y: The y-coordinate of the current state
* 	int gx: The x-coordinate of the goal state
*	int gy: The y-coordinate of the goal state
* RETURNS
*	double: The cost of the current state
*/
double CostCalc::ManhattanCost(int x, int y, int gx, int gy) {
	double temp = abs(gx-x) + abs(gy-y);
	return temp;
}

/* The A* Euclidian cost algorithm
* PARAMS
*	int x: The x-coordinate of the current state
*	int y: The y-coordinate of the current state
*	double parCost: Cost of the current state's parent
* 	int gx: The x-coordinate of the goal state
*	int gy: The y-coordinate of the goal state
* RETURNS
*	double: The cost of the current state
*/
double CostCalc::AStarEuc(int x, int y, double parCost, int gx, int gy) {
	double temp = parCost + EuclidCost(x, y, gx, gy);
	return temp;
}

/* The A* Manhattan cost algorithm
* PARAMS
*	int x: The x-coordinate of the current state
*	int y: The y-coordinate of the current state
*	double parCost: Cost of the current state's parent
* 	int gx: The x-coordinate of the goal state
*	int gy: The y-coordinate of the goal state
* RETURNS
*	double: The cost of the current state
*/
double CostCalc::AStarMan(int x, int y, double parCost, int gx, int gy) {
	double temp = parCost + ManhattanCost(x, y, gx, gy);
	return temp;	
}