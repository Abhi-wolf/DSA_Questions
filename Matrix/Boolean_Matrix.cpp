#include <bits/stdc++.h>
using namespace std;

void booleanMatrix(vector<vector<int>> &vec)
{
    set<pair<int, int>> st;
    int n = vec.size();
    int m = vec[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vec[i][j] == 1)
            {
                st.insert({i, j});
            }
        }
    }

    for (auto ptr : st)
    {
        cout << ptr.first << ", " << ptr.second << "\n";
        for (int i = 0; i < m; i++)
        {
            vec[ptr.first][i] = 1;
        }

        for (int j = 0; j < n; j++)
        {
            vec[j][ptr.second] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << vec[i][j] << ", ";
        }
        cout << endl;
    }
}

bool find132pattern(vector<int> &nums)
{
    int i = 0;
    int j = nums.size() - 1;

    while (i < j)
    {
        if (nums[i] < nums[j])
        {
            for (int a = i + 1; a < j ; a++)
            {
                if (nums[a] > nums[i] && nums[a] > nums[j])
                    return true;
            }
        }

        else if (nums[i] > nums[j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> vec;
    vec = {{1, 0, 0},
           {1, 0, 0},
           {0, 0, 0},
           {0, 0, 1}};
    // booleanMatrix(vec);
    vector<int> v = {1,2,3,4};
    bool ans = find132pattern(v);
    cout << "ans = " << ans << endl;
    return 0;
}