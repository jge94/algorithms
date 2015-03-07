#include "stdafx.h"
#include <iostream>
#include "parrot.h"
#include "ape.h"
#include "human.h"

Human::Human()
{
	cout << "Hello, I'm the CTOR from class Human that takes NO parameters. (default CTOR)" << endl;
}

Human::Human(bool variable) : Ape(variable)
{
	cout << "Hello, I'm the CTOR from class Human should inherit class Ape: (bool) variable." << endl;
}

Human::Human(bool boolVar, char* charP) : Ape(boolVar), Parrot(charP)
{
	cout << "Hello, I'm the CTOR from class Human should inherit from " << endl;
	cout << "1) class Ape: (bool) variable." << endl;
	cout << "2) class Parrot: (char*) charP." << endl;
}

Human::~Human()
{
	cout << "Hello, I'm the DTOR from class Human that takes NO parameters." << endl;
}

void Human::eatBanana(void)
{
	cout << "Hello, I'm function eatBanana from class Human" << endl;
}

void Human::scratchHead(void)
{
	cout << "Hello, I'm function scratchHead from class Human" << endl;
}