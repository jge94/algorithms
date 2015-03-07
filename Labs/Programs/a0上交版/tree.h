#ifndef TREE
#define TREE
// tree.h

#include "stdafx.h"
#include "node.h"
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

#endif