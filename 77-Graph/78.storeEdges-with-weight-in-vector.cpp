#include <iostream>
#include <vector>
using namespace std;

// To add an edge
void addEdge(vector<pair<int, int>> adj[], int u, int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

// Print adjacency list representation of graph
void printGraph(vector<pair<int, int>> adj[], int V)
{
    int v, w;
    for (int u = 0; u < V; u++)
    {
        cout << "Node " << u << " makes an edge with"<<endl;
        for (auto it = adj[u].begin(); it != adj[u].end(); it++)
        {
            v = it->first;
            w = it->second;
            cout << "     Node " << v << " with edge weight = " << w <<endl;
        }
        cout << "\n";
    }
}

// Driver code
int main()
{
    int V = 5;
    vector<pair<int, int>> adj[V];
    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 4, 20);
    addEdge(adj, 1, 2, 30);
    addEdge(adj, 1, 3, 40);
    addEdge(adj, 1, 4, 50);
    addEdge(adj, 2, 3, 60);
    addEdge(adj, 3, 4, 70);
    printGraph(adj, V);
    return 0;
}


/* => Output
Node 0 makes an edge with
     Node 1 with edge weight = 10
     Node 4 with edge weight = 20

Node 1 makes an edge with
     Node 0 with edge weight = 10
     Node 2 with edge weight = 30
     Node 3 with edge weight = 40
     Node 4 with edge weight = 50

Node 2 makes an edge with
     Node 1 with edge weight = 30
     Node 3 with edge weight = 60

Node 3 makes an edge with
     Node 1 with edge weight = 40
     Node 2 with edge weight = 60
     Node 4 with edge weight = 70

Node 4 makes an edge with
     Node 0 with edge weight = 20
     Node 1 with edge weight = 50
     Node 3 with edge weight = 70
*/