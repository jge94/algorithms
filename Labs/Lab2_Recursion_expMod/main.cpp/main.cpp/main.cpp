// main.cpp.cpp : Defines the entry point for the console application.
//

// Programmer: Jinnan Ge
// Date: 09/03/2014

//	================== LAB2 : RECURSION ===================
//			 ------ ANSWER TO QUESTIONS --------

// Q5. I ran into trouble during the first function, and as the exponent gets bigger, the recursive functions 
//	   has stack overflow. It is because Visual Studio is running out of memory (8 GB) for the huge numbers.
//	   Function 2 and 4, which are using loops instead of recursive functions, are not overflowing for relatively
//	   small numbers, because the non-recursive functions save memories comparatively.
//	
//	   Difference between functions: loop will just take a long time, but recursion will run out of memory.

// Q6. Because Visual Studio blows up for the first function, I used n = 4000 here.
//	   The results are:
//	   function1: 18896 clock ticks
//	   function2: 4339 clock ticks
//	   function3: 59 clock ticks
//	   function4: 16 clock ticks

// Q7. n = 10000000 (ten million)
//	   function3: 10853 clock ticks
//	   function4: 2292 clock ticks


#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

// --- prototype declarations ---
bool trapBadInput(int b, int n, int m);

int expmod1(int b, int n, int m);
int expmod2(int b, int n, int m);
int expmod3(int b, int n, int m);
int expmod4(int b, int n, int m);

void time1(int b, int n, int m);
void time2(int b, int n, int m);
void time3(int b, int n, int m);
void time4(int b, int n, int m);
void bigtime3(int b, int n, int m);
void bigtime4(int b, int n, int m);
// --- end prototypes ---

int _tmain(int argc, _TCHAR* argv[])
{
	int b, m, n;
	cout << "Enter value of base (b): ",
		cin >> b;
	cout << "\nEnter value of exponent (n): ",
		cin >> n;
	cout << "\nEnter value of modulus (m): ",
		cin >> m;

	if (trapBadInput(b, n, m))
	{
		if (b > m)
		{
			b = b % m;
		}
		time1(b, n, m);
		time2(b, n, m);
		time3(b, n, m);
		time4(b, n, m);

		bigtime3(b, n, m);
		bigtime4(b, n, m);
	}
	else
		cout << "Oops... The numbers are to big for this program." << endl;

	// Comment out if need to print out the result
	/*int result1 = expmod1(b, n, m);
	int result2 = expmod2(b, n, m);
	int result3 = expmod3(b, n, m);
	int result4 = expmod4(b, n, m);

	cout << "1: " << result1 << endl;
	cout << "2: " << result2 << endl;
	cout << "3: " << result3 << endl;
	cout << "4: " << result4 << endl;*/

	system("PAUSE");
	return 0;
}

bool trapBadInput(int b, int n, int m)
{
	if (b > 1 && m < 65536)
		return true;
	else
		return false;
}

int expmod1(int b,int n, int m)
{
	if (n == 0)
		return 1;
	else
	{
		return (expmod1(b, n - 1, m)*b) % m;
	}
}

int expmod2(int b, int n, int m)
{
	int result = 1;
	for (int i = 1; i <= n; i++)
	{
		result = (result*b) % m;
	}

	return result;
}

int expmod3(int b, int n, int m)
{
	if (n == 0)
		return 1;
	else if (n % 2 != 0)
		return (expmod3(b, n - 1, m)*b) % m;
	else
		return expmod3((b * b) % m, n / 2, m) % m;
}

int expmod4(int b, int n, int m)
{
	int result = 1, base = b, exp = n;
	while (exp != 0)
	{
		if (exp % 2 != 0)
		{
			result = (result * base) % m;
			exp = exp - 1;
		}
		else
		{
			base = (base * base) % m;
			exp = exp / 2;
		}
	}
	return result;
}

void time1(int b, int n, int m)
{
	clock_t start, end;
	start = clock();
	for (int i = 0; i < 50000; i++)
	{
		int result1 = expmod1(b, n, m);
	}
	end = clock();
	cout << "The computation 1 took " << (end - start) << " clock ticks." << endl;
}

void time2(int b, int n, int m)
{
	clock_t start, end;
	start = clock();
	for (int i = 0; i < 50000; i++)
	{
		int result2 = expmod2(b, n, m);
	}
	end = clock();
	cout << "The computation 2 took " << (end - start) << " clock ticks." << endl;
}

void time3(int b, int n, int m)
{
	clock_t start, end;
	start = clock();
	for (int i = 0; i < 50000; i++)
	{
		int result3 = expmod3(b, n, m);
	}
	end = clock();
	cout << "The computation 3 took " << (end - start) << " clock ticks." << endl;
}

void time4(int b, int n, int m)
{
	clock_t start, end;
	start = clock();
	for (int i = 0; i < 50000; i++)
	{
		int result4 = expmod4(b, n, m);
	}
	end = clock();
	cout << "The computation 4 took " << (end - start) << " clock ticks." << endl;
}

void bigtime3(int b, int n, int m)
{
	n = 25000;
	clock_t start, end;
	start = clock();
	for (int i = 0; i < 10000000; i++)
	{
		int result3 = expmod3(b, n, m);
	}
	end = clock();
	cout << "The BIG computation 3 took " << (end - start) << " clock ticks." << endl;
}

void bigtime4(int b, int n, int m)
{
	n = 25000;
	clock_t start, end;
	start = clock();
	for (int i = 0; i < 10000000; i++)
	{
		int result4 = expmod4(b, n, m);
	}
	end = clock();
	cout << "The BIG computation 4 took " << (end - start) << " clock ticks." << endl;
}