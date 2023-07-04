
#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph
{
    int v;                 //  no of vertices
    vector<list<int>> adj; //  pointer to an array containing adjacency lists

public:
    Graph(int v);               //  constructor
    void addEdge(int v, int w); //  function to add an edge to graph
    void BFS(int s);
};

Graph::Graph(int v)
{
    this->v = v;
    adj.resize(v);
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); //  add w to v's list
}

void Graph::BFS(int s)
{
    vector<bool> visited; //  mark all vertice as not visited
    visited.resize(v, false);

    // queue<int>que;  // create a queue for bfs
    list<int> que;
    visited[s] = true; // mark the current node as visited and push it in queue
    que.push_back(s);

    while (!que.empty())
    {
        s = que.front(); //  pop out a vextex from front from queue
        que.pop_front();
        cout << s << " ";

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (auto adjecent : adj[s])
        {
            if (!visited[adjecent])
            {
                visited[adjecent] = true;
                que.push_back(adjecent);
            }
        }
    }
    cout<<endl;
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "\nFollowing is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);

    cout << "\nFollowing is Breadth First Traversal "
         << "(starting from vertex 0) \n";
    g.BFS(0);

    cout << "\nFollowing is Breadth First Traversal "
         << "(starting from vertex 1) \n";
    g.BFS(1);

    cout << "\nFollowing is Breadth First Traversal "
         << "(starting from vertex 3) \n";
    g.BFS(3) ;
    return 0;
}