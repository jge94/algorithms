#include "stdafx.h"
#include <iostream>
#include "monkey.h"

using namespace std;

Monkey::Monkey()
{
	cout << "Hello, I'm the constructor from class Monkey that takes NO parameters. (default CTOR)" << endl;
}

// CTOR and DTOR
Monkey::Monkey(bool variable)
{
	cout << "Hello, I'm the constructor from class Monkey that takes parameters (bool) variable." << endl;
}

Monkey::~Monkey()
{
	cout << "Hello, I'm the destructor from class Monkey that takes NO parameters." << endl;
}

void Monkey::eatBanana(void)
{
	cout << "Hello, I'm function eatBanana from class Monkey" << endl;
}

// NO virtual???
void Monkey::scratchHead(void)
{
	cout << "Hello, I'm function scratchHead from class Monkey" << endl;
}

void Monkey::hasABrain(void)
{
	cout << "function hasABrain from class Monkey" << endl;
}
