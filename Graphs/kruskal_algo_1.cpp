#include <iostream>
#define I 32767
#define V 7 // no of vertices in graph
#define E 9 //  no of edges in graph
using namespace std;

/*
    1.  find minimum edge form vertex which are not included
    2.  check if the vertex is in loop
        (a) if in loop discard that vertex but mark included in track array
        (b) if not in loop include that vertex in ans and mark included in the track array,then perform union
    3.  repeat steps from 1
*/

void printMST(int ans[][V - 1], int A[][E])
{
    cout << "Minimum cost spanning tree edges\n";
    for (int i = 0; i < V - 1; i++)
        cout << "[ " << ans[0][i] << " ]----[ " << ans[1][i] << " ]\n";
    cout << endl;
}

void Union(int u, int v, int s[])
{
    if (s[u] < s[v])
    {
        s[u] += s[v];
        s[v] = u;
    }
    else
    {
        s[v] += s[u];
        s[u] = v;
    }
}

int find(int u, int s[])
{
    int x = u;
    int v = 0;

    while (s[x] > 0)
    {
        x = s[x];
    }

    while (u != x)
    {
        v = s[u];
        s[u] = x;
        u = v;
    }
    return x;
}

void KruskalMCST(int A[3][9])
{
    int ans[2][V - 1];
    int track[E] = {0};
    int set[V + 1] = {-1, -1, -1, -1, -1, -1, -1, -1};

    int i = 0;
    while (i < V - 1)
    {
        int min = I;
        int u, v, k;
        u = v = k = 0;

        //  find a minimum cost edge
        for (int j = 0; j < E; j++)
        {
            if (track[j] == 0 && A[2][j] < min)
            {
                min = A[2][j];
                u = A[0][j];
                v = A[1][j];
                k = j;
            }
        }

        //  check is the selected min cost edge(u,v) forming a cycle or not
        if (find(u, set) != find(v, set))
        {
            ans[0][i] = u;
            ans[1][i] = v;

            //  perform union
            Union(find(u, set), find(v, set), set);
            i++;
        }
        track[k] = 1;
    }
    printMST(ans, A);
}

int main()
{
    int edges[3][9] = {{1, 1, 2, 2, 3, 4, 4, 5, 5},
                       {2, 6, 3, 7, 4, 5, 7, 6, 7},
                       {25, 5, 12, 10, 8, 16, 14, 20, 18}};

    KruskalMCST(edges);

    return 0;
}
