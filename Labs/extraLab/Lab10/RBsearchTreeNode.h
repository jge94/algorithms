#ifndef _RB_STN
#define _RB_STN

#include "dictEntry.h"
#include "treeNode.h"
#include "searchTree.h"
#include "searchTreeNode.h"

enum RBcolor{RED, BLACK};

class RBsearchTreeNode:public treeNode
{
	public:
		RBcolor color;
		RBsearchTreeNode();
		
		RBsearchTreeNode* left;
		RBsearchTreeNode* right;
		RBsearchTreeNode* parent;

		RBsearchTreeNode(dictEntry* d);
		RBsearchTreeNode(dictEntry* d, RBsearchTreeNode* p);
		RBsearchTreeNode(dictEntry* d, RBsearchTreeNode* l, RBsearchTreeNode* r, RBsearchTreeNode* p);
};

#endif