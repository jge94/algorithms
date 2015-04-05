#ifndef _SEARCHTREE
#define _SEARCHTREE

#include "stdafx.h"
#include "dictEntry.h"
#include <string>
#include "treeNode.h"

using namespace std;

class searchTree
{
	public:
		virtual void insert(dictEntry* dictEntryP) = 0;
		virtual treeNode* search(string s) = 0;
		virtual void remove(string s) = 0;
		virtual void preOrder(string fileName) = 0;
		virtual void postOrder(string fileName) = 0;
		virtual void inOrder(string fileName) = 0;
		virtual ~searchTree(){};
};
  
#endif