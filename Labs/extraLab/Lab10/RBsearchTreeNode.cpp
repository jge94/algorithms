#include "stdafx.h"
#include <iostream>
#include <string>
#include "dictEntry.h"
#include "treeNode.h"
#include "searchTree.h"
#include "RBsearchTreeNode.h"

using namespace std;

RBsearchTreeNode::RBsearchTreeNode()
{
	this->color = RED;
}

RBsearchTreeNode::RBsearchTreeNode(dictEntry* d)
{
	this->color = RED;
	this->data = d;
	this->left = NULL;
	this->right = NULL;
	this->parent = NULL;
}

RBsearchTreeNode::RBsearchTreeNode(dictEntry* d, RBsearchTreeNode* p)
{
	this->color = RED;
	this->data = d;
	this->left = NULL;
	this->right = NULL;
	this->parent = p;
}

RBsearchTreeNode::RBsearchTreeNode(dictEntry* d, RBsearchTreeNode* l, RBsearchTreeNode* r, RBsearchTreeNode* p)
{
	this->color = RED;
	this->data = d;
	this->left = l;
	this->right = r;
	this->parent = p;
}