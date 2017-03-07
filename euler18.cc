/*
Maximum path sum I
Problem 18

By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

                         75
                        95 64
                       17 47 82
                     18 35 87 10
                   20 04 82 47 65
                 19 01 23 75 03 34
               88 02 77 73 07 63 67
             99 65 04 28 06 16 70 92
           41 41 26 56 83 40 80 70 33
         41 48 72 33 47 32 37 16 94 29
       53 71 44 65 25 43 91 52 97 51 14
     70 11 33 28 77 73 17 78 39 68 17 57
   91 71 52 38 17 14 91 43 58 50 27 29 48
 63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)
*/

#include "eulerNumbers.h"
#include <iostream>
#include <fstream>
using namespace std;

/*void printArrayAsTriangle(int * array, int nValues, int nRows) {
	for(int i = 0; i < nValues; i++) {//array index
		for(int j = nRows; j >= 0; j--) {
			cout << " ";
		}
		for(int rowNum = 0; rowNum < nRows;) {
			cout << array[i] << " ";
			if(rowNum == i) {
				cout << endl;
				rowNum = rowNum + i;
			}
		}
		
	}
}
//POST: Each row one more element than next
void printTriangle(int* array, int numVal, int numR) {
	for(int i = 0; i < numVal; i++) {
		cout << array[i] << " ";
	}
}
* */

void printArray(int* array, int nValues, int nRows) {
	cout << endl;
	int r = 0;//row index
	int a = 0;//array index
	int curLine = 0;
	int incLine = 1;
	int s = 0;
	for(int i = 0; i < nValues; i++) {	
		if(r == curLine) {
			cout << endl;
			//print nRow - r spaces
			s = 0;
			while(s < nRows - r) {//<<<<<<<<<<<<<<<<<<<< issue here
				cout << " ";
				s++;
			}
			
			curLine = curLine + incLine;
			incLine++;
		}
		cout << array[i] << " ";
		r++;
	}
}

int main(int argc, char* argv[]) {
	int numRows = FIFTEEN;
	int numValues = 0;
	for(int i = 0; i <= numRows; i++ ) {
		numValues = numValues + i;
	}
	cout << "Num values = " << numValues << endl;
	int valueArray[120];
	int * arrPtr = valueArray;
	ifstream infile;
	infile.open("euler18Values.txt");
	for(int i = 0; i < numValues; i++) {
		infile >> valueArray[i];
	}
	infile.close();
	printArray(valueArray, numValues, numRows);
	return(0);
}
