#include <bits/stdc++.h>
using namespace std;

//  CYCLE DETECTION IN CONNECTED AND DISCONNECTED GRAPH
// using BFS
bool isCyclicBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> adjList)
{
    unordered_map<int, int> parent;
    visited[src] = true;
    parent[src] = -1;
    queue<int> que;
    que.push(src);

    while (!que.empty())
    {
        int front = que.front();
        que.pop();

        for (auto neighbour : adjList[front])
        {
            // is the node is visited and its parent is not the front node then there is cycle
            if (visited[neighbour] == true && neighbour != parent[front])
            {
                return true;
            }

            // is node is not visited push the node to queue and mark the node as visited and make the front node as its parent
            else if (!visited[neighbour])
            {
                que.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front;
            }
        }
    }
    return false;
}

// using DFS
bool isCyclicDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> adjList)
{
    // mark the node as visited
    visited[node] = true;

    // call dfs on all its unvisited neighbour
    for (auto neighbour : adjList[node])
    {
        if (!visited[neighbour])
        {
            bool cycleDetected = isCyclicDFS(neighbour, node, visited, adjList);
            if (cycleDetected)
                return true;
        }

        // node is visited and its parent is not equal to neighbour
        else if (neighbour != parent)
        {
            return true;
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    unordered_map<int, list<int>> adjList;

    // make adjacency list
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // used to  track visited nodes
    unordered_map<int, bool> visited;

    // loop is used for disconnected graph
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            // bool ans = isCyclicBFS(i, visited, adjList);
            bool ans = isCyclicDFS(i, -1, visited, adjList);
            if (ans == 1)
                return "Yes";
        }
    }
    return "No";
}

int main()
{
    vector<vector<int>> edges;
    edges.push_back({1, 2});
    edges.push_back({2, 3});
    edges.push_back({3, 4});
    edges.push_back({3, 1});

    cout << "Is cycle present = " << cycleDetection(edges, 4, 3) << endl;
    return 0;
}