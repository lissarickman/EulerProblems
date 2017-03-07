//Summation of primes
//Problem 10

//The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

//Find the sum of all the primes below two million.

#include <iostream>     // std::cout, std::end
#include <sstream>		  //stringstream
#include <string.h>     //string
#include "eulerNumbers.h"
#include "eulerUtilities.h" //isPrime()

using namespace std;

//PRE: ceiling defined 
//POST: returns sum of all primes below ceiling
long int sumPrimes(long int ceiling) {
	long int sum = 0;
	for(int i = 0; i < ceiling; i++) {
		if(isPrime(i)) { //is prime, add to sum
			cout << "sum is: " << sum << " + " << i << endl;
			sum = sum + i;		
		}
	}	
	return(sum);
}

int main(int argc, char* argv[]) {
	long int givenValue = 0;
	long int sumOfPrimes = 0;
	cout << "Please give a number to add all primes below" << endl;
	cin >> givenValue;
	sumOfPrimes = sumPrimes(givenValue);
	cout << "The sum of primes below " << givenValue << " is : " << sumOfPrimes << endl;
}

