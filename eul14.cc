#include <iostream>     // std::cout, std::end
#include "eulerNumbers.h"


using namespace std;

int main() {
const int number = 1000000;
 
long sequenceLength = 0;
long startingNumber = 0;
long sequence;
 
for (int i = 2; i <= number; i++) {
    int length = 1;
    sequence = i;
    while (sequence != 1) {
        if ((sequence % 2) == 0) {
            sequence = sequence / 2;
        } else {
            sequence = sequence * 3 + 1;
        }
        length++;
    }
 
    //Check if sequence is the best solution
    if (length > sequenceLength) {
        sequenceLength = length;
        startingNumber = i;
    }
}
cout << "value : " << startingNumber << " has the longest chain with " << sequenceLength << endl;
}
