#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// first method
//  first step -- pick a vextex
//  second step-- fully explore the picked vertex (visit all its adjacent vertex)
void BFS(int vertex, int A[][8], int n)
{
    queue<int> que;
    int visited[8] = {0};
    cout << vertex << ", "; //  visit vertex
    visited[vertex] = 1;
    que.emplace(vertex); // push the visited verted in queue

    while (!que.empty())
    {
        int u = que.front(); //  vertex u for exploring
        que.pop();
        for (int v = 1; v <= n; v++) //  adjacent vertices of vertex u
        {
            if (A[u][v] == 1 && visited[v] == 0) //  adjacent vertices and not vertex
            {
                cout << v << ", "; //  visit vertex
                visited[v] = 1;
                que.emplace(v);
            }
        }
    }
    cout << endl;
}

int main()
{
    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0}};

    cout << "Vertex: 1 -> ";
    BFS(1, A, 8);

    cout << "Vertex: 4 -> ";
    BFS(4, A, 8);

    return 0;
}