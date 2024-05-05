#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

// generic
template <typename T>

class graph
{
public:
    unordered_map<T, list<T>> adjList;

    // adding a edge in adjacency list
    void addEdge(T u, T v, bool direction)
    {
        // direction 0 -- undirected graph
        // direction 1-- directed graph

        adjList[u].push_back(v);
        if (direction == 0)
            adjList[v].push_back(u);
    }

    // printing adjacency list
    void printList()
    {
        for (auto i : adjList)
        {
            cout << i.first << " --> ";
            for (auto y : i.second)
                cout << y << ", ";
            cout << endl;
        }
    }
};

int main()
{
    int virtex, edges;
    cout << "Enter no of vertices : ";
    cin >> virtex;
    cout << "Enter no of edges : ";
    cin >> edges;

    // graph<int> g;
    // for (int i = 0; i < edges; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     g.addEdge(u, v, 0);
    // }
    // g.printList();

    graph<char> g2;
    for (int i = 0; i < edges; i++)
    {
        char u, v;
        cin >> u >> v;
        g2.addEdge(u, v, 0);
    }

    g2.printList();

    return 0;
}