//Sum square difference
//Problem 6

//The sum of the squares of the first ten natural numbers is,
//1^2 + 2^2 + ... + 10^2 = 385

//The square of the sum of the first ten natural numbers is,
//(1 + 2 + ... + 10)^2 = 55^2 = 3025

//Hence the difference between the sum of the squares of the first 
// ten natural numbers and the square of the sum is 3025 − 385 = 2640.

//Find the difference between the sum of the squares of the first one 
// hundred natural numbers and the square of the sum.


#include <iostream>     // std::cout, std::end
#include "eulerNumbers.h"

using namespace std;

//PRE:
//POST: Sum of the squares for first 100 natural numbers returned
//			ie 1^2+2^2+3^2...+100^2
int sumSquare(int max) {
	int sum = 0;
	for(int i = 1; i <= max; i++) {
		sum = sum + (i * i);
	}
	return(sum);
}

//PRE:
//POST: Returns square of sum for first 100 natural numbers squared
//			ie (1+2+3...+100)^2
int squSum(int max) {
	int sum = 0;
	int sqSum = 0;
	for(int i = 1; i <= max; i++) {
		sum = sum + i;
	}
	sqSum = sum*sum;
	return(sqSum);
}

int main(int argc, char* argv[]) {
	int suSq = 0; //sum of squares
	int sqSu = 0; //sum squared
	suSq = sumSquare(ONEHUNDRED);
	sqSu = squSum(ONEHUNDRED);
	cout << "Sum of squares = " << suSq << endl;
	cout << "Square of sum = " << sqSu << endl;
	cout << "Difference between is " << (sqSu - suSq) << endl;
}
