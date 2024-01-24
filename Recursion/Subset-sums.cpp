#include <iostream>
#include <vector>
using namespace std;

/*
Given a list arr of N integers, return sums of all subsets in it.

Example 1:
Input:N = 2 , arr[] = {2, 3}
Output: 0 2 3 5
Explanation:
When no elements is taken then Sum = 0.
When only 2 is taken then Sum = 2.
When only 3 is taken then Sum = 3.
When element 2 and 3 are taken then
Sum = 2+3 = 5.

Example 2:
Input:N = 3, arr = {5, 2, 1}
Output: 0 1 2 3 5 6 7 8
Your Task:
You don't need to read input or print anything. Your task is to complete the function subsetSums() which takes a list/vector and an integer N as an input parameter and return the list/vector of all the subset sums.

Expected Time Complexity: O(2N)
Expected Auxiliary Space: O(2N)

Constraints:
1 <= N <= 15
0 <= arr[i] <= 104
*/

void Solve(int index, int sum, int N, vector<int> arr, vector<int> &ans)
{
    if (index == N)
    {
        ans.push_back(sum);
        return;
    }

    // taken
    Solve(index + 1, sum + arr[index], N, arr, ans);

    // not taken
    Solve(index + 1, sum, N, arr, ans);
}

vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int> res;
    int sum = 0;
    Solve(0, sum, N, arr, res);
    return res;
}

void Display(vector<int> res)
{
    cout << "\n";
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << ", ";
    cout << "\n";
}
int main()
{
    vector<int> arr = {5, 2, 1};
    int n = arr.size();

    vector<int> res = subsetSums(arr, n);
    Display(res);
    return 0;
}
