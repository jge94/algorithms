// Lab9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "myItem.h"

using namespace std;

void swap(myItem& itemA, myItem& itemB);
void merge(myItem* A, myItem* B, myItem* C, int sizeB, int sizeC);
void mergeSort(myItem* A, int n);
int LomutoPartition(myItem* A, int l, int r);
void LomutoQuickSort(myItem* A, int l, int r);
int HoarePartition(myItem* A, int l, int r);
void HoareQuickSort(myItem* A, int l, int r);

void cmerge(myItem* A, myItem* B, myItem* C, int sizeB, int sizeC);
void cmergeSort(myItem* A, int n);
int cLomutoPartition(myItem* A, int l, int r);
void cLomutoQuickSort(myItem* A, int l, int r);
int cHoarePartition(myItem* A, int l, int r);
void cHoareQuickSort(myItem* A, int l, int r);

// Global Variable
int COUNT;

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream FIN;
	ofstream FOUT;

	string fileName;
	cout << "Enter name of input file: ";
	getline(cin, fileName);

	if (fileName.empty())
	{
		cout << "Done." << endl;
		exit(-1);
	}

	while (!fileName.empty())
	{
		FIN.open(fileName.c_str());

		while (!FIN.is_open())
		{
			cout << "\nUnable to open file, please enter the file name again: ",
				cin >> fileName;
			FIN.open(fileName.c_str());
		}

		int nblines = 0;
		string oneLine;

		while (getline(FIN, oneLine))
			nblines++;

		cout << "Number of lines: " << nblines << endl;

		myItem* myItemArray = new myItem[nblines];
		myItem* lomutoArray = new myItem[nblines];
		myItem* hoareArray = new myItem[nblines];

		myItem* cmyItemArray = new myItem[nblines];
		myItem* clomutoArray = new myItem[nblines];
		myItem* choareArray = new myItem[nblines];

		int nextInt;
		string nextString;

		for (int i = 0; i < nblines; i++)
		{
			FIN >> nextInt;
			myItemArray[i].serialNumber = nextInt;
			lomutoArray[i].serialNumber = nextInt;
			hoareArray[i].serialNumber = nextInt;

			cmyItemArray[i].serialNumber = nextInt;
			clomutoArray[i].serialNumber = nextInt;
			choareArray[i].serialNumber = nextInt;

			FIN >> nextString;
			myItemArray[i].name = nextString;
			lomutoArray[i].name = nextString;
			hoareArray[i].name = nextString;

			cmyItemArray[i].name = nextString;
			clomutoArray[i].name = nextString;
			choareArray[i].name = nextString;
		}

		//merge(myItemArray, )

		//merge(A, B, C, sizeB, sizeC);

		FIN.close();
		FOUT.close();

		COUNT = 0;

		//-------------  MERGESORT ---------------
		cout << "*** Merge sort:" << endl;
		clock_t start, end;
		start = clock();
		mergeSort(myItemArray, 30000);
		end = clock();
		cout << "Time: " << (end - start) << " ticks." << endl;

		cout << "	count Merge sort: ";
		cmergeSort(cmyItemArray, 30000);
		cout << COUNT << endl;
		COUNT = 0;

		//------------- LOMUTOQUICKSORT ---------------
		cout << "\n\n***lomutoQuickSort:" << endl;
		clock_t start2, end2;
		start2 = clock();
		LomutoQuickSort(lomutoArray, 0, 30000 - 1);
		end2 = clock();
		cout << "Time: " << (end2 - start2) << " ticks." << endl;

		cout << "	count lomutoQuickSort:";
		cLomutoQuickSort(clomutoArray, 0, 30000 - 1);
		cout << COUNT << endl;
		COUNT = 0;


		//----------- HOAREQUICKSORT ---------------
		cout << "\n\n***hoareQuickSort time:" << endl;
		clock_t start3, end3;
		start3 = clock();
		HoareQuickSort(hoareArray, 0, 30000);
		end3 = clock();
		cout << "Time: " << (end3 - start3) << " ticks." << endl;

		cout << "	count hoareQuickSort: ";
		cHoareQuickSort(choareArray, 0, 30000);
		cout << COUNT << endl;
		COUNT = 0;

		cout << "Enter name of input file: ";
		getline(cin, fileName);

		if (fileName.empty())
		{
			cout << "Done." << endl;
			exit(-1);
		}
	}
	

	system("PAUSE");
	return 0;
}

void swap(myItem& itemA, myItem& itemB)
{
	myItem swap = itemA;
	itemA = itemB;
	itemB = swap;
}

void merge(myItem* B, myItem* C, myItem* A, int sizeB, int sizeC)
{
	int i = 0, j = 0, k = 0;
	while (i < sizeB && j < sizeC)
	{
		if (B[i] <= C[j])
		{
			A[k] = B[j];
			i++;
		}
		else
		{
			A[k] = C[j];
			j++;
		}
		k++;

		if (i = sizeB)
		{
			for (; j < sizeC; j++, k++)
			{
				A[k] = C[j];
			}
		}
		else
		{
			for (; j < sizeC; i++, k++)
			{
				A[k] = B[i];
			}
		}
	}// end while
}


void mergeSort(myItem* A, int n)
{
	int sizeB, sizeC;
	sizeB = n / 2;
	sizeC = n - sizeB;
	if (n > 1)
	{
		myItem* B = new myItem[sizeB];
		myItem* C = new myItem[sizeC];

		for (int i = 0; i < sizeB; i++)
		{
			B[i] = A[i];
		}

		for (int i = sizeB; i < n; i++)
		{
			C[i-sizeB] = A[i];
		}

		mergeSort(B, sizeB);
		mergeSort(C, sizeC);

		merge(B, C, A, sizeB, sizeC);
	}//end if
}


int LomutoPartition(myItem* A, int l, int r)
{
	myItem p = A[l];
	int s = l;
	for (int i = l + 1; i <= r; i++) 
	{
		if (A[i] < p)
		{
			s++;
			swap(A[s], A[i]);
		}
	}
	swap(A[l], A[s]);
	return s;
}


void LomutoQuickSort(myItem* A, int l, int r)
{
	if (l < r)
	{
		int s = LomutoPartition(A, l, r);
		LomutoQuickSort(A, l, s - 1);
		LomutoQuickSort(A, s + 1, r);
	}
}


int HoarePartition(myItem* A, int l, int r)
{
	myItem p;
	if (A[l] < A[r])
	{
		myItem p = A[l];
	}
	else
	{
		swap(A[l], A[r]);
		myItem p = A[l];
	}

	int i = l;
	int j = r + 1;

	do{
		do{ i++; } while (A[i] < p);
		do{ j--; } while (A[j] > p);
		swap(A[l], A[i]);
	} while (i < j);

	swap(A[j], A[i]);
	swap(A[j], A[l]);

	return j;
}


void HoareQuickSort(myItem* A, int l, int r)
{
	if (l < r)
	{
		int s = HoarePartition(A, l, r);
		HoareQuickSort(A, l, s - 1);
		HoareQuickSort(A, s + 1, r);
	}
}


void cmerge(myItem* B, myItem* C, myItem* A, int sizeB, int sizeC)
{
	int i = 0, j = 0, k = 0;
	while (i < sizeB && j < sizeC)
	{
		COUNT += 2;
		if (B[i] <= C[j])
		{
			A[k] = B[j];
			i++;
		}
		else
		{
			A[k] = C[j];
			j++;
		}
		k++;
		COUNT++;

		if (i = sizeB)
		{
			for (; j < sizeC; j++, k++)
			{
				COUNT++;
				A[k] = C[j];
			}
		}
		else
		{
			for (; j < sizeC; i++, k++)
			{
				COUNT++;
				A[k] = B[i];
			}
		}
		COUNT++;
	}// end while
}


void cmergeSort(myItem* A, int n)
{
	COUNT++;

	int sizeB, sizeC;
	sizeB = n / 2;
	sizeC = n - sizeB;
	if (n > 1)
	{
		myItem* B = new myItem[sizeB];
		myItem* C = new myItem[sizeC];

		for (int i = 0; i < sizeB; i++)
		{
			COUNT++;
			B[i] = A[i];
		}

		for (int i = sizeB; i < n; i++)
		{
			COUNT++;
			C[i - sizeB] = A[i];
		}

		cmergeSort(B, sizeB);
		cmergeSort(C, sizeC);

		cmerge(B, C, A, sizeB, sizeC);
	}//end if
}


int cLomutoPartition(myItem* A, int l, int r)
{
	myItem p = A[l];
	int s = l;
	for (int i = l + 1; i <= r; i++)
	{
		COUNT++;
		if (A[i] < p)
		{
			s++;
			swap(A[s], A[i]);
		}
		COUNT++;
	}
	swap(A[l], A[s]);
	return s;
}


void cLomutoQuickSort(myItem* A, int l, int r)
{
	if (l < r)
	{
		COUNT++;
		int s = cLomutoPartition(A, l, r);
		cLomutoQuickSort(A, l, s - 1);
		cLomutoQuickSort(A, s + 1, r);
	}
}


int cHoarePartition(myItem* A, int l, int r)
{
	myItem p;
	if (A[l] < A[r])
	{
		myItem p = A[l];
	}
	else
	{
		swap(A[l], A[r]);
		myItem p = A[l];
	}
	COUNT++;

	int i = l;
	int j = r + 1;

	do{
		do{ i++; COUNT++; } while (A[i] < p);
		do{ j--; COUNT++; } while (A[j] > p);
		swap(A[l], A[i]);
		COUNT++;
	} while (i < j);

	swap(A[j], A[i]);
	swap(A[j], A[l]);

	return j;
}


void cHoareQuickSort(myItem* A, int l, int r)
{
	if (l < r)
	{
		COUNT++;
		int s = cHoarePartition(A, l, r);
		cHoareQuickSort(A, l, s - 1);
		cHoareQuickSort(A, s + 1, r);
	}
}