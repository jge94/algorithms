// ape.h
// class Ape, derived from class Monkey

#ifndef _APE
#define _APE

#include "stdafx.h"
#include <iostream>
#include "monkey.h"

using namespace std;
/*
(a) a constructor that takes no input.
(b) a constructor that takes a bool as its input and calls the constructor from monkey that
takes a bool.
(c) a destructor (that only prints on the screen that the destructor from ape was called)
(d) a function eatBanana that takes no input. This function should not be virtual.
(e) a virtual function stratchHead that takes no input.
*/

class Ape : public Monkey
{
	public:
		Ape();
		Ape(bool variable);
		~Ape();
		
		void eatBanana(void);
		virtual void scratchHead(void);

		virtual void hasABrain(void);
};

#endif