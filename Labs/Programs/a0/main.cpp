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

using namespace std;

class binarySearchTree
{
public:
	binarySearchTree();						// CTOR
	~binarySearchTree();					// DTOR

	void insert(int key);					// insert node
	bool search(int key);					// search value

	void inOrderTraversal();				// print in order

private:
	treeNode *root;									// pointer, but really is not pointing to node yet
	void destroy_tree(treeNode* leaf);				// DTOR function
	void insert_help(int key, treeNode* leaf);		// insert node
	bool search_help(int key, treeNode* leaf);		// search value
	void inOrderTraversal_help(treeNode* leaf);		// print in order

};// end binarySearchTree


// Default CTOR
binarySearchTree::binarySearchTree()
{
	this->root = NULL;			// NULL == 0
}


// Default DTOR
binarySearchTree::~binarySearchTree()
{
	this->destroy_tree(this->root);
}


// real function for DTOR
void binarySearchTree::destroy_tree(treeNode* leaf)
{
	if (leaf != NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}


// insert node with value
void binarySearchTree::insert(int key)
{
	if (this->root == NULL)
	{
		root = new treeNode(key);		// Better to use the CTOR
		//OR:
		//root->value = key;
		//root->left = NULL;
		//root->right = NULL;
	}
	else
	{
		this->insert_help(key, root);
	}
}


class treeNode
{
public:
	treeNode();					// default CTOR
	treeNode(int number);		// intialization CTOR

	int value;
	treeNode *left, *right;

};// class treeNode


// real function that does the inserting
void binarySearchTree::insert_help(int key, treeNode* leaf)
// assume left != NULL
{
	if ((key < leaf->value) && (leaf->left != NULL))			// less than the left, but still need to 
	{
		insert_help(key, leaf->left);
	}
	else if ((key < leaf->value) && (leaf->left == NULL))
	{
		leaf->left = new treeNode(key);
		// OR: 
		//leaf->left->value = key;
		//leaf->left->left = NULL;
		//leaf->left->right = NULL;
	}
	else if ((key > leaf->value) && (leaf->right != NULL))
	{
		insert_help(key, leaf->right);
	}
	else if ((key > leaf->value) && (leaf->right == NULL))
	{
		leaf->right = new treeNode(key);
	}
}


//  search value
bool binarySearchTree::search(int key)
{
	return this->search_help(key, root);
}


// real function to do the search
bool binarySearchTree::search_help(int key, treeNode* leaf)
{
	if (leaf == NULL)
		return false;
	else if (leaf->value == key)
		return true;
	else if (key < leaf->value)
		return search_help(key, leaf->left);
	else
		return search_help(key, leaf->right);
}


// print in order
void binarySearchTree::inOrderTraversal()
{
	this->inOrderTraversal_help(root);
}


// real function to print recursively
void binarySearchTree::inOrderTraversal_help(treeNode* leaf)
{
	if (leaf == NULL)
		return;
	else if (leaf != NULL)
	{
		inOrderTraversal_help(leaf->left);
		cout << leaf->value << endl;
		inOrderTraversal_help(leaf->right);
	}
}


treeNode::treeNode()				// Default CTOR
{
	this->value = 0;
	this->left = NULL;
	this->right = NULL;
}

treeNode::treeNode(int number)		// CTOR with initializing with a value
{
	this->value = number;
	this->left = NULL;
	this->right = NULL;
}



// ---------------- main function ---------------
int main()
{
	cout << "			 +++++++++ Binary Search Tree v1.0 +++++++++" << endl;
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

