// Lab8.cpp : Defines the entry point for the console application.
//

// Jinnan Ge
// 10/15/2014

#include "stdafx.h"
#include <iostream>
#include <list>
#include <string>
#include <fstream>

using namespace std;

int* readFile(int &nblines);
void insertionSort(int* A, int size);
int binarySearch(int* A, int size, int searchElt);

int _tmain(int argc, _TCHAR* argv[])
{
	int* A;
	int searchInt;
	int nblines = 0;
	A = readFile(nblines);

	insertionSort(A, nblines);

	cout << "After insertionSort, the array is: " << endl;
	for (int i = 0; i < nblines; i++)
	{
		cout << A[i] << endl;
	}

	cout << "\nEnter the integer you're searching: ",
		cin >> searchInt;
	int resultIndex = binarySearch(A, nblines, searchInt);

	while (resultIndex != -1)
	{
		cout << "Found at index: " << resultIndex << endl;
		cout << "\nSearching again...";
		cout << "\nEnter the integer you're searching: ",
			cin >> searchInt;
		resultIndex = binarySearch(A, nblines, searchInt);
	}

	cout << "\nNot found... Done." << endl;
	system("PAUSE");
	return 0;
}

int* readFile(int& nblines)
{
	int* A = NULL;
	string fileName;
	cout << "Enter name of input file: ",
		cin >> fileName;

	ifstream FIN;
	ofstream FOUT;
	FIN.open(fileName.c_str());

	while (!FIN.is_open())
	{
		cout << "\nUnable to open file, please enter the file name again: ",
			cin >> fileName;
		FIN.open(fileName.c_str());
	}

	int nextInt;

	if (FIN.is_open())
	{
		FIN >> nblines;
		A = new int[nblines];
		for (int i = 0; i < nblines; i++)
		{
			FIN >> nextInt;
			A[i] = nextInt;
		}
	}


	FIN.close();

	return A;
}

void insertionSort(int* A, int size)
{
	for (int i = 1; i <= (size - 1); i++)
	{
		int v = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] >= v)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
	}
}

int binarySearch(int* A, int size, int searchElt)
{
	int left = 0;
	int right = size - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (searchElt == A[middle])
			return middle;
		else if (searchElt < A[middle])
		{
			right = middle - 1;
		}
		else
			left = middle + 1;
	}
	return -1;
}

