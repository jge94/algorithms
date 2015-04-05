#include "stdafx.h"
#include <iostream>
#include <string>
#include "dictEntry.h"
#include "treeNode.h"
#include "searchTree.h"
#include "searchTreeNode.h"

using namespace std;

searchTreeNode::searchTreeNode(dictEntry* d)
{
	this->data = d;
	this->left = NULL;
	this->right = NULL;
	this->parent = NULL;
}


searchTreeNode::searchTreeNode(dictEntry* d, searchTreeNode* p)
{
	this->data = d;
	this->parent = p;
	this->left = NULL;
	this->right = NULL;
}


searchTreeNode::searchTreeNode(dictEntry* d, searchTreeNode* l, searchTreeNode* r, searchTreeNode* p)
{
	this->data = d;
	this->left = l;
	this->right = r;
	this->parent = p;
}


/*
a constructor that takes only a pointer to a dictEntry d as input, and initializes data to
d and sets all the pointers to NULL
• a constructor that takes a pointer to a dictEntry d and a pointer to a searchTreeNode p
as input, and initializes data to d, parent to p and left and right to NULL
• a constructor that takes a pointer to a dictEntry d and 3 pointers to a searchTreeNode
l, r and p as input and sets data, left, right and parent in the obvious way
*/