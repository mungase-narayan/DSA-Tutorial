// Adjacency Matrix representation in C++

#include <iostream>
using namespace std;

class Graph
{
private:
    bool **adjMatrix;
    int numVertices;

public:
    // Initialize the matrix to zero
    Graph(int numVertices)
    {
        this->numVertices = numVertices;
        adjMatrix = new bool *[numVertices];
        for (int i = 0; i < numVertices; i++)
        {
            adjMatrix[i] = new bool[numVertices];
            for (int j = 0; j < numVertices; j++)
                adjMatrix[i][j] = false;
        }
    }

    // Add edges
    void addEdge(int i, int j)
    {
        adjMatrix[i][j] = true;
        adjMatrix[j][i] = true;
    }

    // Remove edges
    void removeEdge(int i, int j)
    {
        adjMatrix[i][j] = false;
        adjMatrix[j][i] = false;
    }

    // Print the martix
    void toPrint()
    {
        cout << "Printing the adjMatrix" << endl;
        cout<<"    0 1 2 3 4 5"<<endl;
        cout<<"    | | | | | |"<<endl;
        for (int i = 0; i < numVertices; i++)
        {
            cout << i << " - ";
            for (int j = 0; j < numVertices; j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }

    ~Graph()
    {
        for (int i = 0; i < numVertices; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
};

int main()
{
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(5, 4);

    g.toPrint();
}

/*
Output =>
Printing the adjMatrix
    0 1 2 3 4 5
    | | | | | |
0 - 0 1 1 0 0 0 
1 - 1 0 1 0 0 0 
2 - 1 1 0 1 0 0 
3 - 0 0 1 0 1 0 
4 - 0 0 0 1 0 1 
5 - 0 0 0 0 1 0

*/