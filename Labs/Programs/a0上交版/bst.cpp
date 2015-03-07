// hw1.cpp : Defines the entry point for the console application.
//

// Programmer: Jinnan Ge
// Date: 09/08/2014

// Summary:
//		This program creates a binary search tree, prompt the user for input to build the tree,
//		search for specific numbers and prints all numbers in the tree in order to console.

// Input: Standard, Keyboard
//		1) integers to insert
//		2) integers to search


// Output: (to console)
//		1) Found or not found based on the integers from input
//		2) Print out all numbers in the tree (all numbers entered by the user)


//				********* ANSWER TO QUESTIONS **********
// The output of inOrderTraversal is always print out the numbers in order,
// from the smallest to the largest number. Because during the recursion,
// we make the function go to left (smallest) first, then print, then to the
// right (biggest).


#include "stdafx.h"
#include <iostream>
#include "node.h"
#include "tree.h"

using namespace std;


// ---------------- main function ---------------
int main()
{
	cout << "       +++++++++ Binary Search Tree v1.0 +++++++++" << endl;
	cout << "Please enter positive integers to continue, non-negative integers to stop. " << endl;

	int value, searchVal;
	binarySearchTree oneTree;
	cout << "\nEnter the integer: ",
		cin >> value;

	// prompt for input as long as the number entered is non negative
	while (value > 0)
	{
		oneTree.insert(value);
		cout << "Enter the integer: ",
			cin >> value;
	}

	// search number
	cout << "\nEnter an integer you want to search: ",
		cin >> searchVal;

	// keep searching as long as input is non negative
	while (searchVal > 0)
	{
		if (oneTree.search(searchVal))
			cout << "Yayyy...Found!" << endl;
		else
			cout << "Nahhhh... Not found... " << endl;

		cout << "Enter an integer you want to search: ",
			cin >> searchVal;
	}

	// print out all nubmers in tree
	cout << "\nNumbers in the tree are: " << endl;
	oneTree.inOrderTraversal();

	system("pause");
	return 0;
}

