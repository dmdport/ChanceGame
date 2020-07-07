#include "aCoin.h"

aCoin::aCoin()
{
	sides = 2; //defines sides as 2
}

aCoin::operator int() //converstion operator that returns flip()
{
	return aCoin::randNum(sides); //passes over the number of sides of a coin to allow the randomBase to either return a 1 or 2
}
