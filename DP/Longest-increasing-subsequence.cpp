#include <iostream>
#include <vector>
using namespace std;

/*
Given an array of integers, find the length of the longest (strictly) increasing subsequence
from the given array.

Example 1:
Input:
N = 16
A = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15}
Output:
6
Explanation:
There are more than one LIS in this array. One such Longest increasing subsequence is {0,2,6,9,13,15}.
Example 2:

Input:
N = 6
A[] = {5,8,3,7,9,1}
Output:
3
Explanation:
There are more than one LIS in this array.  One such Longest increasing subsequence is {5,7,9}.
Your Task:
Complete the function longestSubsequence() which takes the input array and its size as input
parameters and returns the length of the longest increasing subsequence.

Expected Time Complexity : O( N*log(N) )
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 104
0 ≤ A[i] ≤ 106
*/

// TLE
void solve(int arr[], int index, int n, int &ans, vector<int> &temp)
{
    if (index == n)
    {
        int len = temp.size();
        ans = max(ans, len);
        cout << len << ", ";
        return;
    }

    if (temp.empty() || arr[index] > temp.back())
    {
        temp.push_back(arr[index]);
        solve(arr, index + 1, n, ans, temp);
        temp.pop_back();
    }
    solve(arr, index + 1, n, ans, temp);
}

int longestSubsequence(int n, int arr[])
{
    int ans = 0;
    vector<int> temp;
    solve(arr, 0, n, ans, temp);
    return ans;
}

int main()
{
    int arr[] = {0, 8, 4, 12, 2};
    // int arr[] = {5, 8, 3, 7, 9, 1};
    // int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    int res = longestSubsequence(n, arr);
    cout << "n = " << n << endl;
    cout << "\n\nResult = " << res << endl;

    string str = "1200";
    cout << "to int = " << stoi(str);

    return 0;
}