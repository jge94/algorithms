#include "stdafx.h"
#include<iostream>
#include<stdlib.h>

#include "node.h"

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