#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// CYCLE DETECTION IN DIRECTED GRAPH

bool isCyclicDirectedDFS(vector<int> adj[], int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited)
{
    visited[node] = true;
    dfsVisited[node] = true;

    for (int x : adj[node])
    {
        if (!visited[x])
        {
            if (isCyclicDirectedDFS(adj, x, visited, dfsVisited))
                return true;
        }
        else if (dfsVisited[x])
        {
            return true;
        }
    }

    dfsVisited[node] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    unordered_map<int, bool> visited, dfsVisited;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (isCyclicDirectedDFS(adj, i, visited, dfsVisited))
                return true;
        }
    }
    return false;
}
int main()
{
    vector<int> adj[4] = {{1}, {2}, {3}, {3}}; // cycle
    vector<int> adj2[4] = {{1}, {2}, {3}, {}}; // no cycle
    cout << isCyclic(4, adj) << endl;
    cout << isCyclic(4, adj2) << endl;
    return 0;
}
