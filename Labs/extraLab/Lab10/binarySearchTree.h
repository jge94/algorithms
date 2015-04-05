#ifndef _BST
#define _BST

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include "dictEntry.h"
#include "treeNode.h"
#include "searchTree.h"
#include "searchTreeNode.h"

using namespace std;

class binarySearchTree :public searchTree
{
	protected:
		searchTreeNode* root;
		ofstream FOUT;

		virtual void insert_h(dictEntry* in, searchTreeNode* current);
		virtual searchTreeNode* search_h(string w, searchTreeNode* current);

		virtual void preOrder_h(searchTreeNode* n);
		virtual void postOrder_h(searchTreeNode* n);
		virtual void inOrder_h(searchTreeNode* n);

		virtual void visit(searchTreeNode* n);

	public:
		binarySearchTree();

		virtual void insert(dictEntry* in);
		virtual searchTreeNode* search(string w);

		virtual searchTreeNode* successor(searchTreeNode* n);
		virtual void remove(string w);

		virtual void preOrder(string fileName);
		virtual void postOrder(string fileName);
		virtual void inOrder(string fileName);
		/*
		 A public virtual function search that takes a string w, searches for it into the tree
		and returns a pointer to the node whose dictEntry's word member is equal to w. This
		function has a corresponding protected helper function search h.
		 A public virtual function remove that takes a string w and removes the node in the tree
		whose dictEntry's word member is equal to w. If no such node exists, the function does
		nothing.
		 Public virtual functions preOrder, postOrder and inOrder with their corresponding
		protected helper functions preOrder h, postOrder h and inOrder h (though, for in-
		Order, the helper function is not strictly necessary, feel free to do everything in the
		public function if you feel like it)
		*/
};

#endif