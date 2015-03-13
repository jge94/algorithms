#include "stdafx.h"
#include<iostream>
#include<stdlib.h>

#include "node.h"

treeNode::treeNode()				// Default CTOR
{
	this->intPair.value1 = 0;
	this->intPair.value2 = 0;
	this->left = NULL;
	this->right = NULL;
}

treeNode::treeNode(integerPairs pair)		// CTOR with initializing with a value
{
	this->intPair.value1 = pair.value1;
	this->intPair.value2 = pair.value2;
	this->left = NULL;
	this->right = NULL;
}