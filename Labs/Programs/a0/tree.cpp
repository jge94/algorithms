#include "stdafx.h"
#include <iostream>
#include "node.h"
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