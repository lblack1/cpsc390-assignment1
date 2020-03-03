#include <iostream>
#include "State.h"
#include "Fringe.h"
#include "Simulation.h"

using namespace std;

/** Runs and prints output for the four different algorithms
*/
int main(int argc, char** argv) {


	if (argc != 2) {
		cout << "Usage: ./PathFinder <text file>" << endl;
		return 1;
	}

	string filename = argv[1];

	cout << endl;

	Simulation* sime = new Simulation(filename, 'e');
	cout << sime->ConstructOutput(sime->Run()) << endl << endl;

	Simulation* simE = new Simulation(filename, 'E');
	cout << simE->ConstructOutput(simE->Run()) << endl << endl;	

	Simulation* simm = new Simulation(filename, 'm');
	cout << simm->ConstructOutput(simm->Run()) << endl << endl;

	Simulation* simM = new Simulation(filename, 'M');
	cout << simM->ConstructOutput(simM->Run()) << endl << endl;

	return 0;

}
