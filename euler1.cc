// Fizzbuzz

// "Write a program that prints the numbers from 1 to 100. 
// But for multiples of three print “Fizz” instead of the 
// number and for the multiples of five print “Buzz”. 
// For numbers which are multiples of both three and 
// five print “FizzBuzz”."

#include <iostream>
using namespace std;

//PRE: num defined 1 < num < 9999
//POST: for each value 1 -> num, 
//      prints FIZZ if multiple of 3,
//      prints BUZZ if multiple of 5,
//      prints FIZZBUZZ if mulitiple of 3 & 5
//      else prints number
void fizzBuzz(int num) {
	for(int i = 0; i <= num; i++) {
		if(i % 3 == 0) {
			//ASSERT: num divisible by 3
			cout << "Fizz";
		}
		if(i % 5 == 0) {
			//ASSERT: num divisible by 5
			cout << "Buzz";
		}
		if (i % 3 != 0 && i % 5 != 0) {
			//ASSERT: num not divisible by 3 or 5
			cout << i;
		}
		cout << endl;
	}
}


//PRE: 
//POST: FIZZBUZZ run on user submitted value
int main(int argc, char * argv[]) {
	int userValue = 0;
	bool valueValid = false;
	while(!valueValid) {
		cout << "Please give a number between 1 and 9999" << endl;
		cin >> userValue;
		//ASSERT: userValue is number given by user
		if(userValue > 0 && userValue < 9999) {
			//NOTE: 9999 chosen arbitarily for simplicity
			valueValid = true;
		}
	}
	fizzBuzz(userValue);
	return (0);
}