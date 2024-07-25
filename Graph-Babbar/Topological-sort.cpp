#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

// TOPOLOGICAL SORT -- only in acyclic graph(no cycle)

void topologicalSortDFS(vector<int> adj[], unordered_map<int, bool> &visited, stack<int> &stk, int node)
{
    visited[node] = true;

    for (int i : adj[node])
    {
        if (!visited[i])
        {
            topologicalSortDFS(adj, visited, stk, i);
        }
    }
    stk.push(node);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    unordered_map<int, bool> visited;
    stack<int> stk;
    vector<int> ans;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            topologicalSortDFS(adj, visited, stk, i);
        }
    }

    while (!stk.empty())
    {
        ans.push_back(stk.top());
        stk.pop();
    }
    return ans;
}

int main()
{
    vector<int> adj[4] = {{}, {0}, {0}, {0}};
    vector<int> ans = topoSort(4, adj);
    for (int i : ans)
        cout << i << ", ";
    return 0;
}