// A C++ program to check if there is a cycle in
// directed graph using BFS.
#include <bits/stdc++.h>
using namespace std;

class Graph {
	int V; // No. of vertices'

	list<int>* adj;

public:
	Graph(int V); // Constructor

	void addEdge(int u, int v);

	bool isCycle();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
}

bool Graph::isCycle()
{
	vector<int> in_degree(V, 0);

	for (int u = 0; u < V; u++) {
		for (auto v : adj[u])
			in_degree[v]++;
	}

	queue<int> q;
	for (int i = 0; i < V; i++)
		if (in_degree[i] == 0)
			q.push(i);

	int cnt = 1;

	vector<int> top_order;

	while (!q.empty()) {

		int u = q.front();
		q.pop();
		top_order.push_back(u);

		list<int>::iterator itr;
		for (itr = adj[u].begin(); itr != adj[u].end(); itr++)

			if (--in_degree[*itr] == 0)
			{
			q.push(*itr);
			cnt++;
			}

		
	}

	if (cnt != V)
		return true;
	else
		return false;
}

int main()
{
	Graph g(6);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(3, 4);
	g.addEdge(4, 5);

	if (g.isCycle())
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
