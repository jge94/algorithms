// Lab10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>

#include "dictEntry.h"
#include "searchTreeNode.h"
#include "searchTree.h"
#include "treeNode.h"
#include "dictEntry.h"
#include "binarySearchTree.h"
#include "RBsearchTreeNode.h"
#include "RBSearchTree.h"
#include "dictionary.h"


using namespace std;

// PROTOTYPE
void printProcess(dictionary* myDic);

// MAIN
int _tmain(int argc, _TCHAR* argv[])
{
	/* TESTING
	string s1 = "abcd";
	string s2 = "edfg";
	string s3 = "mnl";
	
	cout << strcmp(s1.c_str(), s2.c_str()) << endl;
	cout << strcmp(s2.c_str(), s3.c_str()) << endl;
	cout << strcmp(s3.c_str(), s1.c_str()) << endl;

	dictEntry obj("mnl","mnl");
	bool a;
	a = obj < "edfg";
	if (a == true)
		cout << "true" << endl;
	else
		cout << "false" << endl;*/
	
	cout << "			---------- MY DICTIONARY ----------\n" << endl;
	dictionary* myDic;

	char treeType;

	cout << "Enter according to the following options:" << endl;
	cout << "'R' -- Red - Black tree " << endl;
	cout << "'B' -- Binary search tree" << endl;
	cout << "Enter here: ",
		cin >> treeType;
	cout << endl;

	treeType = toupper(treeType);

	while (treeType != 'R' && treeType != 'B')
	{
		cout << "Invalid input! Enter either 'R' or 'B'." << endl;
		cout << "Enter again: ",
			cin >> treeType;
	}

	if (treeType == 'R')
	{
		cout << "Red-Black tree..." << endl;
		RBsearchTree* RBp = new RBsearchTree;
		myDic = new dictionary(RBp);
		printProcess(myDic);
	}
	else if (treeType == 'B')
	{
		cout << "Binary Search Tree..." << endl;
		binarySearchTree* BSTp = new binarySearchTree;
		myDic = new dictionary(BSTp);
		printProcess(myDic);
	}

	system("PAUSE");
	return 0;
}


void printProcess(dictionary* myDic)
{
	int option;
	cout << "\nOption 1: Read a File" << endl;
	cout << "Option 2: Add an Entry" << endl;
	cout << "Option 3: Search in Dictionary" << endl;
	cout << "Option 4: Remove from Dictionary" << endl;
	cout << "Option 5: Write to File" << endl;
	cout << "Option 0: End Program" << endl;
	cout << "Enter an integer: ";
	cin >> option;

	while (option != 0 && option != 1 && option != 2 && option != 3 && option != 4 && option != 5)
	{
		cout << "Invalid input, enter again: ",
			cin >> option;
	}

	while (option != 0)
	{
		if (option == 1)
		{
			string fileName;
			cout << "Name of the file to read from: ";
			cin >> fileName;

			myDic->readFile(fileName);
		}
		else if (option == 2)
		{
			string word;
			string definition;

			cout << "Enter a word to add: ";
			cin >> word;
			
			// Make uppercase
			for (unsigned int i = 0; i < word.length(); i++)
			{
				word[i] = toupper(word[i]);
			}

			cout << endl << "Enter a definition to add: ";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(cin, definition);
			cout << endl;

			dictEntry * userEntry = new dictEntry(word, definition);

			myDic->add(userEntry);
		}
		else if (option == 3)
		{
			string userWord;
			cout << "Enter a word to search for: ";
			cin >> userWord;

			myDic->search(userWord);
		}
		else if (option == 4)
		{
			string userWord;
			cout << "Enter a word to delete: ";
			cin >> userWord;

			myDic->remove(userWord);
		}
		else if (option == 5)
		{
			string userFile;
			cout << "Filename you want to write: ";
			cin >> userFile;
			cout << endl;
			int userNum;
			cout << "How do you what to write the file?" << endl;
			cout << "1 In-Order Traversal" << endl;
			cout << "2 Pre-Order Traversal" << endl;
			cout << "3 Post-Order Traversal" << endl;
			cin >> userNum;

			if (userNum == 1)
			{
				myDic->writeFileInorder(userFile);
			}
			else if (userNum == 2)
			{
				myDic->writeFilePreorder(userFile);
			}
			else if (userNum == 3)
			{
				myDic->writeFilePostorder(userFile);
			}

		}
		else if (option == 0)
		{
			delete myDic;
		}

		cout << endl;
		cout << "\nOption 1: Read a File" << endl;
		cout << "Option 2: Add an Entry" << endl;
		cout << "Option 3: Search in Dictionary" << endl;
		cout << "Option 4: Remove from Dictionary" << endl;
		cout << "Option 5: Write to File" << endl;
		cout << "Option 0: End Program" << endl;
		cout << "Enter an integer: ";
		cin >> option;
	}
}