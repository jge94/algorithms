// ape.cpp
// class Ape, derived from class Monkey

#include "stdafx.h"
#include <iostream>
//#include "monkey.h"
#include "ape.h"

using namespace std;

Ape::Ape()
{
	cout << "Hello, I'm the constructor from class Ape that takes NO parameters. (default CTOR)" << endl;
}
Ape::Ape(bool variable)
{
	cout << "Hello, I'm the constructor from class Ape that takes parameters (bool) variable." << endl;
}

Ape::~Ape()
{
	cout << "Hello, I'm the destructor from class Ape that takes NO parameters." << endl;
}

void Ape::eatBanana(void)
{
	cout << "Hello, I'm function eatBanana from class Ape" << endl;
}

void Ape::scratchHead(void)
{
	cout << "Hello, I'm function scratchHead from class Ape" << endl;
}

void Ape::hasABrain(void)
{
	cout << "function hasABrain from class Ape" << endl;
}