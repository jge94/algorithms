#ifndef _INTEGERPAIRS
#define _INTEGERPAIRS

#include "stdafx.h"
#include <iostream>

using namespace std;

class integerPairs
{
	public:
		integerPairs();
		integerPairs(int a, int b);

		// ----------------- Operators-------------------
		bool operator==(/*inout*/integerPairs& integerPairs2);             // Equal to
		bool operator<(/*inout*/integerPairs& integerPairs2);              // Less than
		bool operator>(/*inout*/integerPairs& integerPairs2);              // Greater than
		bool operator<=(/*inout*/integerPairs& integerPairs2);             // Less than or equal to
		bool operator>=(/*inout*/integerPairs& integerPairs2);             // Greater than or equal to

		int value1, value2;
};

#endif