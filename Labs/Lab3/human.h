// human.h
// class Human, parent of class
#ifndef _HUMAN
#define _HUMAN

#include "stdafx.h"
#include "ape.h"
#include "parrot.h"
#include <iostream>

using namespace std;

class Human:public Ape, public Parrot
{
	public:
		Human();
		Human(bool varaible);				// juwt declaration, it's ok not to define :Ape()
		Human(bool boolVar, char* charP);
		~Human();

		void eatBanana(void);
		void scratchHead(void);
};

#endif