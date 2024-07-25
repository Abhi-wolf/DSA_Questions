#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
/*
Given a Directed acyclic graph(DAG) with n nodes labelled from 0 to n-1. Given edges, start, and destination, count the number of ways
to reach from start to destination. There is a directed Edge from vertex edges[i][0] to the vertex edges[i][1]. Your task is to find
the number of ways to reach from start to destination.

Examples :
Input: edges = [[0,1], [0,3], [0,2], [2, 0], [2,1], [1,3]], n = 4, start = 0, destination = 3
Output: 3
Explanation: There are three ways to reach at 3 from 0. These are : 2->1->3 , 2->0->3 and 2->0->1->3.

Input: edges = [[0,1]], n = 2, start = 0, destination = 1
Output: 1
Explanation: There is only one way to reach at 1 from 0 that is : 0->1.

Expected Time Complexity: O(2n)
Expected Auxilary Complexity: O(n+e)
where e is the number of edges in the graph.

Constraints:
1 <= n <= 15
0 <= start, destination, edges[i][0], edges[i][1] <= n-1
 */
void dfs(unordered_map<int, bool> visited, unordered_map<int, vector<int>> adjList, int start, int destination, string str, unordered_set<string> &ans)
{
    visited[start] = true;
    if (start == destination)
    {
        cout << str << endl;
        ans.insert(str);
        return;
    }

    for (int i : adjList[start])
    {
        if (!visited[i])
        {
            dfs(visited, adjList, i, destination, str + to_string(i), ans);
        }
    }
}

int possible_paths(vector<vector<int>> edges, int n, int start, int destination)
{
    unordered_map<int, bool> visited;
    unordered_set<string> ans;

    unordered_map<int, vector<int>> adjList;

    for (int i = 0; i < edges.size(); i++)
    {
        adjList[edges[i][0]].push_back(edges[i][1]);
    }

    string str = to_string(start);
    dfs(visited, adjList, start, destination, str, ans);

    return ans.size();
}
int main()
{
    vector<vector<int>> edges = {{0, 1}, {0, 3}, {0, 2}, {2, 0}, {2, 1}, {1, 3}};
    cout << "Count = " << possible_paths(edges, 4, 2, 3) << endl;
    return 0;
}
