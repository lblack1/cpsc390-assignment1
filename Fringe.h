#ifndef FRINGE
#define FRINGE

#include <iostream>
#include <vector>
#include "State.h"

// Fringe - A queue with best-first insertion based on cost, plus a list of visited states to prevent adding duplicates
class Fringe {

	public:
		Fringe();
		~Fringe();

		void insert(State* s);
		void insert(State** s);
		State* pop();
		bool visited(State* s);

	private:
		vector<State*>* fringeQueue;
		vector< pair<int, int>* >* closedList;

};

#endif
