// lab7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "myGraph.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream FIN;
	ofstream FOUT;
	
	string fileName;
	int nbVertices;
	int matrixValue;

	cout << "Enter the file name: ",
		cin >> fileName;

	FIN.open(fileName.c_str());

	while (!FIN.is_open())
	{
		cout << "\nUnable to open file, please enter the file name again: ",
			cin >> fileName;
		FIN.open(fileName.c_str());
	}

	if (FIN.is_open())
	{
		FIN >> nbVertices;
		myGraph myGraph(nbVertices);
		for (int row = 0; row < nbVertices; row++)
		{
			for (int column = 0; column < nbVertices; column++)
			{
				FIN >> matrixValue;
				myGraph.adjMatrix[row][column] = matrixValue;
			}// column
		}//row

		myGraph.DFS();
		myGraph.BFS();
	}

	system("PAUSE");
	return 0;
}

