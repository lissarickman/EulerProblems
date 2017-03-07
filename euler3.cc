//Largest prime factor
//Problem 3

//The prime factors of 13195 are 5, 7, 13 and 29.

#include <iostream>     // std::cout, std::end
#include "eulerNumbers.h"
#include "eulerUtilities.h" //isPrime()
#include <cstdlib> //atoi

using namespace std;

//PRE: num defined
//POST: Returns largest prime factor of num
//			if 1 is returned, num is prime
long int largestPrimeFactor(long int num) {
	bool isFactor = false;
	bool isPri = false;
	long int checkFactor = num / TWO;//start with half num and decrease
	while((isFactor == false) && (isPri == false)
		 && (checkFactor > ONE)) {
		if(num % checkFactor == ZERO) {//if factor
			isFactor == true;//note:only need largest
			isPri = isPrime(checkFactor);
			if(isPri == false) {//if non prime factor, continue.
				//note: if prime factor, nothing else runs until the return statement
				checkFactor--;
				isFactor = false;       
			}//end if not prime
		}//end if factor
		else {	//not a factor
			checkFactor--;
		}//end if not factor
	}//end while
	return(checkFactor);
}

int main(int argc, char* argv[]) {
	long int numEntered = 0;
	long int lPrime = 0;
	
	if(argc == 2 && argv[1] > 0) { //number given when run
		numEntered = atoi(argv[1]);
	}	else { //need to obtain number
		cout << "Please enter a (positive) number to find the largest prime." << endl;
		cin >> numEntered;
	}
	lPrime = largestPrimeFactor(numEntered);
	cout << "The largest prime factor of " << numEntered;
	cout << " is: " << lPrime << endl;
	return(0);
}

