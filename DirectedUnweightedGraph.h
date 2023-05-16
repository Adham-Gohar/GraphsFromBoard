#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Edge
{
	int source;
	int destination;
};

class UndirectedWeightedGraph
{
private:
	int numberOfVertices;
	vector<vector<int>> adjacencyList;

public:
	UndirectedWeightedGraph(int count)
	{
		numberOfVertices = count;
		adjacencyList.resize(numberOfVertices);
	}

	void addEdge(Edge edge)
	{
		adjacencyList[edge.source].push_back(edge.destination);
		adjacencyList[edge.destination].push_back(edge.source);
	}

	void BFS()
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

	void DFSRec(int vertex, vector<bool>& visited)
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

	void DFS()
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
};

int main()
{
	// Create a graph
	UndirectedWeightedGraph graph(44);

	// Read the text file
	ifstream file("Board.txt");
	string line;

	while (getline(file, line))
	{
		// Split the line into tokens
		vector<string> tokens;
		stringstream ss(line);
		while (getline(ss, tokens, ' '))
		{
			tokens.push_back(tokens);
		}

		// Add an edge to the graph
		if (tokens.size() == 2)
		{
			int source = stoi(tokens[0]);
			int destination = stoi(tokens[1]);

			if (source != -1 && destination != -1)
			{
				graph.addEdge({ source, destination, 1 });
			}
		}
	}

	// Print the graph
	for (int i = 0; i < graph.numberOfVertices; i++)
	{
		cout << i << ": ";
		for (int neighbor : graph.adjacencyList[i])
		{
			cout << neighbor << " ";
		}
		cout << endl;
	}

	cout << "Graph:" << endl;
	graph.BFS();
	cout << endl;
	graph.DFS();
	cout << endl;

	return 0;
}
