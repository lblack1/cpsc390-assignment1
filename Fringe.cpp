#include "Fringe.h"
#include "State.h"
#include <iostream>
#include <vector>

using namespace std;

/** The Constructor
*/
Fringe::Fringe() {

	fringeQueue = new vector<State*>();
	closedList = new vector< pair<int, int>* >();

}

/** The Destructor
*/
Fringe::~Fringe() {

	delete fringeQueue;
	for (int i = 0; i < closedList->size(); ++i) {
		delete closedList->at(i);
	}
	delete closedList;

}

/** Inserts a state into the queue in a location based on cost.
* PARAMS
*	State* s: A pointer to a State to be inserted
*/
void Fringe::insert(State* s) {

	if (visited(s)) {
		return;
	} else {
		int i = 0; 
		while (i < fringeQueue->size() && fringeQueue->at(i)->GetCost() < s->GetCost()) {
			++i;
		}
		vector<State*>::iterator iter = fringeQueue->begin() + i;
		fringeQueue->insert(iter, s);
		return;
	}

}

/** Inserts multiple States to the queue
* PARAMS
*	State** s: An array of pointers to States.
*/
void Fringe::insert(State** s) {

	int i = 0;
	while (s[i] != NULL) {
		insert(s[i]);
		i++;
	}

}

/** Removes and returns the first element in the queue
* RETURNS
*	State*: A pointer to the least expensive state in the queue
*/
State* Fringe::pop() {

	State* temp = NULL;
	if (fringeQueue->size() > 0) {
		temp = fringeQueue->front();
		fringeQueue->erase(fringeQueue->begin());
		int tempX = temp->GetX();
		int tempY = temp->GetY();
		closedList->push_back(new pair<int,int>(tempX, tempY));
	}
	return temp;

}

/** Determines whether a location on the grid has been visited or not
* PARAMS
*	State* s: The State in question
* RETURNS
*	bool: true if s has been visited, false otherwise
*/
bool Fringe::visited(State* s) {
	
	int tempX = s->GetX();
	int tempY = s->GetY();
	for (int i = 0; i < closedList->size(); ++i) {
		if (tempX == closedList->at(i)->first && tempY == closedList->at(i)->second) {
			return true;
		}
	}
	return false;

}