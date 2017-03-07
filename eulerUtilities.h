#ifndef EULER_UTILITIES_H
#define EULER_UTILITIES_H

#include "eulerNumbers.h"
#include <sstream>		  //stringstream
#include <string.h>     //string

using namespace std;

//used in problem 3, problem 7, problem 10
//PRE: num defined 1< num 
//POST: Returns true if number is prime
bool isPrime(long int num) {
	bool isPrime = true;
	long int checkFac = TWO; // starts at two	
	if(num == ONE) {//if wanted to include 1 in primes, remove this
		isPrime = false;
	}
	//check each possible factor to see if prime
	while((checkFac <=(num / TWO)) && (isPrime == true)) {
		if(num % checkFac == ZERO) {// if checkfactor is a factor
			isPrime = false; //number is not prime
		}//end if
		checkFac ++;
	}//end while
	return(isPrime);
};

//used in problem 1
//PRE: num is an integer
//     mul is either 3 or 5 for Fizzbuzz but can be
//	any integer for this function
//POST: Returns true if num is a multiple of mul
// 	note: checks to see if num mod mul equals zero.
//	If yes, then num is a multiple of mul
bool isMultiple(int num, int mul) {
	bool isMult = false;
	if(num % mul == 0) { // if mul is multiple of num
		isMult = true;
	}	
	return (isMult);
};

//PRE: num defined, charNum allocated with enough indices
//			length defined
//POST: length number of chars now in charNum array
void intToCharArray(int num, char* charNum, int &length) {
	string strNum = "";
	stringstream ss;
	ss << num;                        //put value in string stream
	strNum = ss.str().c_str();        //put in string
	length = strNum.size();           // how many digits in num
	strcpy(charNum, strNum.c_str());  //copy string to char array
};


//used in problem 17
//PRE: num defined, between 1 and 1000
//POST: Number of letters in num returned
// ie five = 4 letters, ten = 3 letters
int getNumLetters(int num) {
	int numLetInHundred = SEVEN; 			// 'hundred' has 7 letters
	int numLetInAnd = 		THREE; 		  // 'and' has 3 letters
	int retValue = 				ZERO; 			//to hold return	
	// array to hold values for 0-9
	//nmLet[0] = none
	//nmLet[1] = two = 3
	int nmLet[TEN] = {0,3,3,5,4,4,3,5,5,4};	
	
	//array to hold values for 10-19
	//nmLetTeen[0] = ten = 3
	//nmLetTeen[1] = eleven = 6
	int nmLetTeen[TEN] = {3,6,6,8,8,7,7,9,8,8};//---------------what about 'ten'??
	
	//array to hold values for 20, 30, 40 ... 80, 90
	//nmLetTens[0,1] = 0 (void)
	//nmLetTens[3] = thirty = 6
	//nmLetTens[4] = forty = 5
	int nmLetTens[TEN] = {0,0,6,6,5,5,5,7,6,6};
		
	int hunPlace = num / ONEHUNDRED;
	int tensPlace = (num % ONEHUNDRED) / TEN;
	int onesPlace = num % TEN;

	if(num == ONETHOUSAND) {// num = 1000
		retValue = ELEVEN;
	}
	
	else {//num not 1000
		if(hunPlace > ZERO) {
			//assert: num > 100
			retValue = nmLet[hunPlace] + numLetInHundred;//add letters for 'hundred'
			if(num % ONEHUNDRED != ZERO) {
				//assert num is not X00
				retValue = retValue + numLetInAnd;//add letters for 'and'
			}
			//assert: rv = num letters in hundreds place, num letters in 'hundred'
			//				and num letters in 'and' if needed
		}//end if hundreds
		if(tensPlace > ONE) {
			//assert: num is X1X - X9X
			retValue = retValue + nmLetTens[tensPlace];
		}//end if tens	
		if(tensPlace == ONE) {
			//assert: num is X1X
			retValue = retValue + nmLetTeen[onesPlace];
		}//end if teens	
		else {//num doesn't have teen
			retValue = retValue + nmLet[onesPlace];
		}//end ones
	}
	//RV = arr3[num / 100] + arr2[((num % 100) / 10)] + arr1[num % 10];
	return(retValue);
};

#endif
