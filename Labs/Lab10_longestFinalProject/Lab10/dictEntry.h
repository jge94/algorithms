///*
#ifndef _DICTENTRY
#define _DICTENTRY

#include "stdafx.h"
#include <iostream>
#include <cstring>

using namespace std;

class dictEntry
{
	protected:
		string word;
		string definition;

	public:
		dictEntry(string w, string d);
		string getDefinition(void);
		string getWord(void);
		void updateDefinition(string def);

		bool operator==(string aString);
		bool operator<(string aString);
		bool operator>(string aString);
		bool operator<=(string aString);
		bool operator>=(string aString);
};

#endif
//*/