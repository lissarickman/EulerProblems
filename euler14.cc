/*
Longest Collatz sequence
Problem 14

The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1) 
* contains 10 terms. Although it has not been proved yet (Collatz Problem), 
* it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.

*/
#include <iostream>     // std::cout, std::end
#include "eulerNumbers.h"

using namespace std;

//PRE: num defined 2 < num 
//POST: Returns number of elements in num's collatz chain
int collatz(long int num) {
	int chainNum = 0;
	while(num > 1) {
		if(num % 2 == 0) {//num is even
			num = num/2;
		}
		else { //num is odd
			num = 3 * num + 1;
		}
		chainNum++;
	}
	return(chainNum);
}

//PRE:
//POST: Displays number (number < one million) with the largest collatz chain
int main() {
	int numInChain = 0;
	int highestNumChain = 0;
	int numWithHighestChain = 0;
	for(long int i = TWO; i < ONEMILLION; i++) {
		numInChain = collatz(i);
		if(numInChain > highestNumChain) {
			highestNumChain = numInChain;
			numWithHighestChain = i;
		}
	}//end for
	cout << "Most numbers in collatz chain is: " << numWithHighestChain;
	cout << " with " << highestNumChain << " values in chain" << endl;
	return(0);
}
