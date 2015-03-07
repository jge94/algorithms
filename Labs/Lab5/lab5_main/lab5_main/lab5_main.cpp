// lab5_main.cpp : Defines the entry point for the console application.
//

// Programmer: Jinnan Ge
// Date: 9/26/2014

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct tripleInt {
	int intOne;
	int intTwo;
	int intThree;
};

tripleInt* reverse(tripleInt*);
void swap(int, tripleInt*);

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream FIN;
	FIN.open("barn.moo");
	ofstream FOUT;
	FOUT.open("reverse.dat");

	int nblines;
	string nextLine;

	if (FIN.is_open())
	{
		getline(FIN, nextLine);
		sscanf_s(nextLine.c_str(), "%d", &nblines);
	}

	tripleInt* A = new tripleInt[];
	A = reverse(A);
	swap(nblines, A);

	system("PAUSE");
	return 0;
}

tripleInt* reverse(tripleInt* A)
{
	ifstream FIN;
	FIN.open("barn.moo");
	ofstream FOUT;
	FOUT.open("reverse.dat");

	int nblines, firstInt, secondInt, thirdInt;
	string nextLine;

	if (FIN.is_open())
	{
		getline(FIN, nextLine);
		sscanf_s(nextLine.c_str(), "%d", &nblines);				// input file formatting: sscanf
																// c_str(): transfer string to char*
		A = new tripleInt[nblines];

		FOUT << "There are " << nblines << " lines in this file." << endl;

		for (int i = 0; i < nblines; i++)
		{
			getline(FIN, nextLine);
			sscanf_s(nextLine.c_str(), "woof %d meow meow %d quack oink quack %d roar", &firstInt, &secondInt, &thirdInt);
			A[i].intOne = firstInt;
			A[i].intTwo = secondInt;
			A[i].intThree = thirdInt;
		}

		for (int j = nblines - 1; j >= 0; j--)
		{
			FOUT << A[j].intOne << "," << A[j].intTwo << "," << A[j].intThree << endl;
		}
	}
	else cout << "Unable to open file" << endl;

	FIN.close();
	FOUT.close();

	return A;
}

void swap(int nblines, tripleInt* A)
{
	ifstream FIN;
	FIN.open("reverse.dat");
	ofstream FOUT;
	FOUT.open("swap.dat");

	FOUT << "There are " << nblines << " lines in this file." << endl;

	tripleInt* orderedA = new tripleInt[nblines];

	int i = 0;
	for (int j = nblines - 1; j >= 0; j--)
	{
		orderedA[i].intOne = A[j].intOne;
		orderedA[i].intTwo = A[j].intTwo;
		orderedA[i].intThree = A[j].intThree;
		i++;
	} 

	// calculate the even numbers, numbers divisible by 3, numbers divisible by 5
	int evenNumber = 0;
	int divideThree = 0;
	int divideFive = 0;

	for (int i = 0; i < nblines; i++)
	{
		if (orderedA[i].intOne % 2 == 0)
			evenNumber += 1;
		if (orderedA[i].intTwo % 2 == 0)
			evenNumber += 1;
		if (orderedA[i].intThree % 2 == 0)
			evenNumber += 1;
		
		if (orderedA[i].intOne % 3 == 0)
			divideThree += 1;
		if (orderedA[i].intTwo % 3 == 0)
			divideThree += 1;
		if (orderedA[i].intThree % 3 == 0)
			divideThree += 1;

		if (orderedA[i].intOne % 5 == 0)
			divideFive += 1;
		if (orderedA[i].intTwo % 5 == 0)
			divideFive += 1;
		if (orderedA[i].intThree % 5 == 0)
			divideFive += 1;
	}


	for (int lineNum = 0; lineNum < nblines; lineNum++)
	{
		if (nblines % 2 == 1)							// odd number of lines in total
		{
			if (lineNum == nblines - 2)					// second to the last line
			{
				FOUT << "First integer: " << evenNumber << " ";
				FOUT << "Second integer: " << divideThree << " ";
				FOUT << "Third integer: " << divideFive << endl;
				continue;
			}
			else if (lineNum == nblines - 1)			// last line
			{
				FOUT << "First integer: " << orderedA[lineNum].intOne << " ";
				FOUT << "Second integer: " << orderedA[lineNum].intTwo << " ";
				FOUT << "Third integer: " << orderedA[lineNum].intThree << endl;
				break;
			}
		}

		if (lineNum % 2 == 0)	// odd line number
		{
			FOUT << "First integer: " << orderedA[lineNum + 1].intOne << " ";
			FOUT << "Second integer: " << orderedA[lineNum + 1].intTwo << " ";
			FOUT << "Third integer: " << orderedA[lineNum + 1].intThree << endl;
		}
		else					// even line number
		{
			FOUT << "First integer: " << orderedA[lineNum - 1].intOne << " ";
			FOUT << "Second integer: " << orderedA[lineNum - 1].intTwo << " ";
			FOUT << "Third integer: " << orderedA[lineNum - 1].intThree << endl;
		}
	}

	FIN.close();
	FOUT.close();
}

