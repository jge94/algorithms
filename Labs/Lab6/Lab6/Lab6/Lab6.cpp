// Lab6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include "pairsAgain.h"

using namespace std;

void selectionSort(pairsAgain* A, int nblines, string outputFile);
void bubbleSort(pairsAgain* A, int nblines, string outputFile);
int sequentialSearch(pairsAgain* A, int nblines, pairsAgain searchPair);
int bruteForceMatch(char* textArray, char* patternArray, int nblines, int sizeOfPattern);

void bruteForceMatch(pairsAgain* A, int nblines);

int _tmain(int argc, _TCHAR* argv[])
{
	/*string INPUT;
	int one, two;
	cout << "Test input: ";
	getline(cin, INPUT);
	cout << INPUT << endl;
	sscanf_s(INPUT.c_str(), "%d %d", &one, &two);
	cout << one << endl;
	cout << two << endl;
	pairsAgain newPair(one, two);
	cout << newPair.val1 << " " << newPair.val2 << endl;*/

	int inputType;
	cout << "Enter a number (1 or 2) to choose " << endl;
	cout << "1. your file contains numbers" << endl;
	cout << "2. your file contains text" << endl;
	cout << "My file type is: ",
		cin >> inputType;

	while (inputType != 1 && inputType != 2)
	{
		cout << "Invalid input, please enter again! " << endl;
		cout << "1. your file contains numbers" << endl;
		cout << "2. your file contains text" << endl;
		cout << "My file type is: ",
			cin >> inputType;
	}

	if (inputType == 1)  // numbers
	{
		string fileName;
		cout << "Enter the name of the file: ",
			cin >> fileName;

		ifstream FIN;

		string nextLine;
		int nblines, firstInt, secondInt;

		FIN.open(fileName.c_str());

		pairsAgain* A = new pairsAgain[];

		while (!FIN.is_open())
		{
			cout << "\nUnable to open file, please enter the file name again: ",
				cin >> fileName;
			FIN.open(fileName.c_str());
		}

		if (FIN.is_open())
		{
			getline(FIN, nextLine);
			sscanf_s(nextLine.c_str(), "%d", &nblines);

			A = new pairsAgain[nblines];

			for (int i = 0; i < nblines; i++)
			{
				getline(FIN, nextLine);
				sscanf_s(nextLine.c_str(), "%d %d", &firstInt, &secondInt);
				A[i].val1 = firstInt;
				A[i].val2 = secondInt;
			}
		}


		FIN.close();

		string algChoice;
		cout << "Below is the algorithms: " << endl;
		cout << "a. Selection Sort" << endl;
		cout << "b. Bubble Sort" << endl;
		cout << "c. Sequential Search" << endl;
		cout << "Enter the letter that represent your choice: ",
			cin >> algChoice;

		string outputFile;
		pairsAgain searchPair;

		while (algChoice != "a" && algChoice != "b" && algChoice != "c")
		{
			cout << "Invalid input, please enter again: ",
				cin >> algChoice;
		}

		if (algChoice == "a")
		{
			cout << "\nEnter the name of your output file: ",
				cin >> outputFile;
			selectionSort(A, nblines, outputFile);
		}
		else if (algChoice == "b")
		{
			cout << "\nEnter the name of your output file: ",
				cin >> outputFile;
			bubbleSort(A, nblines, outputFile);
		}
		else if (algChoice == "c")
		{
			cin.clear();
			cin.ignore(10000, '\n');

			string inputPair, inputPair2;
			int first, second;
			cout << "\nEnter the following pairs in format [integer (space) integer]." << endl;
			cout << "Enter the pair you want to search: ";
			getline(cin, inputPair);
			sscanf_s(inputPair.c_str(), "%d %d", &first, &second);
			pairsAgain searchPair(first, second);

			int foundPosition = sequentialSearch(A, nblines, searchPair);

			while (foundPosition != -1)
			{
				cout << "\nNow search again... Enter the numbers seperately this time." << endl;
				cout << "Enter the pair you want to search. ";
				cout << "First number: ",
					cin >> first;
				cout << "Second number: ",
					cin >> second;
				pairsAgain searchPair(first, second);

				foundPosition = sequentialSearch(A, nblines, searchPair);
			}

			if (foundPosition == -1)
			{
				cout << "The pair you entered is not found." << endl;
			}
		}

	}//end numbers

	else if (inputType == 2)   // text
	{
		string fileName;
		cout << "Enter the name of the input file: ",
			cin >> fileName;

		ifstream FIN;

		string nextLine;
		int nblines, firstInt, secondInt;

		FIN.open(fileName.c_str());

		while (!FIN.is_open())
		{
			cout << "\nUnable to open file, please enter the file name again: ",
				cin >> fileName;
			FIN.open(fileName.c_str());
		}

		if (FIN.is_open())
		{
			string wholeFileString = "";

			getline(FIN, nextLine);
			sscanf_s(nextLine.c_str(), "%d", &nblines);

			for (int i = 0; i < nblines; i++)
			{
				getline(FIN, nextLine);
				nextLine.erase(remove(nextLine.begin(), nextLine.end(), '\n'), nextLine.end());
				nextLine += " ";
				wholeFileString += nextLine;
			}

			char* textArray = new char[];
			strcpy(textArray, wholeFileString.c_str());

			string searchPattern;
			cout << "\nEnter the pattern to search: ",
				cin >> searchPattern;
			
			int sizeOfPattern = searchPattern.length();
			char* patternArray = new char[];
			strcpy(patternArray, searchPattern.c_str());

			int textPosition = bruteForceMatch(textArray, patternArray, nblines, sizeOfPattern);

			while (textPosition != -1)
			{
				cout << "\nEnter the pattern to search: ",
					cin >> searchPattern;

				int sizeOfPattern = searchPattern.length();
				char* patternArray = new char[];
				strcpy(patternArray, searchPattern.c_str());

				int textPosition = bruteForceMatch(textArray, patternArray, nblines, sizeOfPattern);
			}
		}


		FIN.close();
		
	}// end text

	system("PAUSE");
	return 0;
}


void selectionSort(pairsAgain* A, int nblines, string outputFile)
{
	ofstream FOUT;
	FOUT.open(outputFile.c_str());

	int min;
	pairsAgain swap;
	for (int i = 0; i <= nblines - 2; i++)
	{
		min = i;
		for (int j = i + 1; j <= nblines - 1; j++)
		{
			if (A[j] < A[min])
				min = j;
		} // end first for

		swap = A[i];
		A[i] = A[min];
		A[min] = swap;
	}// end second for

	FOUT << nblines << endl;
	for (int k = 0; k < nblines; k++)
	{
		FOUT << A[k].val1 << " " << A[k].val2 << endl;
	}

	FOUT.close();
}


void bubbleSort(pairsAgain* A, int nblines, string outputFile)
{
	ofstream FOUT;
	FOUT.open(outputFile.c_str());

	int nbswap;
	pairsAgain swap;
	for (int i = 0; i <= nblines - 2; i++)
	{
		nbswap = 0;
		for (int j = 0; j <= (nblines - 2 - j); j++)
		{
			if (A[j + 1] < A[j])
			{
				swap = A[j+1];
				A[j+1] = A[j];
				A[j] = swap;
				nbswap++;
			}// if
		}// inner for

		if (nbswap == 0)
			break;
	}// outer for
	
	FOUT << nblines << endl;
	for (int k = 0; k < nblines; k++)
	{
		FOUT << A[k].val1 << " " << A[k].val2 << endl;
	}

	FOUT.close();
}


int sequentialSearch(pairsAgain* A, int nblines, pairsAgain searchPairs)
{

	for (int i = 0; i <= nblines - 1; i++)
	{
		//cout << A[i].val1 << ", " << A[i].val2 << endl;
		if (A[i] == searchPairs)
		{
			cout << "Found (" << searchPairs.val1 << " " << searchPairs.val2 << ") at position: " << i << endl;
			return i;
		}
	}
	return -1;
}


int bruteForceMatch(char* textArray, char* patternArray, int nblines, int sizeOfPattern)
{
	for (int i = 0; i <= (nblines - sizeOfPattern - 1); i++)
	{
		int j = 0;
		bool firstTime = true;
		while ((j < sizeOfPattern) && (patternArray[j] == textArray[i + 1]))
		{
			j++;
		}
		if (j = sizeOfPattern)
			return 1;
	}
	return -1;
}