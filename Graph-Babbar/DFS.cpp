#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, list<int>> adjList, vector<int> &component, unordered_map<int, bool> &visited)
{
    // push back current node
    component.push_back(node);

    // mark the node as visited
    visited[node] = true;

    // traverse the neighbour
    for (auto x : adjList[node])
    {
        // if not visited call the dfs
        if (!visited[x])
        {
            dfs(x, adjList, component, visited);
        }
    }
}

void makeAdjList(vector<vector<int>> edges, unordered_map<int, list<int>> &adjList)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // adjacency list
    unordered_map<int, list<int>> adjList;

    // used to track visited nodes
    unordered_map<int, bool> visited;
    vector<vector<int>> ans;

    makeAdjList(edges, adjList);

    // loop and 2D vector are for disconnected graph
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(i, adjList, component, visited);
            ans.push_back(component);
        }
    }
    return ans;
}

// display depth first search of graph
void Display(vector<vector<int>> ans)
{
    if (ans.size() == 0)
    {
        cout << "Array is empty.\n";
        return;
    }

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << ", ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> edges;
    edges.push_back({0, 2});
    edges.push_back({0, 1});
    edges.push_back({1, 2});
    edges.push_back({3, 4});

    vector<vector<int>> ans = depthFirstSearch(5, 4, edges);
    Display(ans);
    return 0;
}