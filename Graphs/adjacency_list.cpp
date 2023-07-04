#include <iostream>
#include <list>
using namespace std;

class graph
{
public:
    list<int> *adjlist; // it points to a array of pointer and then each block contains a list
    int n;
    graph(int v)
    {
        adjlist = new list<int>[v];
        n = v;
    }

    void addedge(int u, int v, bool bi)
    {
        adjlist[u].push_back(v);
        if (bi)             //  if the edge is bidirectional
            adjlist[v].push_back(u);
    }

    void print()
    {
        for(int i=0;i<n;i++)
        {
            cout<<i<<"-->";
            for(auto it:adjlist[i])
                cout<<it<<" ";
            cout<<endl;
        }
    }
};


int main()
{
    graph g(5);
    g.addedge(0,1,true);
    g.addedge(0,3,true);
    g.addedge(1,2,true);
    g.addedge(4,2,true);
    g.addedge(1,3,true);
    g.addedge(4,3,true);
    g.addedge(1,4,true);
    g.addedge(2,3,true);

    g.print();
    return 0;
}