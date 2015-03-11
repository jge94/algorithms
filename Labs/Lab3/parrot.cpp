#include "stdafx.h"
#include <iostream>
#include "parrot.h"

using namespace std;

Parrot::Parrot()
{
	cout << "Hello, I'm the constructor from class Parrot that takes NO parameters. (default CTOR)" << endl;
}

Parrot::Parrot(char* charP)
{
	cout << "Hello, I'm the constructor from class Parrot that takes parameter: (char*) charP." << endl;
}

Parrot::~Parrot()
{
	cout << "Hello, I'm the destructor from class Parrot that takes NO parameters." << endl;
}

void Parrot::talk(void)
{
	cout << "Hello, I'm function talk from class Parrot" << endl;
}