#include "aDie.h"

aDie::aDie()
{
	sides = 6; //assigns sides to 6
}

aDie::operator int() //converstion operator returning roll()
{
	return aDie::randNum(sides); //passes over number of sides on a die to allow randomBase to return numbers 1-6
}
