#include <iostream>
#include <unordered_map>
using namespace std;

/*
    Given an array of 0s and 1s. Find the length of the largest subarray with equal number of 0s and 1s.

Example 1:
Input:
    N = 4
    A[] = {0,1,0,1}
Output: 4
Explanation: The array from index [0...3] contains equal number of 0's and 1's.
            Thus maximum length of subarray having equal number of 0's and 1's is 4.
*/

int maxLen(int arr[], int N)
{
    int ans = 0;
    unordered_map<int, int> um;

    // here we updated 0 in the array with -1,so, as to solve the problem using the subarray with zero sum
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == 0)
            arr[i] = -1;
    }

    // code for subarray with zero sum
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            ans = i + 1;
        }

        else if (um.find(sum) != um.end())
        {
            ans = max(ans, i - um[sum]);
        }

        else
        {
            um[sum] = i;
        }
    }
    return ans;
}

int main()
{
    int A[] = {0, 0, 1, 0, 0};
    int size = sizeof(A) / sizeof(A[0]);
    int x = maxLen(A, size);
    cout << "Answer = " << x << endl;
    return 0;
}