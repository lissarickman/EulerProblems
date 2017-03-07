/*
Number letter counts
Problem 17

If the numbers 1 to 5 are written out in words: 
one, two, three, four, five, then there are 
3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) 
inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 
342 (three hundred and forty-two) contains 23 letters 
and 115 (one hundred and fifteen) contains 20 letters. 
The use of "and" when writing out numbers is in compliance 
with British usage.

*/

#include "eulerNumbers.h"
#include <iostream>
#include "eulerUtilities.h" //getNumLetters()

using namespace std;

//PRE:
//POST: Displays the total number of letters from 1 -> a given number
//			ex: 5 = one(3) + two(3) + three(5) + four(4) + five(4) = 
//			3 + 3 + 5 + 4 + 4 = 19
int main(int argc, char* argv[]) {
	bool finished = false;
	int givenNum = 0;

	cout << "Number letter counts" << endl;
	cout << "Program will add the letters of numbers from 1";
	cout << " -> given number " << endl;
	cout << endl;
	
	while(!finished) {
		int numberLetters = 0; //hold numbers # letters
		long int totalLetters = 0; //hold total # letters
		cout << "        --------------------         " << endl;
		cout << endl;
		cout << "Please enter a number between 1 and 1000" << endl;
		cout << "Enter 0 to quit" << endl;
		cin >> givenNum;
		if((givenNum > ZERO) && (givenNum <= ONETHOUSAND)) {		
			for(int i = 1; i <= givenNum; i++) {
				numberLetters = getNumLetters(i);
				totalLetters = totalLetters + numberLetters;
				//cout << i << " has " << numberLetters << 
				//cout << " letters. Total = " << totalLetters << endl;
			}
			cout << "The total letters for 1 -> " << givenNum << " is: " << totalLetters << endl;
		}
		else {//number invalid or given quit command (entering 0)
			finished = true;
		}
	}
	return(0);
}


