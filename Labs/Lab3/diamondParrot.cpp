#include "stdafx.h"
#include <iostream>
#include "diamondParrot.h"

using namespace std;

diamondParrot::diamondParrot()
{
	cout << "Hello, I'm the CTOR from class DIAMONDParrot that takes NO parameters. (default CTOR)" << endl;
}

diamondParrot::diamondParrot(char* charP)
{
	cout << "Hello, I'm the constructor from class DIAMONDParrot that takes parameter: (char*) charP." << endl;
}

diamondParrot::~diamondParrot()
{
	cout << "Hello, I'm the destructor from class DIAMONDParrot that takes NO parameters." << endl;
}

void diamondParrot::talk(void)
{
	cout << "Hello, I'm function talk from class DIAMONDParrot" << endl;
}