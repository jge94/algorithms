#include "stdafx.h"
#include <iostream>
#include <queue>
#include "myGraph.h"

using namespace std;

myGraph::myGraph()
{
	this->nbVertices = 0;
	this->adjMatrix = NULL;
}

myGraph::myGraph(int num)
{
	this->nbVertices = num;
	this->adjMatrix = new int*[nbVertices];
	for (int i = 0; i < nbVertices; i++)
	{
		adjMatrix[i] = new int[nbVertices];
	}
	mark = new int[num];
	markPrime = new int[num];
}

myGraph::~myGraph()
{
	for (int i = 0; i < nbVertices; i++)
		delete[] adjMatrix[i];
	delete[] adjMatrix;
}

void myGraph::DFS()
{
	for (int v = 0; v < nbVertices; v++)
	{
		mark[v] = 0;
		markPrime[v] = 0;
	}

	count = 0;
	countPrime = 0;
	
	for (int v = 0; v < nbVertices; v++)
	{
		if (mark[v] == 0)
		{
			dfs(v);
		}
	}

	// print out results
	cout << "\nThe order in which the vertices were added to the DFS graph: ";
	for (int v = 0; v < nbVertices; v++)
	{
		cout << mark[v] <<" ";
	}
	
	cout << "\n\nThe order in which the vertices were popped from the stack: ";
	for (int v = 0; v < nbVertices; v++)
	{
		cout << markPrime[v] << " ";
	}
	cout << endl;
}

void myGraph::BFS()
{
	for (int v = 0; v < nbVertices; v++)
	{
		mark[v] = 0;
		markPrime[v] = 0;
	}

	count = 0;
	countPrime = 0;

	for (int v = 0; v < nbVertices; v++)
	{
		if (mark[v] == 0)
		{
			bfs(v);
		}
	}

	//print result
	cout << "\nThe order in which the vertices were added to the BFS queue: ";
	for (int v = 0; v < nbVertices; v++)
	{
		cout << mark[v] << " ";
	}
	cout << endl << endl;
}
			/*
			queue<int> oneQueue = bfs(v);
			copyQueue = oneQueue;
		}
	}

	//cout << endl;

	//print result
	cout << "The order in which the vertices were added to the BFS queue: " << endl;
	while (!copyQueue.empty())
	{
		cout << copyQueue.front();
		copyQueue.pop();
	}
	cout << endl;
}*/

void myGraph::dfs(int v)
{
	count++;
	mark[v] = count;
	for (int w = 0; w < nbVertices; w++)
	{
		if (this->adjMatrix[v][w] = 1)
		{
			if (mark[w] == 0)
				dfs(w);
		}
	}

	countPrime++;
	markPrime[v] = countPrime;
}

void myGraph::bfs(int v)
{
	count++;
	mark[v] = count;

	queue<int> myQueue;
	myQueue.push(v);
	int front = myQueue.front();

	while (!myQueue.empty())
	{
		for (int w = 0; w < nbVertices; w++)
		{
			if (this->adjMatrix[front][w] == 1)
			{
				if (mark[w] == 0)
				{
					count++;
					mark[w] = count;
					myQueue.push(w);
					//cout << w << " ";
				}
			}// neighbor to front
		}// each w
		myQueue.pop();
	}//not empty
}