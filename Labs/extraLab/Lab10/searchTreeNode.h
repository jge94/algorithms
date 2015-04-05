#ifndef _SEARCHTREENODE
#define _SEARCHTREENODE

#include "stdafx.h"
#include "dictEntry.h"
#include <string>
#include "treeNode.h"
#include "searchTree.h"

using namespace std;

class searchTreeNode:public treeNode
{
	public:
		searchTreeNode* left;
		searchTreeNode* right;
		searchTreeNode* parent;

		searchTreeNode(dictEntry* d);
		searchTreeNode(dictEntry* d, searchTreeNode* p);
		searchTreeNode(dictEntry* d, searchTreeNode* l, searchTreeNode* r, searchTreeNode* p);
};

#endif