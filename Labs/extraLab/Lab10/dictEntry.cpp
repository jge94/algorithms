
#include "stdafx.h"
///*
#include "dictEntry.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

dictEntry::dictEntry(string w, string d)
{
	this->word = w;
	this->definition = d;
}

string dictEntry::getDefinition(void)
{
	return(this->definition);
}

string dictEntry::getWord(void)
{
	return(this->word);
}

void dictEntry::updateDefinition(string def)
{
	this->definition = def;
}

bool dictEntry::operator==(string aString)
{
	if (strcmp((this->word).c_str(), aString.c_str()) == 0)
		return true;
	else
		return false;
}

bool dictEntry::operator<(string aString)
{
	if (strcmp((this->word).c_str(), aString.c_str()) < 0)
		return true;
	else
		return false;
}

bool dictEntry::operator>(string aString)
{
	if (strcmp((this->word).c_str(), aString.c_str()) > 0)
		return true;
	else
		return false;
}

bool dictEntry::operator<=(string aString)
{
	return ((this->word < aString) || (this->word == aString));
}

bool dictEntry::operator>=(string aString)
{
	return ((this->word > aString) || (this->word == aString));
}
//*/