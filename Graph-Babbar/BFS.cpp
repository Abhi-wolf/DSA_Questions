#include <bits/stdc++.h>
using namespace std;

void bfs(unordered_map<int, list<int>> &adjList, vector<int> &ans, unordered_map<int, bool> &visited, int node)
{
    queue<int> que;
    que.push(node);
    visited[node] = true;

    while (!que.empty())
    {
        int frontNode = que.front();
        que.pop();
        ans.push_back(frontNode);

        for (auto x : adjList[frontNode])
        {
            if (!visited[x])
            {
                que.push(x);
                visited[x] = 1;
            }
        }
    }
}

// make adjacency list from the given vector
void makeAdjList(unordered_map<int, list<int>> &adjList, vector<pair<int, int>> edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // adjacency list
    unordered_map<int, list<int>> adjList;

    // ans
    vector<int> ans;

    // used to mark which nodes are visited and which are not
    unordered_map<int, bool> visited(false);

    // prepare adjacency list
    makeAdjList(adjList, edges);

    // for loop is used for disconnected graph
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(adjList, ans, visited, i);
        }
    }
    return ans;
}

// display breadth first search of graph
void Display(vector<int> ans)
{
    if (ans.size() == 0)
    {
        cout << "Array is empty.\n";
        return;
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ", ";
    cout << endl;
}

int main()
{
    vector<pair<int, int>> edges;
    edges.push_back({0, 1});
    edges.push_back({0, 3});
    edges.push_back({1, 2});
    edges.push_back({2, 3});

    vector<int> ans = BFS(4, edges);
    Display(ans);

    return 0;
}