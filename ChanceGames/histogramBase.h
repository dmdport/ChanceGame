#ifndef HISTOGRAMBASE_H
#define HISTOGRAMBASE_H
using namespace std;
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
class histogramBase
{
public:
	void calculate(vector<int> vect); //accepts a vector then calculates the value for each X for the histogram. Must be run before print
	void print(vector<int> vect, int gameType); //accepts a vector and then displays the data in form of a histogram

protected:
	double valueOfX = 0;
	double printedX;
};
#endif
