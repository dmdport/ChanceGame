#ifndef ACOIN_H
#define ACOIN_H
#include <cstdlib>
#include <string>
#include "randomBase.h"
#include "histogramBase.h"
using namespace std;
class aCoin : public randomBase, public histogramBase //inherits from randomBase and histogramBase
{
public:
	aCoin(); //constructor
	operator int(); //converstion operator returning flip()
private:
	int sides;
};
#endif
