#ifndef MONKEY
#define MONKEY

#include "stdafx.h"
#include <iostream>

class Monkey
{
	public:
		bool hungry;

		Monkey();							// CTOR and DTOR
		Monkey(bool variable);
		~Monkey();

		virtual void eatBanana(void);
		virtual void scratchHead(void);

		void hasABrain(void);
};

#endif

