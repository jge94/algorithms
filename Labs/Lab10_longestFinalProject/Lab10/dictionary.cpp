
#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "dictEntry.h"
#include "treeNode.h"
#include "searchTree.h"
#include "searchTreeNode.h"
#include "binarySearchTree.h"
#include "RBsearchTreeNode.h"
#include "RBsearchTree.h"
#include "dictionary.h"

using namespace std;

dictionary::dictionary(searchTree* d)		//CTOR
{
	this->dict = d;
}

dictionary::~dictionary()					//DTOR
{
	delete this->dict;
}

void dictionary::search(string word)
{
	// Make uppercase
	for (unsigned int i = 0; i < word.length(); i++)
	{
		word[i] = toupper(word[i]);
	}

	treeNode* searchQuery = this->dict->search(word);

	if (searchQuery == NULL)
	{
		cout << "The word " << word << " was not found in the dictionary." << endl;
	}
	else
	{
		cout << searchQuery->data->getWord() << " : " << searchQuery->data->getDefinition() << endl;
	}   
}

void dictionary::add(dictEntry* in)
{	
	dict->insert(in);
}

void dictionary::remove(string word)
{
	dict->remove(word);
}

void dictionary::readFile(string fileName)
{
	ifstream aFile;
	aFile.open(fileName);
	stringstream ssin;

	string line;
	string word;
	string definition;

	while (!aFile.eof())
	{
		getline(aFile, line);

		ssin.clear();
		ssin.str(line);

		ssin >> word;
		for (unsigned int i = 0; i < line.length(); i++)
		{
			definition = definition + line[i];
		}

		dictEntry newDefinition(word, definition);
	}
}


void dictionary::writeFilePreorder(string w)
{
	dict->preOrder(w);
}


void dictionary::writeFileInorder(string w)
{
	dict->inOrder(w);
}


void dictionary::writeFilePostorder(string w)
{
	dict->postOrder(w);
}