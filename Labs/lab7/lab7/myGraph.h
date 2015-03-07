// myGraph.h
#ifndef _MYGRAPH
#define _MYGRAPH

#include <queue>

class myGraph
{
	public:
		int nbVertices;
		int** adjMatrix;

		int count;
		int countPrime;
		int* mark;
		int* markPrime;
		int v;		// vertex, arg of dfs()

		myGraph();
		myGraph(int num);
		~myGraph();

		// functions
		void DFS();
		void BFS();
		
		//an integer count and arrays of integers mark and markPrime as indicated in class

	private:
		void dfs(int v);
		void bfs(int v);
};

#endif