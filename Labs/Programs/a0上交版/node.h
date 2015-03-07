#ifndef TREE_NODE
#define TREE_NODE

#include "stdafx.h"
#include <iostream>

class treeNode
{
	public:
		treeNode();					// default CTOR
		treeNode(int number);		// intialization CTOR

		int value;
		treeNode *left, *right;
	
};// class treeNode

#endif