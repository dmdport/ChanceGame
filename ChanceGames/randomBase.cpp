#include "randomBase.h"

void randomBase::seed(unsigned int numb) //sets the seed to the random number generator
{
	srand(numb);
}

int randomBase::randNum(int sides) //return a number between 1 and "sides"
{
	return rand() % sides + 1;
}