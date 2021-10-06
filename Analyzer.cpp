#include <iostream>
#include <chrono>
#include <string>
#include "StringData.h"

using namespace std;

int linearSearch(vector<string> dataSet, string element)
{
    int result = -1;
    for (int i = 0; i < dataSet.size(); i++)
    {
        if(0==dataSet[i].compare(element))
        {
            result = i;
            break;
        }
    }
    return result;
}
int binarySearch(vector<string> dataSet, string element)
{
    int low = 0;
    int high = dataSet.size()-1;
    int mid;
    while (low <= high)
    {
        mid = (low+high)/2;
        if(dataSet[mid].compare(element) < 0)
        {
            low = mid+1;
        }
        else if(dataSet[mid].compare(element) > 0)
        {
            high = mid-1;
        }
        else
            return mid;
    }
    return -1;
}
void testSearch(std::string elem)
{
    long long beginTime = 0;
    long long endTime = 0;

    vector<string> data = getStringData();

    cout<<"Running linear Search searching for : " << elem;
    beginTime = systemTimeNanoseconds();
    long linear = (linearSearch(data, elem));
    endTime = systemTimeNanoseconds();
    cout<<linear;
    cout<<"The runtime for the linear search is : " << (endTime - beginTime) << "\n";
    cout<<"Running binary Search searching for : " << elem;
    beginTime = systemTimeNanoseconds();
    long binary = (binarySearch(data, elem));
    endTime = systemTimeNanoseconds();
    cout<<binary;
    cout<<"The runtime for the binary search is : " << (endTime - beginTime) << "\n\n";
}

int main() {
    testSearch("not_here");
    testSearch("mzzzz");
    testSearch("aaaaa");
    return 0;
}