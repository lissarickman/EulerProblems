//Special Pythagorean triplet
//Problem 9

//A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
//a2 + b2 = c2

//For example, 32 + 42 = 9 + 16 = 25 = 52.

//There exists exactly one Pythagorean triplet for which a + b + c = 1000.
//Find the product abc.


#include <math.h>       /* sqrt */
#include <iostream>     // std::cout, std::end
#include "eulerNumbers.h"

using namespace std;

void phyTriple(int num){
	int a = 1;
	int b = 2;
	int c = 3;
	bool found = false; //this only used for printing solution, could eliminate if printed when found
	int product = 0;
	int aFinal;
	int bFinal;
	int cFinal;
	int aIndex = 0; //dont really need these but wanted to be able to retain
	int bIndex = 0; // indices of found values
	int cIndex = 0; // in case something else was required
	for(aIndex = 0; (aIndex + a) < (bIndex + b); aIndex++) { // given a < b < c thus next value provides ceiling for previous value
		for(bIndex = 0; (bIndex + b) < (cIndex + c); bIndex++) {
			for(cIndex = 0; (cIndex + c) < sqrt(num); cIndex++) {
				product = (((a + aIndex) * (a + aIndex))+((b + bIndex) * (b + bIndex)) + ((c + cIndex) * (c + cIndex)));
				if(product == num) { //found triple, could put cout here instead of at bottom and wouldn't need to retain indices
					aFinal = (a + aIndex);
					bFinal = (b + bIndex);
					cFinal = (c + cIndex);
					found = true;
					break; //<--------------------------------------------------------------------------------------------------------------fix this!!
				}
			}
		}
	}//everything below could be elminated if printed in if statement above, retained in case wanted to return indices
	if(found) {
		cout << "Found Pythagorean triplet!!!   " << aFinal << " * " << bFinal << " * " << cFinal << " = " << num <<  endl;
	}
	else {
		cout << "Not found" << endl;
	}
	
}
int main() {
	int givenNum;
	cout << "Enter number to find if a Pythagorean triplet" << endl;
	cin >> givenNum;
	phyTriple(givenNum);
}
