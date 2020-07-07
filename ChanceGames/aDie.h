#ifndef ADIE_H
#define ADIE_H
#include <cstdlib>
#include "randomBase.h"
#include "histogramBase.h"
class aDie : public randomBase, public histogramBase
{
public:
	aDie(); //constructor
	operator int(); //converstion operator returning roll
private:
	int sides; //allows to potentially create a die with more sides
};
#endif
