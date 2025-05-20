// Graph Store in List Format
#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}

// Print the graph
void printGraph(vector<int> adj[], int V)
{
  for (int i = 0; i < V; ++i)
  {
    cout << "Vertex " << i << " :";
    for (auto x : adj[i])
    {
      cout << " => " << x;
    }
    cout << endl;
  }
}

int main()
{
  int v = 5;

  // Create a graph
  vector<int> adj[v];

  // Add edges
  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 0, 3);
  addEdge(adj, 1, 2);
  printGraph(adj, v);
}