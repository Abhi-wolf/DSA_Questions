#include <iostream>
using namespace std;

/* Given an array cost[] of positive integers of size n and an integer w, where cost[i] represents
the cost of an i kg packet of oranges, the task is to find the minimum cost to buy exactly w kg of
oranges. The cost array has a 1-based indexing. If buying exactly w kg of oranges is impossible,
then return -1.
Note:
1. cost[i] = -1 means that i kg packet of orange is unavailable.
2. It may be assumed that there is an infinite supply of all available packet types.

Example 1:
Input:
n = 5
cost[] = {20, 10, 4, 50, 100}
w = 5
Output: 14
Explanation: Purchase the 2kg packet for 10 coins and the 3kg packet for 4 coins to buy 5kg of
oranges for 14 coins.

Example 2:
Input:
n = 5
cost[] = {-1, -1, 4, 3, -1}
w = 5
Output: -1
Explanation: It is not possible to buy 5 kgs of oranges.

Your Task: You don't need to read input or print anything. Complete the function minimumCost()
which takes integers n and w, and integer array cost[] as input parameters and returns the minimum
cost to buy exactly w kg of oranges, If buying exactly w kg of oranges is impossible, then return
-1.

Expected Time Complexity: O(n*w)
Expected Auxiliary Space: O(n*w)

Constraints:
1 ≤ n, w ≤ 2*102
1 ≤ cost[i] ≤ 105
cost[i] ≠ 0*/

// TODO @note TLE
void solve(int arr[], int n, int price, int kg, int &res)
{
    if (kg == 0)
    {
        res = min(res, price);
        return;
    }
    if (kg < 0)
        return;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
            continue;
        solve(arr, n, price + arr[i], kg - (i + 1), res);
    }
}

int minimumCost(int n, int arr[], int w)
{
    int res = INT32_MAX;
    solve(arr, n, 0, w, res);
    return res;
}

int main()
{
    int arr[] = {20, 10, 4, 50, 100};
    int arr2[] = {-1, -1, 4, 3, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int res = minimumCost(n2, arr2, 5);
    cout << "Result = " << res << endl;
    return 0;
}