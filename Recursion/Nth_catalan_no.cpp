#include <iostream>
using namespace std;

/*
    catalan no --> 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, ….....
    c0 = 1;
    c1 = 1;
    c2 = (c0*c1) + (c1*c0)
    c3 = (c0*c2) + (c1*c1) + (c2*c0)
    c4 = (c0*c3) + (c1*c2) + (c2*c1) + (c3*c0)

    it can also be find by 
    nth catalan no = (2n)! / ((n+1)! * (n)!)
*/

//  fails in large inputs
unsigned long int catalan_1(int n)
{
    if ((n == 0 || n == 1))
        return 1;

    unsigned long int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += catalan_1(i) * catalan_1(n - i - 1);
    }

    return ans;
}

// using dynammic programming
unsigned long int catalan_2(int n)
{
    unsigned long int dp[n + 1];
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = 0;
        for (int j = 0; j < i; j++)
        {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    return dp[n];
}

int main()
{
    cout << "Catalan 1 = ";
    for (int i = 0; i < 15; i++)
    {
        cout << catalan_1(i) << ",   ";
    }

    cout << "\nCatalan 2 = ";
    for (int i = 0; i < 150; i++)
    {
        cout << catalan_2(i) << ",   ";
    }
    return 0;
}