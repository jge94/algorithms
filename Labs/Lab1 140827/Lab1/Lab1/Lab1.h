// CellClass.h

#ifndef CELL
#define CELL

//-----------------------------------------------------------------------
#include <stdafx.h>
#include <iostream>

using namespace std;

//-----------------------------------------------------------------------

class Cell
{
public:
	// Constructors (CTOR)
	Cell();
	Cell(int n);                                            // Default CTOR
	Cell(int n, Cell *p);
	Cell(Cell& cellOriginal);								// Copy CTOR

	const Cell operator+(const Cell& cellOriginal);         // Addition

	// getter functions
	int getValue(Cell cellOriginal);
	Cell getNext(Cell cellOriginal);

private:
	int value;
	Cell *next;
};

//-----------------------------------------------------------------------

class Queue
{
public:
	// Constructors (CTOR)
	Queue();					// Default CTOR
	Queue(Cell& cell);

	// Functions
	int pushLast(int n);
	

private:
	Cell *first;
	Cell *last;
};

#endif
