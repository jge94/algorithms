#ifndef TREE
#define TREE
// tree.h

#include "stdafx.h"
#include "node.h"
#include "integerPairs.h"
#include <iostream>

using namespace std;

class binarySearchTree
{
	public:
		binarySearchTree();						// CTOR
		~binarySearchTree();					// DTOR

		void insert(integerPairs key);					// insert node
		bool search(integerPairs key);					// search value
		int depth(void);								// calculate the depth of the tree

	private:
		treeNode *root;									// pointer, but really is not pointing to node yet
		void destroy_tree(treeNode* leaf);				// DTOR function
		void insert_help(integerPairs key, treeNode* leaf);		// insert node
		bool search_help(integerPairs key, treeNode* leaf);		// search value
		int depth_help(treeNode* nodePointer);

};// end binarySearchTree

#endif