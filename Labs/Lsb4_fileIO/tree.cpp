#include "stdafx.h"
#include <iostream>
#include "node.h"
#include <algorithm>
#include "tree.h"

using namespace std;

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
void binarySearchTree::insert(integerPairs key)
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


// real function that does the inserting
void binarySearchTree::insert_help(integerPairs key, treeNode* leaf)
// assume left != NULL
{
	if ((key < leaf->intPair) && (leaf->left != NULL))			// less than the left, but still need to 
	{
		insert_help(key, leaf->left);
	}
	else if ((key < leaf->intPair) && (leaf->left == NULL))
	{
		leaf->left = new treeNode(key);
		// OR: 
		//leaf->left->value = key;
		//leaf->left->left = NULL;
		//leaf->left->right = NULL;
	}
	else if ((key > leaf->intPair) && (leaf->right != NULL))
	{
		insert_help(key, leaf->right);
	}
	else if ((key > leaf->intPair) && (leaf->right == NULL))
	{
		leaf->right = new treeNode(key);
	}
}


//  search value
bool binarySearchTree::search(integerPairs key)
{
	return this->search_help(key, root);
}


// real function to do the search
bool binarySearchTree::search_help(integerPairs key, treeNode* leaf)
{
	if (leaf == NULL)
		return false;
	else if (leaf->intPair == key)
		return true;
	else if (key < leaf->intPair)
		return search_help(key, leaf->left);
	else
		return search_help(key, leaf->right);
}

int binarySearchTree::depth(void)								// calculate the depth of the tree
{
	return this->depth_help(root);
}

int binarySearchTree::depth_help(treeNode* leaf)							// calculate the depth of the tree
{
	if (leaf == NULL)
		return 0;
	else
	{
		int d1 = depth_help(leaf->left);
		int d2 = depth_help(leaf->right);
		return (1 + max(d1, d2));
	}
}