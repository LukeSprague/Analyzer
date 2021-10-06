#include <iostream>
#include <vector>
#include "StringData.h"

using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::endl;

int linearSearch(vector<string> dataSet, string element){
    for(int i = 0; i<dataSet.size(); i++) {
        if (0==element.compare(dataSet[i])) {
            return i;
        }
    }
    return -1;
}

//checks if a is "greater" than b as according to lexical order
bool isGreater(string a, string b) {

    char aArray [a.length()];
    char bArray [b.length()];

    for(int i=0; i<a.length(); i++) {
        aArray[i] = a[i];
    }
    for(int i=0; i<b.length(); i++) {
        bArray[i] = b[i];
    }

    int index;

    //check which String is longer so that the comparison loop doesn't iterate over one of the string's indicies
    if(a.length()<b.length()) {
        index = a.length();
    }
    else if(b.length()<a.length()) {
        index = b.length();
    }
    //if they're the same size, then they must be of size 5, since the String.getData() only gets 5 character strings
    else {
        index = 5;
    }

    //compare members of each string as a char array
    for(int i=0; i<index; i++) {
        if(aArray[i] > bArray[i]) {
            return true;
        }
    }
    return false;
}

int binarySearch(vector<string> dataSet, string element){
    int min = 0;
    int max = dataSet.size()-1;
    int midPoint = min + (max-min)/2;

    while(min<=max) {

        if(0==dataSet[midPoint].compare(element)) {
            return midPoint;
        }

        //check if search term is less than midpoint
        else if(isGreater(dataSet[midPoint], element)) {
            max = midPoint-1;
            midPoint = min + (max-min)/2;
        }
        //check if search term is greater than midpoint
        else if(isGreater(element, dataSet[midPoint])) {
            min = midPoint+1;
            midPoint = min + (max-min)/2;
        }
    }
    return -1;
}


int main() {
        vector<string> data = getStringData();

        cout << "Linear search for not_here..." << endl;
        long start = systemTimeNanoseconds();
        linearSearch(data, "not_here" );
        long finish = systemTimeNanoseconds();
        cout << "Total time: " << (finish-start) << endl;

        cout << "Binary search for not_here..." << endl;
        start = systemTimeNanoseconds();
        binarySearch(data, "not_here" );
        finish = systemTimeNanoseconds();
        cout << "Total time: " << (finish-start) << endl;

        cout << "Linear search for mzzzz..." << endl;
        start = systemTimeNanoseconds();
        linearSearch(data, "mzzzz" );
        finish = systemTimeNanoseconds();
        cout << "Total time: " << (finish-start) << endl;

        cout << "Binary search for mzzzz..." << endl;
        start = systemTimeNanoseconds();
        binarySearch(data, "mzzzz" );
        finish = systemTimeNanoseconds();
        cout << "Total time: " << (finish-start) << endl;

        cout << "Linear search for aaaaa..." << endl;
        start = systemTimeNanoseconds();
        linearSearch(data, "aaaaa" );
        finish = systemTimeNanoseconds();
        cout << "Total time: " << (finish-start) << endl;

        cout << "Binary search for aaaaa..." << endl;
        start = systemTimeNanoseconds();
        binarySearch(data, "aaaaa" );
        finish = systemTimeNanoseconds();
        cout << "Total time: " << (finish-start) << endl;
    return 0;
}

