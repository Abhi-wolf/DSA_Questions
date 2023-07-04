#include <iostream>
#define V 8
#define I 32767
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

void PrismMst(int G[V][V], int n)
{
    cout << "print\n";
    int u, v;
    int min = I;

    //  array to track which node is near to which one
    int track[V];

    //  array to store the pairs of answer
    int T[2][V - 2] = {0};

    //  initial -- find min cost edge
    for (int i = 1; i < V; i++)
    {
        track[i] = I;
        for (int j = i; j < V; j++)
        {
            if (G[i][j] < min)
            {
                min = G[i][j];
                u = i;
                v = j;
            }
        }
    }

    //  store u and v in ans array
    T[0][0] = u;
    T[1][0] = v;

    //  mark index u and v visited in track array, so that index not gets repeated
    track[u] = track[v] = 0;

    //  initialize track array to track min cost edge
    //  initialize array with least distanced node
    for (int i = 1; i < V; i++)
    {
        if (track[i] != 0)
        {
            if (G[i][u] < G[i][v])
                track[i] = u;
            else
                track[i] = v;
        }
    }

    //  repeat
    for (int i = 1; i < n - 1; i++)
    {
        int k;
        min = I;
        //  find minimum distanced node form the remaining nodes
        for (int j = 1; j < V; j++)
        {
            if (track[j] != 0 && G[j][track[j]] < min)
            {
                k = j;
                min = G[j][track[j]];
            }
        }

        T[0][i] = k;
        T[1][i] = track[k];
        track[k] = 0;

        //  initialize track array to track min cost edge
        //  initialize array with least distanced node
        for (int j = 1; j < V; j++)
        {
            if (track[j] != 0 && G[j][k] < G[j][track[j]])
                track[j] = k;
        }
    }

    PrintMST(T, G);
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
