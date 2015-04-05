#ifndef _DICTIONARY
#define _DICTIONARY

#include <iostream>
#include <string>

#include "dictEntry.h"
#include "treeNode.h"
#include "searchTree.h"
#include "searchTreeNode.h"
#include "binarySearchTree.h"
#include "RBsearchTreeNode.h"
#include "RBsearchTree.h"

class dictionary
{
	protected:
		searchTree* dict;


	public:
		dictionary(searchTree* d);			// CTOR
		~dictionary();						// DTOR

		void search(string w);
		void add(dictEntry* in);
		void remove(string w);
		void readFile(string fileName);

		virtual void writeFilePreorder(string w);
		virtual void writeFileInorder(string w);
		virtual void writeFilePostorder(string w);
};

#endif
