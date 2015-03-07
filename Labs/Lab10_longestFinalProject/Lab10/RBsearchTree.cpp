#include "stdafx.h"
#include "RBsearchTree.h"
#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

RBsearchTree::RBsearchTree()
{
	this->root = NULL;
}

RBsearchTree::~RBsearchTree()
{
	destruct_tree(root);
}

void RBsearchTree::destruct_tree(RBsearchTreeNode* n)
{
	if (n->left != NULL && n->right != NULL)
	{
		delete n->left;
		delete n->right;
		delete n;
	}
}

RBcolor RBsearchTree::Color(RBsearchTreeNode* n)
{
	if (n == NULL)
		return BLACK;
	else
		return n->color;
}

void RBsearchTree::insert(dictEntry* in)
{
	RBsearchTreeNode* n;
	if (this->root == NULL)
	{
		root = new RBsearchTreeNode(in);
		n = root;
	}
	else
		n = insert_h(in, root);

	if (n != NULL)
		insert_fixup(n);
}

RBsearchTreeNode* RBsearchTree::insert_h(dictEntry *in, RBsearchTreeNode * current)
{
	if (*(in) < current->data->getWord() && current->left != NULL)
		return insert_h(in, current->left);

	else if (*(in) < current->data->getWord())
	{
		current->left = new RBsearchTreeNode(in, current);
		return current->left;
	}

	else if (*(in) > current->data->getWord() && current->right != NULL)
		return insert_h(in, current->right);

	else if (*(in) > current->data->getWord())
	{
		current->right = new RBsearchTreeNode(in, current);
		return current->right;
	}

	else
		return NULL;
}

void RBsearchTree::insert_fixup(RBsearchTreeNode * n)
{
	if (n->parent == NULL)
		n->color = BLACK;

	else if (n->parent->color == BLACK)
		return;

	else
	{
		RBsearchTreeNode* p = n->parent;
		RBsearchTreeNode* g = p->parent;
		RBsearchTreeNode* u = uncle(n);

		if (Color(u) == BLACK)
		{
			if (n == p->right && p == g->left)
			{
				rotate_left(p);
				swap(p, n);
			}
			if (n == p->left && p == g->right)
			{
				rotate_right(p);
				swap(p, n);
			}

			p->color = BLACK;
			g->color = RED;

			if (n == p->left)
				rotate_right(g);
			else
				rotate_left(g);
		}// end Color(u) == BLACK

		else
		{
			p->color = BLACK;
			u->color = BLACK;
			g->color = RED;
			insert_fixup(g);
		}// end else
	}
}

RBsearchTreeNode* RBsearchTree::uncle(RBsearchTreeNode* n)
{
	RBsearchTreeNode* p;
	RBsearchTreeNode* g;
	if (n->parent != NULL)
	{
		p = n->parent;
		if (p->parent != NULL)
		{
			g = p->parent;
			if (p = g->left)
			{
				return g->right;
			}
			else
			{
				return g->left;
			}
		}// end if p->parent != NULL
	}//end n->parent != NULL
}

RBsearchTreeNode * RBsearchTree::sibling(RBsearchTreeNode * n)
{
	if (n == NULL)
	{
		return NULL;
	}
	else if (n->parent == NULL)
	{
		return NULL;
	}
	else if (n == n->parent->left)
	{
		return n->parent->right;
	}
	else
		return n->parent->left;
}

void RBsearchTree::rotate_left(RBsearchTreeNode* x)
{
	RBsearchTreeNode* y = x->right;
	x->right = y->left;

	if (y->left != NULL)
	{
		y->left->parent = x;
	}

	y->parent = x->parent;

	if (x->parent == NULL)
		root = y;

	else if (x == x->parent->left)
		x->parent->left = y;

	else
		x->parent->right = y;

	y->left = x;
	x->parent = y;
}

void RBsearchTree::rotate_right(RBsearchTreeNode* x)
{
	RBsearchTreeNode* y = x->left;
	x->left = y->right;

	if (y->right != NULL)
	{
		y->right->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == NULL)
	{
		root = y;
	}
	else if (x == x->parent->right)
	{
		x->parent->right = y;
	}
	else
	{
		x->parent->left = y;
	}
	y->right = x;
	x->parent = y;
}

void RBsearchTree::swap(RBsearchTreeNode* nOne, RBsearchTreeNode * nTwo)
{
	RBsearchTreeNode * temp;
	temp = nOne;
	nOne = nTwo;
	nTwo = temp;
}

RBsearchTreeNode* RBsearchTree::search(string w)
{
	if (root != NULL)
		return search_h(w, root);

	else
		return NULL;
}

RBsearchTreeNode * RBsearchTree::search_h(string key, RBsearchTreeNode* current)
{
	if (current == NULL)
		return NULL;

	else if (current->data->getWord() == key)
		return current;

	else if (key < current->data->getWord())
		return search_h(key, current->left);

	else
		return search_h(key, current->right);
}

RBsearchTreeNode * RBsearchTree::successor(RBsearchTreeNode* n)
{
	if (n == NULL)
		return NULL;

	else if (n->right == NULL)
		return NULL;

	else
	{
		RBsearchTreeNode * current = n->right;
		while (current->left != NULL)
		{
			current = current->left;
		}
		return current;
	}
}

void RBsearchTree::remove(string w)
{
	RBsearchTreeNode* y;
	RBsearchTreeNode* z = search(w);
	if (z == NULL)
		return;

	if (z->left == NULL && z->right == NULL)
		y = z;

	else
	{
		y = successor(z);
		z->data = y->data;
	}
	if (y->left != NULL)
	{
		y->data = y->left->data;
		delete y->left;
		y->left = NULL;
		return;
	}
	if (y->right != NULL)
	{
		y->data = y->right->data;
		delete y->right;
		y->right = NULL;
		return;
	}
	if (y->color == BLACK)
	{
		remove_fixup(y);
	}
	if (y->parent == NULL)
	{
		root = NULL;
	}
	else if (y == y->parent->left)
	{
		y->parent->left = NULL;
	}
	else
	{
		y->parent->right = NULL;
	}
	delete y;
}

void RBsearchTree::remove_fixup(RBsearchTreeNode * n)
{
	if (n->parent == NULL)
		return;

	RBsearchTreeNode* s = sibling(n);

	if (s->color == RED)
	{
		n->parent->color = RED;
		s->color = BLACK;
		if (n = n->parent->left)
		{
			rotate_left(n->parent);
		}
		else
		{
			rotate_right(n->parent);
		}
		s = sibling(n);
	}

	if (n == n->parent->left && Color(s->right) == BLACK && Color(s->left) == RED)
	{
		s->color = RED;
		s->left->color = BLACK;
		rotate_right(s);
	}

	else if (n == n->parent->right && Color(s->left) == BLACK && Color(s->right) == RED)
	{
		s->color = RED;
		s->right->color = BLACK;
		rotate_left(s);
	}

	if (n == n->parent->left && Color(s->right) == RED)
	{
		s->color = n->parent->color;
		n->parent->color = BLACK;
		s->right->color = BLACK;
		rotate_left(n->parent);
		return;
	}

	else if (n == n->parent->right && Color(s->left) == RED)
	{
		s->color = n->parent->color;
		n->parent->color = BLACK;
		s->left->color = BLACK;
		rotate_right(n->parent);
		return;
	}
}

void RBsearchTree::preOrder(string fileName)
{
	FOUT.open(fileName);
	preOrder_h(root);
	FOUT.close();
}

void RBsearchTree::preOrder_h(RBsearchTreeNode* n)
{
	if (n != NULL)
	{
		preOrder_h(n->left);
		visit(n);
		preOrder_h(n->right);
	}
}

void RBsearchTree::postOrder(string fileName)
{
	FOUT.open(fileName);
	postOrder_h(root);
	FOUT.close();
}

void RBsearchTree::postOrder_h(RBsearchTreeNode* n)
{
	if (n != NULL)
	{
		postOrder_h(n->right);
		visit(n);
		postOrder_h(n->left);
	}
}

void RBsearchTree::inOrder(string fileName)
{
	FOUT.open(fileName);
	inOrder_h(root);
	FOUT.close();
}

void RBsearchTree::inOrder_h(RBsearchTreeNode* n)
{
	queue<RBsearchTreeNode*> Q;
	Q.push(n);
	while (!Q.empty())
	{
		RBsearchTreeNode* current = Q.front();
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

void RBsearchTree::visit(RBsearchTreeNode* n)
{
	FOUT << n->data->getWord() << ": " << n->data->getDefinition() << endl;
	cout << endl;
}
