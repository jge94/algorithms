// parrot.h
// class Parrot, parent of class
#ifndef _DIAMONDPARROT
#define _DIAMONDPARROT

#include "stdafx.h"
#include <iostream>
#include "monkey.h"

class diamondParrot : public Monkey
{
public:
	char* vocabulary;
	diamondParrot();
	diamondParrot(char* charP);
	~diamondParrot();

	void talk(void);
};

#endif
