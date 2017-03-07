// Largest palindrome product
// Problem 4

// A palindromic number reads the same both ways. 
// The largest palindrome made from the product of 
// two 2-digit numbers is 9009 = 91 × 99.

//Find the largest palindrome made from 
//the product of two 3-digit numbers.


//Notes:
// boundries 100*100 (10,000) is floor
//					 999*999 (998,001) is ceiling
// highest possible palindrome 989,989
// valid palindrome solutions are: 10001, 20002, 30003 ...
//																	100001, 200002, 300003 ... 900009

#include <iostream>     // std::cout, std::end
#include <sstream>		  //stringstream
#include <string.h>     //string
#include "eulerNumbers.h"
#include "eulerUtilities.h" // int to char array
using namespace std;


//PRE:  num defined, 100*100 <= num >= 999*999
//			NUM_CHAR defined in .h file
//			note: puts int into char array because itoa not available on linux
//POST: Returns true if strNum is a palindrome
bool isPalindrome(int num) {
	char charNum[NUM_CHAR];            //seven because largest ppossible is 6 digits
	int size = 0;                      //num digits in num
	intToCharArray(num, charNum, size);
	//ASSERT: charNum now contains num's digits as chars
	bool isPal = false;
	bool isDone = false;
	while(isDone == false) {
		for(int i = 0; i <= size/2; i++) {
			if((isDone == false) && (charNum[i] == charNum[(size - 1 - i)])) {
				isPal= true;
				if(i >= size/2) {
					isDone = true;
				}			
			}//end if
			else {
				isPal = false;
				isDone = true;
			}
		}//end for
	}//end while
	return(isPal);
}

//PRE:
//notes: starts at 999 and descends due to searching for the largest 
//				NINENINENINE defined in .h file
//POST: Largest 3 digit palindrome displayed
int main(int argc, char * argv[]) {
	int fNum = NINENINENINE; //starts with both values 999
	int sNum = NINENINENINE;
	int curHigh = 0;
	bool isPalin = false;
	bool isDone = false;
	int checkNum = 0;
	while(fNum >= ONEHUNDRED && sNum >= ONEHUNDRED) {
		checkNum = fNum * sNum;
		isPalin = isPalindrome(checkNum);		
		if(isPalin) { //check num is palindrome
			if(curHigh < checkNum) {
				curHigh = checkNum; //curHigh contains current highest palindrome
			}
		}
		sNum = sNum - 1;
		if(sNum < ONEHUNDRED) {
			fNum = fNum - 1; //decreased the first number by one
			sNum = fNum - 1; //resets the 2nd number to first number -1 to eliminate checking repeats
		}			
	}//end while
	cout << "The largest palindrome product for two three digit numbers is " << curHigh << endl;
	return(0);
}
