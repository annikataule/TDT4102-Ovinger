#include "utilities.h"
#include "std_lib_facilities.h"

int randomWithLimits(int min, int max)
{
	return rand() % (max - min + 1) + min;;
}

