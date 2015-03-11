// lab3.cpp : Defines the entry point for the console application.
//

// Programmer: Jinnan Ge
// Date: 09/11/2014
// COMP 225 - Lab3 : Inheritance Functions in C++


#include "stdafx.h"
#include <iostream>
#include <math.h> 
#include "ape.h"
#include "human.h"
#include "monkey.h"
#include "parrot.h"
#include "diamondParrot.h"
#include "diamondHuman.h"

using namespace std;


//	--------------- Global Variable--------------
double INPUT_VALUE = 3.1415, RETURN_IF_EVEN = 2.98, RETURN_IF_ODD = 1.46;


// template function: round and return according to even/odd
template <class T>

T roundReturn(T a, T b, T c) {
	int d;
	if (a < (floor(a) + 0.5))
	{
		a = floor(a);
		d = (int)a;
	}
	else
	{
		a = (int)ceil(a);
		d = (int)a;
	}

	if (d % 2 == 0)
		return b;
	else
		return c;
}// end roundReturn


// template class: cell of type T
template <class T>

class cell 
{
	public:
		T value;
		T* cellPointer;
		cell();
		cell(T);
};


// define default CTOR of class cell
template <class T>
cell<T>::cell()
{
}


// define CTOR that takes in one input
template <class T>
cell<T>::cell(T number)
{
	value = number;
	cout << "\nvalue is: " << value << endl;
}


// MAIN FUNCTION starts here.....

int _tmain(int argc, _TCHAR* argv[])
{
	Monkey *m; Ape *a;
	Human *h;

	cout << "m = new Ape(true) : " << endl;
	m = new Ape(true);

	cout << "\nm->eatBanana() : " << endl;
	m->eatBanana();

	cout << "\na = new Human : " << endl;
	a = new Human;

	cout << "\n** delete m; m = a :" << endl;
	delete m;
	m = a;

	cout << "\nm->scratchHead() : " << endl;
	m->scratchHead();

	cout << "\na->scratchHead() : " << endl;
	a->scratchHead();

	cout << "\nm->eatBanana()" << endl;
	m->eatBanana();

	cout << "\na->eatBanana()" << endl;
	a->eatBanana();

	cout << "\nh = a;" << endl;
	h = dynamic_cast<Human*>(a);

	cout << "\nh = new human(true,NULL) " << endl;
	h = new Human(true, NULL);

	cout << "\nh->talk() : " << endl;
	h->talk();

	cout << "\ndelete h : " << endl;
	delete h;

	cout << "\nh = new human(true) ;" << endl;
	h = new Human(true);

	cout << "\n\n***********\nCreate New Object Diamond human, diamond parrot" << endl;
	// 18: Diamond Class
	diamondHuman *diamondHumanP;
	diamondParrot *diamondParrotP;

	cout << "\n*** diamondHumanP = new diamondHuman(true, NULL) " << endl;
	diamondHumanP = new diamondHuman(true, NULL);
	
	cout << "\n*** a = diamondHumanP" << endl;
	a = diamondHumanP;

	cout << "\n*** m->hasABrain()" << endl;
	diamondHuman* dHuman = new diamondHuman(false, NULL);
	m->hasABrain();

	cout << "\n*** a->hasABrain()" << endl;
	a->hasABrain();

	// 20
	double result;
	double x = INPUT_VALUE, y = RETURN_IF_EVEN, z = RETURN_IF_ODD;
	result = roundReturn(x,y,z);
	cout << "Result is: " << result << endl;


	// 21
	cell<int> Cell = cell<int>();
	cell<int> oneCell = cell<int>(4);

	system("PAUSE");
	return 0;
}

