#ifndef RANDOMBASE_H
#define RANDOMBASE_H
#include <cstdlib>
using namespace std;
class randomBase
{
public:
	void seed(unsigned int numb); //sets the seed to the random number generator
protected:
	int randNum(int sides); //return a number between 1 and "sides"
};
#endif
