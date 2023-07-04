#include <iostream>
#define I 32767
#define V 8
using namespace std;

void PrintMST(int T[][V - 2], int G[V][V])
{
    cout << "Minimum Spanning Tree Edges (w/cost)\n";
    int sum = 0;
    for (int i = 0; i < V - 2; i++)
    {
        int c = G[T[0][i]][T[1][i]];
        cout << "[" << T[0][i] << "]---[" << T[1][i] << "] cost: " << c << endl;
        sum += c;
    }
    cout << endl;
    cout << "Total cost of MST : " << sum << endl;
}

void print(int ans[][V - 2], int G[V][V])
{
    for (int i = 0; i < V - 2; i++)
    {
        cout << ans[0][i] << "  " << ans[1][i] << endl;
    }
}

void PrismMst(int G[V][V], int n)
{
    int i, j, k;
    int u, v;
    int track[V];
    int ans[2][V - 2] = {0};
    int min = I;

    //  find first minimum edge
    for (i = 1; i < V; i++)
    {
        track[i] = I;
        for (int j = 1; j < V; j++)
        {
            if (G[i][j] < min)
            {
                min = G[i][j];
                u = i;
                v = j;
            }
        }
    }

    //  put the min found edge in ans
    ans[0][0] = u;
    ans[1][0] = v;

    //  marks the included vertices in track array 0
    track[u] = track[v] = 0;

    //  update track array to nearest neighbour
    for (i = 1; i < V; i++)
    {
        if (track[i] != 0)
        {
            if (G[i][u] < G[i][v])
                track[i] = u;
            else
                track[i] = v;
        }
    }

    // repeat
    for (i = 1; i < n - 1; i++)
    {
        min = I;
        //  find minimum among remaining edges
        for (j = 1; j < V; j++)
        {
            if (track[j] != 0 && G[j][track[j]] < min)
            {
                k = j;
                min = G[j][track[j]];
            }
        }

        ans[0][i] = k;
        ans[1][i] = track[k];

        track[k] = 0;

        //  update nearest neighbour
        for (j = 1; j < V; j++)
        {
            if (track[j] != 0 && G[j][k] < G[j][track[j]])
            {
                track[j] = k;
            }
        }
    }
    // PrintMST(ans,G);
    print(ans, G);
}

int main()
{
    int cost[V][V]{
        {I, I, I, I, I, I, I, I},
        {I, I, 25, I, I, I, 5, I},
        {I, 25, I, 12, I, I, I, 10},
        {I, I, 12, I, 8, I, I, I},
        {I, I, I, 8, I, 16, I, 14},
        {I, I, I, I, 16, I, 20, 18},
        {I, 5, I, I, I, 20, I, I},
        {I, I, 10, I, 14, 18, I, I},
    };

    int n = sizeof(cost[0]) / sizeof(cost[0][0]) - 1;
    PrismMst(cost, n);
    return 0;
}