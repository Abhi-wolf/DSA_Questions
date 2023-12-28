#include <iostream>
#include <vector>

using namespace std;

void cofactor(vector<vector<int>> matrix, vector<vector<int>> &temp, int R, int C, int n)
{
    int i = 0, j = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != R && col != C)
            {
                temp[i][j] = matrix[row][col];
                j++;
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int Determinant(vector<vector<int>> matrix, int n)
{
    if (n == 1)
        return matrix[0][0];

    int ans = 0;
    vector<vector<int>> temp(n, vector<int>(n));
    int sign = 1;

    for (int j = 0; j < n; j++)
    {
        cofactor(matrix, temp, 0, j, n);
        ans += sign * matrix[0][j] * Determinant(temp, n - 1);
        sign *= -1;
    }

    return ans;
}

int main()
{
    int n = 3;
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 10, 9}};
    int ans = 0;
    ans = Determinant(matrix, n);
    cout << "Ans = " << ans << endl;
    
    return 0;
}
