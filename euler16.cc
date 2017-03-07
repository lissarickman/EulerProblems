/*
Power digit sum
Problem 16

215 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 21000?
*/
#include <iostream>
#include <string>
#include <stdlib.h>     /* atoi */
#include <sstream>      // std::stringstream
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

//PRE: base and exp defined, base > 1, exp >1 
//POST: base ^ exp = returned value
BigInteger doExp(int base, int exp) {
	BigInteger retValue = 1;
	for(int i = 0; i < exp; i++) {
		retValue = retValue * base;
	}
	return(retValue);
}

//PRE: num defined
//POST: return value is sum of digits of num
int sumDigits(BigInteger num) {
	int reValue = 0;
	stringstream ss;
	ss << num;
	string tempString = ss.str();
	int length = tempString.length();
	for(int i = 0; i < length; i++) {
		char curChar = tempString[i];
		//curChar = tempString.at(i);
		reValue = reValue + (curChar - '0');
	}
	return(reValue);
}

int main() {
	cout << " *************** " << endl;
	cout << "To get the sum of the digits of an exponential" << endl;
	cout << "Please enter base" << endl;
	int base;
	cin >> base;
	cout << "Please enter exponent" << endl;
	int exp;
	cin >> exp;
	BigInteger tempValue = doExp(base, exp);
	int sum = sumDigits(tempValue);
	cout << "The sum of the digits of " << base << "^" << exp << " is: " << sum << endl;
	return(0);
}
