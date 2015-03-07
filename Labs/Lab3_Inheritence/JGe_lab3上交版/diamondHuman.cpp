#include "stdafx.h"
#include <iostream>
#include "diamondParrot.h"
#include "ape.h"
#include "diamondHuman.h"

diamondHuman::diamondHuman()
{
	cout << "Hello, I'm the CTOR from class diamondHuman that takes NO parameters. (default CTOR)" << endl;
}

diamondHuman::diamondHuman(bool variable) : Ape(variable)
{
	cout << "Hello, I'm the CTOR from class diamondHuman should inherit class Ape: (bool) variable." << endl;
}

diamondHuman::diamondHuman(bool boolVar, char* charP) : Ape(boolVar), diamondParrot(charP)
{
	cout << "Hello, I'm the CTOR from class diamondHuman should inherit from " << endl;
	cout << "1) class Ape: (bool) variable." << endl;
	cout << "2) class diamondParrot: (char*) charP." << endl;
}

diamondHuman::~diamondHuman()
{
	cout << "Hello, I'm the DTOR from class diamondHuman that takes NO parameters." << endl;
}

void diamondHuman::eatBanana(void)
{
	cout << "Hello, I'm function eatBanana from class diamondHuman" << endl;
}

void diamondHuman::scratchHead(void)
{
	cout << "Hello, I'm function scratchHead from class Human" << endl;
}

void diamondHuman::hasABrain(void)
{
	cout << "function hasABrain from class diamondHuman" << endl;
}