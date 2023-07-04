#include <iostream>
#include <vector>
using namespace std;

int fact(int n)
{
    if (n == 0)
        return 1;
    return fact(n - 1) * n;
}

int nCr(int x, int y)
{
    if (x == y, y == 0)
        return 1;
    else
    {
        int num = fact(x);
        int deno = fact(y) * fact(x - y);
        return num / deno;
    }
}
/* Using Pascals triangle method
                1
            1       1
        1       2       1
    1       3(3C1)  3(3C2)      1
1       4       6       4     1
              (4C2)

*/

int NCR(int x, int y)
{
    if (x == y || y == 0)
        return 1;
    else
        return NCR(x - 1, y - 1) + NCR(x - 1, y);
}

//  using tabulation
/*  Create a 2D vector dp of size (n+1) by (r+1).
    Initialize the base cases, such that for r=0, for all value of n, nCr=1
    Now simply iterate from 0 to n in a nested loop from 1 to min(i,r) to avoid cases where j > i, because in nCr, we know that n >= r.
    Calculate the value of nCr using the previously stored values in the dp table.
    Return the answer. */

int mod = 1e9 + 7;

int calculate_nCr(int n, int r)
{
    if (r > n)
        return 0;

    vector<vector<int>> dp((n + 1), vector<int>(n + 1,0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= r; j++)
        {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
        }
    }

    return dp[n][r] % mod;
}

int main()
{
    cout << nCr(10, 8) << endl;
    cout << NCR(10, 8) << endl;
    cout << calculate_nCr(500, 200) << endl;
    return 0;
}