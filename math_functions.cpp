#include "math_functions.h"

//Shittastic random number generator. It's barely pseudo random.
int nRandom(int nMin, int nMax)
{

	/* initialize random seed: */
	srand(time(NULL));
	int iRand = rand() % nMax + nMin;

	return iRand;
}