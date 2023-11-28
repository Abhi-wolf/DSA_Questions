#include <bits/stdc++.h>
using namespace std;

void printPair(pair<int, int> p)
{
    // Gives first element from queue pair
    int f = p.first;

    // Gives second element from queue pair
    int s = p.second;

    cout << "(" << f << ", " << s << ") ";
}

int numberOfEnclaves2(vector<vector<int>> &grid)
{
    int res = 0;
    queue<pair<int, int>> que;
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> vec(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
       for(int j=0;j<m;j++)
       {
        if(i==0 || j==0 || i==n-1 || j==m-1) {
            if(grid[i][j]==1) {
                que.push({i,j});
                vec[i][j]=1;
            }
        }
       }
    }

    int delrow[4] = {-1, 0, +1, 0};
    int delcol[4] = {0, +1, 0, -1};
   
    while (!que.empty())
    {
        pair<int, int> p = que.front();
        que.pop();
        int x = p.first;
        int y = p.second;

        for (int i = 0; i < 4; i++)
        {
            int nrow = x + delrow[i];
            int ncol = y + delcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vec[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
            {
                que.push({nrow, ncol});
                vec[nrow][ncol] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(grid[i][j]==1 && vec[i][j]==0)
                res++;
               
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> vec;
    vec = {{0, 0, 0, 0},
            {1, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}};
    int ans = numberOfEnclaves2(vec);
    cout << "ans" << ans << endl;
    return 0;
}