/* 
Lattice paths
Problem 15

Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?
*/

#include <iostream>     // std::cout, std::end
#include "eulerNumbers.h"
using namespace std;

//THIS PROGRAM TAKES A LOOOONNNNNGGGGGG TIME FOR SIZE = 20

// Seriously, you have been warned, its run for almost 24 hours
// so far and has yet to display the result (I double checked the
//	logic, it is correct)

//notes: this is VERY slow as it goes through every possible solution,
//        much quicker ways possible but wanted to do it recursively 
//				since I have done so little recursion as of late

//PRE: grid size defined, row position and col position start at 0,0
//      total routes passed by reference
//POST: totalRoutes contains number of routes possible
void transverseGrid(int gSize, int rowPos, int colPos, unsigned long long int &totalRoutes) {
	if(rowPos == gSize && colPos == gSize) {//base case 
		totalRoutes++;
		//cout << "routes = " << totalRoutes << endl;
	}
	else {//recursive case
		if(rowPos <  gSize) {//go down row
			transverseGrid(gSize, rowPos + 1, colPos, totalRoutes);
		}
		if(colPos < gSize) {//go right column
			transverseGrid(gSize, rowPos, colPos + 1, totalRoutes);
		}
	}
}

int main() {
	int gridSize = 0;
	unsigned long long int numRoutes = 0;
	cout << "Please enter a size for the grid" << endl;
	cin >> gridSize;
	transverseGrid(gridSize, 0, 0, numRoutes);
	cout << "There are " << numRoutes << " routes for a " << gridSize << " sized grid" << endl;
}
