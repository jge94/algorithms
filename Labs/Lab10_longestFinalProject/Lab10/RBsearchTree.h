#ifndef _RB_SEARCH_TREE
#define _RB_SEARCH_TREE

#include <iostream>
#include <fstream>
#include "dictEntry.h"
#include "treeNode.h"
#include "searchTree.h"
#include "searchTreeNode.h"
#include "RBsearchTreeNode.h"

class RBsearchTree:public searchTree
{
	protected:
		RBsearchTreeNode* root;
		ofstream FOUT;

		// --------- insert ---------
		virtual RBsearchTreeNode* insert_h(dictEntry*in, RBsearchTreeNode* current);
		void insert_fixup(RBsearchTreeNode* n);

		// --------- search ---------
		virtual RBsearchTreeNode* search_h(string w, RBsearchTreeNode* current);

		// --------- remove ---------
		void remove_fixup(RBsearchTreeNode * n);

		// --------- order transversals ---------
		virtual void preOrder_h(RBsearchTreeNode* n);
		virtual void postOrder_h(RBsearchTreeNode* n);
		virtual void inOrder_h(RBsearchTreeNode* n);

		virtual void visit(RBsearchTreeNode* n);

	public:
		RBsearchTree();				// CTOR
		~RBsearchTree();			// DTOR
		RBcolor Color(RBsearchTreeNode* n);				// change color

		void destruct_tree(RBsearchTreeNode* n);		// DTOR helper

		RBsearchTreeNode* uncle(RBsearchTreeNode* n);
		RBsearchTreeNode* sibling(RBsearchTreeNode* n);

		// --------- insert and search ---------
		virtual void insert(dictEntry* in);
		virtual RBsearchTreeNode* search(string w);

		// --------- successor and remove ---------
		virtual RBsearchTreeNode* successor(RBsearchTreeNode* n);
		virtual void remove(string w);

		// ------------- transformation ----------
		void swap(RBsearchTreeNode* nOne, RBsearchTreeNode* nTwo);
		void rotate_left(RBsearchTreeNode* n);
		void rotate_right(RBsearchTreeNode* n);

		// --------- order traversals ---------
		virtual void preOrder(string fileName);
		virtual void postOrder(string fileName);
		virtual void inOrder(string fileName);
};

#endif
