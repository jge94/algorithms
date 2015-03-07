// Lab10_11_19.cpp : Defines the entry point for the console application.
//

// SUMMARY:
// Programmer: Jinnan Ge
// Date: 11/20/2014

/*
Answers:
(a) Number of keys before first collision: 58
(b) Number of keys before 5-fold collision: 22907
(c) Number of collisions before inserting 90000 keys: 57029
(d) Empty spaces: 32971
(e) Highest number of collisions: 7
(f) Number of keys before each cell in table has at least one key: 1071883
(g) The max of value in table: 30
*/

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <random>

using namespace std;

// Prototypes
long generateRandomKey(void);
long hashFunction(long key);

int _tmain(int argc, _TCHAR* argv[])
{
	long table[90000];

	for (int i = 0; i < 90000; i++)
	{
		table[i] = 0;
	}

	// -------- Comment the part beblow out if testing (f) and (g) ----------
	///*
	for (int i = 0; i < 90000; i++)
	{
		long key = generateRandomKey();
		long hashedKey = hashFunction(key);
		table[hashedKey]++;

		//if (table[hashedKey] == 2)
		//{
		//	cout << "(a) First collision! Number of key is: " << i << endl;
		//	break;
		//}
		// 58

		//if (table[hashedKey] == 5)
		//{
		//	cout << "(b) First collision! Number of key is: " << i << endl;
		//	break;
		//}
		// 5-fold: 22907
	}

	int moreThanOne = 0;
	for (int i = 0; i < 90000; i++)
	{
		if (table[i] >= 1)
			moreThanOne++;
	}
	cout << "(c) total collisions: " << moreThanOne << endl;

	int emptySpace = 0;
	for (int i = 0; i < 90000; i++)
	{
		if (table[i] == 0)
			emptySpace++;
	}
	cout << "(d) empty space: " << emptySpace << endl;

	int maxCollision = 0;
	for (int i = 0; i < 90000; i++)
	{
		if (table[i] > maxCollision)
			maxCollision = table[i];
	}
	cout << "(e) highest collision: " << maxCollision << endl;
	//*/
	// ----------- Comment the part above out if testing (f) and (g) ----------

	// ----------- The part below is testing (f) and (g) ----------
	/*
	int empCellNum = 90000;
	int insertedNum = 0;

	while (empCellNum > 0)
	{
		long key = generateRandomKey();
		long hashedKey = hashFunction(key);
		
		if (table[hashedKey] == 0)
		{
			empCellNum--;
		}

		table[hashedKey]++;
		insertedNum++;
	}

	cout << "(f) Number of keys before filling out the table: " << insertedNum << endl;

	int maxCollision = 0;
	for (int i = 0; i < 90000; i++)
	{
		if (table[i] > maxCollision)
			maxCollision = table[i];
	}
	cout << "(g) highest collision: " << maxCollision << endl;
	*/
	// ----------- The part above is testing (f) and (g) ----------

	system("PAUSE");
	return 0;
}

default_random_engine generator;
uniform_int_distribution<int> distribution(0, 180000);

long generateRandomKey()
{ 
	return distribution(generator); 
}


long hashFunction(long key)
{
	return ((11057 * key) % 179999) % 90000;
}

