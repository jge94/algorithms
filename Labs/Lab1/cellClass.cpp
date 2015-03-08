// Vect.cpp
#include "stdafx.h"
#include "Lab1.h"
#include "stdafx.h"
#include "Lab1.h"

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "math.h"

using namespace std;

//-----------------------------------------------------------------------
//----- Constructors (CTOR) ---------------------------------------------
Cell::Cell()
{
}

Cell::Cell(int n)
{
	this->value = n;
}

Cell::Cell(int n, Cell *p)
{
	this->value = n;
	this->next = p;
}


// COPY CTOR
Cell::Cell(Cell& cellOriginal)  //must pass by REFERENCE - syntax
{
	this->value = cellOriginal.value;
	this->next = cellOriginal.next;
}


// ADDITION
const Cell Cell::operator+(const Cell& cellOriginal)
{
	Cell sumCell;
	sumCell.value = this->value + cellOriginal.value;
	return sumCell;
}

int getValue(Cell cellOriginal)
{
	return cellOriginal.value;
}

Cell getNext(Cell cellOriginal)
{
	return cellOriginal.next;
}

//-----------------------------------------------------------------------
//----- Constructors (CTOR) ---------------------------------------------
Queue::Queue()
{
	*first = 0;
	*last = 0;
}

Queue::Queue(Cell& cell)
{
	first = &cell;
	last = &cell;
	cell.next = 0;
}

int Queue::pushLast(int n)
{
	Cell tempCell(n);
	tempCell.next = 0;
	this->last->next = tempCell;
	*last = tempCell;
}




