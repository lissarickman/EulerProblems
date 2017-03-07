//10001st prime
//Problem 7

//By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

//What is the 10,001st prime number?

#include <iostream>     // std::cout, std::end
#include "eulerNumbers.h"
#include "eulerUtilities.h" //isPrime()

using namespace std;

//POST: Displays 10,001th prime
int main() {
	int maxPrimeNum = TEN_THOUS_ONE;
	int numPrime = 0;
	int ckValue = 2;
	while(numPrime < maxPrimeNum) {
		if(isPrime(ckValue)) {
			numPrime++;
		}
		ckValue++;
	}
	cout << numPrime << " numbered prime is " << ckValue << endl;
}
