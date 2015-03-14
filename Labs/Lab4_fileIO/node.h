#ifndef TREE_NODE
#define TREE_NODE

#include "stdafx.h"
#include "integerPairs.h"
#include <iostream>

class treeNode
{
	public:
		treeNode();					// default CTOR
		treeNode(integerPairs pair);		// intialization CTOR

		integerPairs intPair;
		treeNode *left, *right;
	
};// class treeNode

#endif