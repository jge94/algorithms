
#include "stdafx.h"
#include <iostream>
#include "pairsAgain.h"

pairsAgain::pairsAgain()
{
	this->val1 = NULL;
	this->val2 = NULL;
}

pairsAgain::pairsAgain(int a, int b)
{
	this->val1 = a;
	this->val2 = b;
}

bool pairsAgain::operator==(/*inout*/pairsAgain& pairsAgain2)             // Equal to
{
	if (this->val1 == pairsAgain2.val1)
		return true;
	else
		return false;
}

bool pairsAgain::operator<(/*inout*/pairsAgain& pairsAgain2)              // Less than
{
	if (this->val1 < pairsAgain2.val1)
	{
		return true;
	}
	else
		return false;
}

bool pairsAgain::operator>(/*inout*/pairsAgain& pairsAgain2)              // Greater than
{
	return pairsAgain2 < (*this);
}

bool pairsAgain::operator<=(/*inout*/pairsAgain& pairsAgain2)             // Less than or equal to
{
	return ((*this) < pairsAgain2 || (*this) == pairsAgain2);
}

bool pairsAgain::operator>=(/*inout*/pairsAgain& pairsAgain2)             // Greater than or equal to
{
	return ((*this) > pairsAgain2 || (*this) == pairsAgain2);
}