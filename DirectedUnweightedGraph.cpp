#include "DirectedUnweightedGraph.h"

using namespace std;

DirectedUnweightedGraph::DirectedUnweightedGraph(int count)
{
	numberOfVertices = count;
	adjacencyList.resize(numberOfVertices);
}

void DirectedUnweightedGraph::addEdge(Edge edge)
{
	adjacencyList[edge.source].push_back(edge.destination);
}

void DirectedUnweightedGraph::BFS()
{
	queue<int> queue;
	vector<bool> visited(numberOfVertices, false);

	queue.push(0);
	visited[0] = true;

	while (!queue.empty())
	{
		int currentVertex = queue.front();
		queue.pop();

		cout << currentVertex << " ";

		for (int neighbor : adjacencyList[currentVertex])
		{
			if (!visited[neighbor])
			{
				queue.push(neighbor);
				visited[neighbor] = true;
			}
		}
	}
}

void DirectedUnweightedGraph::DFSRec(int vertex, vector<bool>& visited)
{
	visited[vertex] = true;
	cout << vertex << " ";

	for (int neighbor : adjacencyList[vertex])
	{
		if (!visited[neighbor])
		{
			DFSRec(neighbor, visited);
		}
	}
}

void DirectedUnweightedGraph::DFS()
{
	vector<bool> visited(numberOfVertices, false);

	for (int i = 0; i < numberOfVertices; i++)
	{
		if (!visited[i])
		{
			DFSRec(i, visited);
		}
	}
}