// lab4.cpp : Defines the entry point for the console application.
//

// Programmer: Jinnan Ge
// Date: 9/19/2014

// Answer to Questions:
// Q9: double: 2!, triple: 3!, quqdrupes: 4!

// Q12: 1 time: 5, 2 times: 7, 4 times: 10, 8 times: 11, 16 times: 15
//	    N: number of elements in tree
//		D: depth of the tree
//		D = log2(N+1)

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include "node.h"
#include "tree.h"
#include "integerPairs.h"

using namespace std;

int LINE_NUMBER = 100000000;

void generateFile(void);
integerPairs* readFile(int nbLines);
int findMax(integerPairs* A, int& n);
void outSort(integerPairs* A, int n);
void ourSortTiming(int size);
void ourTreeTiming(int size);

int _tmain(int argc, _TCHAR* argv[])
{
	generateFile();
	integerPairs* A = new integerPairs[LINE_NUMBER];
	A = readFile(LINE_NUMBER);

	int n = LINE_NUMBER;
	int max;
	max = findMax(A, n);
	//cout << "max: " << max << endl;
	//cout << "index: " << n << endl;

	outSort(A, LINE_NUMBER);
	ourSortTiming(LINE_NUMBER);
	ourTreeTiming(LINE_NUMBER);

	/*// test
	integerPairs intPair1(1, 3);
	integerPairs intPair2(1, 2);

	if (intPair1 == intPair2)
	{
		cout << "p1 == p2" << endl;
	}
	if (intPair1 < intPair2)
	{
		cout << "p1 < p2" << endl;
	}
	if (intPair1 > intPair2)
	{
		cout << "p1 > p2" << endl;
	}
	if (intPair1 <= intPair2)
	{
		cout << "p1 <= p2" << endl;
	}
	if (intPair1 >= intPair2)
	{
		cout << "p1 >= p2" << endl;
	}
	*/


	system("PAUSE");
	return 0;
}

void generateFile(void)
{
	ofstream FOUT;
	FOUT.open("InputNumbers.dat");

	for (short i = 0; i < LINE_NUMBER; i++)
	{
		FOUT << rand() << " " << rand() << endl;
	}

	FOUT.close();
}


integerPairs* readFile(int nbLines)
{
	int value1, value2;
	integerPairs* A = new integerPairs[nbLines];
	ifstream FIN;
	FIN.open("InputNumbers.dat");

	for (int i = 0; i < nbLines; i++)
	{
		FIN >> value1;
		FIN >> value2;
		A[i].value1 = value1;
		A[i].value2 = value2;
	}

	FIN.close();
	// test
	/*for (int i = 0; i < nbLines; i++)
	{
		cout << i << ": " << A[i].value1 << endl;
		cout << i << ": " << A[i].value2 << endl;
	}*/
	
	return A;
}

int findMax(integerPairs* A, int& n)
{
	int max = 0;
	int maxIndex;

	for (int i = 0; i < n; i++)
	{
		if (A[i].value1 > max)
		{
			max = A[i].value1;
			maxIndex = i;
		}
		if (A[i].value2 > max)
		{
			max = A[i].value2;
			maxIndex = i;
		}
	}
	n = maxIndex;   //change n so that n = index number

	return max;
}

void outSort(integerPairs* A, int n)
{
	// Q7
	int max;
	int size = n;

	for (int i = 0; i < n; i++)
	{
		int lookUpUntil = n - i;
		max = findMax(A, lookUpUntil);	// now lookUpUntil is the index of max
		integerPairs maxPair = A[lookUpUntil];
		A[lookUpUntil] = A[size - i - 1];
		A[size - i - 1] = maxPair;
	}

	// test
	/*for (int k = 0; k < size; k++)
	{
		cout << k << ": " << A[k].value1 << endl;
		cout << k << ": " << A[k].value2 << endl;
	}*/     
}

void ourSortTiming(int size)
{
	integerPairs* A = new integerPairs[size];
	A = readFile(size);
	clock_t start, end;
	start = clock();
	outSort(A, size);
	end = clock();
	cout << "The sorting took " << (end - start) << " clock ticks." << endl;
	delete A;
}

void ourTreeTiming(int size)
{
	integerPairs* A = new integerPairs[size];
	A = readFile(size);
	binarySearchTree oneTree;
	clock_t start, end;
	start = clock();
	for (int i = 0; i < size; i++)
	{
		oneTree.insert(A[i]);
	}
	end = clock();
	cout << "The interting elements took " << (end - start) << " clock ticks." << endl;
	cout << "Depth of the tree is: " << oneTree.depth() << "." << endl;
	delete A;
}
