#cpsc390-assignment1
A Search Agent AI

Lloyd Black
2295968
CPSC390
Erik Linstead

A program that takes in a text file, constructs a map from it, and runs a search agent from the indicated inital state to the goal state to find the shortest path.

1. Source Files - main.cpp, BuggeredFormatException.h, BuggeredFormatException.cpp, CostCalc.h, CostCalc.cpp, FileNotFoundException.h, FileNotFoundException.cpp, Fringe.h, Fringe.cpp, Simulation.h, Simulation.cpp, State.h, State.cpp

2. Issues - None that I've found but I'm very tired so probably some somewhere.

3. Resources - cplusplus.com/reference, stackoverflow, in-class lecture notes.

4. Description of Program - Takes in a text file as input (with the first line indicating size of the map and subsequent lines representing the map, as in sample.txt), then runs four search algorithms against the map to find paths to the goal.

5. After compiling - ./<executable> <textfile>