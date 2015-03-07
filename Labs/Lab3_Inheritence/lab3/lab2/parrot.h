// parrot.h
// class Parrot, parent of class
#ifndef _PARROT
#define _PARROT

#include "stdafx.h"
#include <iostream>
//#include "monkey.h"

/*
(a) a character pointer vocabulary
(b) a constructor that takes no input.
(c) a constructor that takes a character pointer as a input.
(d) a destructor (that only prints on the screen that the destructor from parrot was called)
(e) a function talk that takes no input.
*/
class Parrot
{
	public:
		char* vocabulary;
		Parrot();
		Parrot(char* charP);
		~Parrot();
		
		void talk(void);
};

#endif
