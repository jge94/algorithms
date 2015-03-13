
#include "stdafx.h"
#include <iostream>
#include "integerPairs.h"

integerPairs::integerPairs()
{
	this->value1 = NULL;
	this->value2 = NULL;
}

integerPairs::integerPairs(int a, int b)
{
	this->value1 = a;
	this->value2 = b;
}

bool integerPairs::operator==(/*inout*/integerPairs& integerPairs2)             // Equal to
{
	if ((this->value1 == integerPairs2.value1) && (this->value2 == integerPairs2.value2))
		return true;
	else
		return false;
}

bool integerPairs::operator<(/*inout*/integerPairs& integerPairs2)              // Less than
{
	if (this->value1 < integerPairs2.value1)
	{
		return true;
	}
	else if ((this->value1 == integerPairs2.value1) && (this->value2 < integerPairs2.value2))
		return true;
	else
		return false;
}

bool integerPairs::operator>(/*inout*/integerPairs& integerPairs2)              // Greater than
{
	return integerPairs2 < (*this);
}

bool integerPairs::operator<=(/*inout*/integerPairs& integerPairs2)             // Less than or equal to
{
	return ((*this) < integerPairs2 || (*this) == integerPairs2);
}

bool integerPairs::operator>=(/*inout*/integerPairs& integerPairs2)             // Greater than or equal to
{
	return ((*this) > integerPairs2 || (*this) == integerPairs2);
}