//Smallest multiple
//Problem 5

//2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

//What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

// notes: 
//lowest possible is 20

#include <iostream>     // std::cout, std::end
#include "eulerNumbers.h"
#include <cstdlib> //atoi


using namespace std;

//PRE: 
//POST: smallest number evenly divisible by values 1->XX is displayed
//			note: XX = user given value, else 20
int main(int argc, char* argv[]) {
	bool finished = false;
	int curValue = 0;
	int tempValue = 0;
	if(argc == 2 && argv[1] > 0) {             //value given by user
		curValue =  atoi(argv[1]);  						 // convert to int
	}
	else {
	 curValue = TWENTY;                        //value not given, use 20
 }
	tempValue = curValue;
	while(finished == false){
		for(int i = TWO; i <= tempValue; i++) {  //start at 2 as 1 divides all
			if(curValue % i != 0) {
				curValue = curValue + tempValue;
				i = TWO;															// resets i if not found
			}
			else {
				i++;
			}
			if(i > tempValue) {
				finished = true;
			}		
		}//end for
	}//end while
	cout << "The smallest number evenly divisible by 1 -> " << tempValue << " is " << curValue << endl;
}

