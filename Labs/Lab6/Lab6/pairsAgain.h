#ifndef _PAIRSAGAIN
#define _PAIRSAGAIN

#include "stdafx.h"
#include <iostream>

using namespace std;

class pairsAgain
{
public:
	pairsAgain();
	pairsAgain(int a, int b);

	// ----------------- Operators-------------------
	bool operator==(/*inout*/pairsAgain& pairsAgain2);             // Equal to
	bool operator<(/*inout*/pairsAgain& pairsAgain2);              // Less than
	bool operator>(/*inout*/pairsAgain& pairsAgain2);              // Greater than
	bool operator<=(/*inout*/pairsAgain& pairsAgain2);             // Less than or equal to
	bool operator>=(/*inout*/pairsAgain& pairsAgain2);             // Greater than or equal to

	int val1, val2;
};

#endif