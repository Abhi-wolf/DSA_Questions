#include <iostream>
#include <vector>
using namespace std;
#define ll long long int

//  not feasible to large inputs
ll fact(ll n)
{
    if (n == 0)
        return 1;
    return fact(n - 1) * n;
}

ll combination(ll n, ll r)
{
    if (r == 0)
        return 1;
    if (r == n)
        return 1;

    ll num = fact(n);
    ll deno1 = fact(n - r);
    ll deno2 = fact(r);

    num /= deno1;
    return num / deno2;
}

vector<ll> nthRowOfPascalTriangle(int n)
{
    vector<ll> vec;
    for (int i = 0; i <= n - 1; i++)
    {
        ll num = combination(n - 1, i);
        vec.push_back(num);
    }
    return vec;
}

//  for small and medium inputs

ll fun(int n, int r)
{
    if (n == r || r == 0)
        return 1;

    return fun(n - 1, r - 1) + fun(n - 1, r);
}
vector<ll> nthPascal(int n)
{
    vector<ll> vec;
    n = n - 1;
    // vec.push_back(1);
    for (int i = 0; i <= n; i++)
    {
        vec.push_back(fun(n, i));
    }
    return vec;
}

// for large inputs
vector<vector<ll>> pascalDP(int n)
{
    vector<vector<ll>> dp(n, vector<ll>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == j || j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    return dp;
}

int main()
{
    vector<ll> ans;
    cout << fact(24) << endl;
    cout << combination(24, 1);
    ans = nthPascal(15);
    cout << "\n\n Answer ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "     ";
    }
    cout << "\n\n";

    vector<vector<ll>> ans2 = pascalDP(15);
    for (int i = 0; i < ans2.size(); i++)
    {
        for (int j = 0; j < ans2.size(); j++)
            cout << ans2[i][j] << ", ";

        cout << endl;
    }
    return 0;
}