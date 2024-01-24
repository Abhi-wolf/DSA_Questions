#include <iostream>
#include <vector>
using namespace std;

/*
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
    Only numbers 1 through 9 are used.
    Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice,
and the combinations may be returned in any order.

Example 1:
Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.

Example 2:
Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.

Example 3:
Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.

Constraints:
    2 <= k <= 9
    1 <= n <= 60
*/

// FIRST METHOD
void Solve(int index, int target, int k, vector<int> arr, vector<int> vec, vector<vector<int>> &res)
{
    if (target == 0 && vec.size() == k)
        res.push_back(vec);

    if (target < 0 || index >= arr.size() || vec.size() >= k)
        return;

    // taken
    int tar1 = target;
    vector<int> v1 = vec;
    tar1 -= arr[index];
    v1.push_back(arr[index]);
    Solve(index + 1, tar1, k, arr, v1, res);

    // not taken
    Solve(index + 1, target, k, arr, vec, res);
}

// SECOND METHOD (BACKTRACKING)  better
void Solve2(int index, int target, int k, vector<int> arr, vector<int> &vec, vector<vector<int>> &res)
{
    if (target == 0 && vec.size() == k)
        res.push_back(vec);

    if (target < 0 || index >= arr.size() || vec.size() >= k)
        return;

    // taken
    if (arr[index] <= target)
    {
        vec.push_back(arr[index]);
        Solve2(index + 1, target - arr[index], k, arr, vec, res);
        vec.pop_back();
    }

    // not taken
    Solve2(index + 1, target, k, arr, vec, res);
}

// WITHOUT USING ARRAY (USING INDEX AS AN ARRAY) -- (BEST)  // doesn't require extra memory for arr to store 1 to 9
void Solve3(int index, int target, int k, vector<int> &vec, vector<vector<int>> &res)
{
    if (target == 0 && vec.size() == k)
        res.push_back(vec);

    if (target < 0 || index > 9 || vec.size() >= k)
        return;

    // taken
    if (index <= target)
    {
        vec.push_back(index);
        Solve3(index + 1, target - index, k, vec, res);
        vec.pop_back();
    }

    // not taken
    Solve3(index + 1, target, k, vec, res);
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> res;
    vector<int> vec;
    vector<int> arr(9);
    for (int i = 0; i < 9; i++)
        arr[i] = i + 1;

    // Solve(0, n, k, arr, vec, res);
    Solve3(1, n, k, vec, res);
    return res;
}

void DisplayArray(vector<vector<int>> res)
{
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << ", ";

        cout << endl;
    }
}

int main()
{
    vector<vector<int>> res = combinationSum3(9, 45);
    if (res.size() > 0)
        DisplayArray(res);
    else
        cout << "Not found\n";
    return 0;
}