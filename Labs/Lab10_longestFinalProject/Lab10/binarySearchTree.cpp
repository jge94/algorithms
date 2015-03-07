#include "stdafx.h"
#include <iostream>
#include <string>
#include <queue>
#include "dictEntry.h"
#include "treeNode.h"
#include "searchTree.h"
#include "searchTreeNode.h"
#include "binarySearchTree.h"

using namespace std;

binarySearchTree::binarySearchTree()
{
	this->root = NULL;
}

void binarySearchTree::insert(dictEntry* in)
{
	if (this->root == NULL)
		root = new searchTreeNode(in, NULL, NULL, NULL); // OR GETWORD???
	else
		insert_h(in, root);
}

void binarySearchTree::insert_h(dictEntry* in, searchTreeNode* current)
{
	if (*(in) == current->data->getWord())
		return;
	else if (*(in) < current->data->getWord())
	{
		if (current->left == NULL)
			current->left = new searchTreeNode(in, NULL, NULL, current);
		else
			insert_h(in, current->left);
	}
	else if (current->right == NULL)
		current->right = new searchTreeNode(in, NULL, NULL, current);
	else
		insert_h(in, current->right);
}

searchTreeNode* binarySearchTree::search(string w)
{
	if (this->root != NULL)
		return search_h(w, root);    // --------------- ?????? ---------------------
	else
		return NULL;
}

searchTreeNode* binarySearchTree::search_h(string w, searchTreeNode* current)
{
	if (current == NULL)
		return NULL;
	else if (*(current->data) == w)
		return current;
	else if (*(current->data) > w)
		return search_h(w, current->left);
	else
		return search_h(w, current->right);
}

searchTreeNode * binarySearchTree::successor(searchTreeNode* n)
{
	if (n == NULL)
		return NULL;
	else if (n->right == NULL)
		return NULL;
	else
	{
		searchTreeNode *current = n->right;
		while (current->left != NULL)
		{
			current = current->left;
		}
		return current;
	} // end else
}

void binarySearchTree::remove(string w)
{
	searchTreeNode* todelete;
	todelete = search(w);
	if (todelete != NULL)
	{
		if (todelete->parent != NULL)
		{
			if (todelete->left == NULL)
			{
				if (todelete == todelete->parent->left)
				{
					todelete->parent->left = todelete->right;
					delete todelete;
				}// end todelete == todelete->parent->left
				else
				{
					todelete->parent->right = todelete->right;
					delete todelete;
				}// end else
			}// end todelete->left == NULL

			else if (todelete->right == NULL)
			{
				if (todelete == todelete->parent->left)
				{
					todelete->parent->left = todelete->left;
					delete todelete;
				}// end todelete == todelete->parent->left
				else
				{
					todelete->parent->right = todelete->left;
					delete todelete;
				}// end else
			}// end todelete->right == NULL

			else
			{
				searchTreeNode* todeleteSucc;
				todeleteSucc = successor(todelete);

				todelete->data = todeleteSucc->data;
				if (todeleteSucc == todeleteSucc->parent->left)  
				{
					todeleteSucc->parent->left = todeleteSucc->right;
					if (todeleteSucc->right != NULL)
					{
						todeleteSucc->right->parent = todeleteSucc->parent;
					}
					delete todeleteSucc;
				}// end todelete == todelete->parent->left
				else
				{
					todeleteSucc->parent->right = todeleteSucc->right;
					if (todeleteSucc->right != NULL)
					{
						todeleteSucc->right->parent = todeleteSucc->parent;
					}
					delete todeleteSucc;
				}// end else
			}
		}// end todelete->parent != NULL

		else // todelete->parent == NULL, todelete is the ROOT
		{  
			// what does this do?
			if (todelete->left == NULL)
			{
				root = todelete->right;
				delete todelete;
			}
			else if (todelete->right == NULL)
			{
				root = todelete->left;
				delete todelete;
			}
			else // both left and right are not NULL
			{
				searchTreeNode* todeleteSucc;
				todeleteSucc = successor(todelete);

				todelete->data = todeleteSucc->data;
				if (todeleteSucc == todeleteSucc->parent->left)
				{
					todeleteSucc->parent->left = todeleteSucc->right;
					if (todeleteSucc->right != NULL)
					{
						todeleteSucc->right->parent = todeleteSucc->parent;
					}
					delete todeleteSucc;
				}// end todelete == todelete->parent->left
				else
				{
					todeleteSucc->parent->right = todeleteSucc->right;
					if (todeleteSucc->right != NULL)
					{
						todeleteSucc->right->parent = todeleteSucc->parent;
					}
					delete todeleteSucc;
				}// end else
			}
		}
	}// end todelete != NULL 
}

void binarySearchTree::preOrder(string fileName)
{
	FOUT.open(fileName);
	preOrder_h(root);
	FOUT.close();
}

void binarySearchTree::preOrder_h(searchTreeNode* n)
{
	if (n != NULL)
	{
		preOrder_h(n->left);
		visit(n);
		preOrder_h(n->right);
	}
}

void binarySearchTree::postOrder(string fileName)
{
	FOUT.open(fileName);
	postOrder_h(root);
	FOUT.close();
}

void binarySearchTree::postOrder_h(searchTreeNode* n)
{
	if (n != NULL)
	{
		postOrder_h(n->right);
		visit(n);
		postOrder_h(n->left);
	}
}

void binarySearchTree::inOrder(string fileName)
{
	FOUT.open(fileName);
	inOrder_h(root);
	FOUT.close();
}

void binarySearchTree::inOrder_h(searchTreeNode* n)
{
	queue<searchTreeNode*> Q;
	Q.push(n);
	while (!Q.empty())
	{
		searchTreeNode* current = Q.front();
		Q.pop();
		visit(current);
		if (current->left != NULL)
		{
			Q.push(current->left);
		}
		if (current->right != NULL)
		{
			Q.push(current->right);
		}
	}// end while
}

void binarySearchTree::visit(searchTreeNode* n)
{
	FOUT << n->data->getWord() << ": " << n->data->getDefinition() << endl;
	cout << endl;
}