#include <iostream>
#include <vector>
using namespace std;

class graph
{
public:
    int vertices;
    vector<vector<int>> adjMatrix;

    graph(int x)
    {
        this->vertices = x;
        this->adjMatrix.resize(x, vector<int>(x, 0));
    }

    void addEdge(int u, int v, bool direction = 0)
    {
        // direction = 0 --> undirected graph
        // direction = 1 --> directed graph

        adjMatrix[u][v] = 1;
        if (direction == 0)
            adjMatrix[v][u] = 1;
    }

    void printAdjMatrix()
    {
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
                cout << adjMatrix[i][j] << ", ";
            cout << endl;
        }
    }
};

int main()
{
    graph g(6);

    g.addEdge(0, 4);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(1, 5);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(5, 3);
    g.addEdge(5, 4);

    g.printAdjMatrix();
    return 0;
}