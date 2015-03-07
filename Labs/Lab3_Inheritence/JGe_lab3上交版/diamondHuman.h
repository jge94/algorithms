// human.h
// class Human, parent of class
#ifndef _DIAMONDHUMAN
#define _DIAMONDHUMAN

#include "stdafx.h"
#include "ape.h"
#include "diamondParrot.h"
#include <iostream>

using namespace std;

class diamondHuman :public Ape, public diamondParrot
{
public:
	diamondHuman();
	diamondHuman(bool varaible);				// juwt declaration, it's ok not to define :Ape()
	diamondHuman(bool boolVar, char* charP);
	~diamondHuman();

	void eatBanana(void);
	void scratchHead(void);

	void hasABrain(void);
};

#endif