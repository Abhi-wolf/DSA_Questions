#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique
combinations of candidates where the chosen numbers sum to target. You may return the combinations in
any order. The same number may be chosen from candidates an unlimited number of times. Two combinations
are unique if the frequency of at least one of the chosen numbers is different.

Example 1:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Example 2:
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:
Input: candidates = [2], target = 1
Output: []

Constraints:
    1 <= candidates.length <= 30
    2 <= candidates[i] <= 40
    All elements of candidates are distinct.
    1 <= target <= 40
*/

// FIRST METHOD
void Solve(vector<int> candidates, vector<int> ans, int index, int target, vector<vector<int>> &res)
{

    if (target == 0 && index == candidates.size())
        res.push_back(ans);

    if (target < 0 || index >= candidates.size())
        return;

    // taken
    int tar1 = target;
    vector<int> v1 = ans;
    tar1 -= candidates[index];
    v1.push_back(candidates[index]);
    Solve(candidates, v1, index, tar1, res);

    // not taken
    Solve(candidates, ans, index + 1, target, res);
}

//  SECOND METHOD
void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    if (ind == arr.size())
    {
        if (target == 0)
            ans.push_back(ds);
        return;
    }

    if (arr[ind] <= target)
    {
        ds.push_back(arr[ind]);
        findCombination(ind, target - arr[ind], arr, ans, ds);
        ds.pop_back();
    }

    findCombination(ind + 1, target, arr, ans, ds);
}

vector<vector<int>> combinationSum1(vector<int> &candidates, int target)
{
    vector<vector<int>> res;
    vector<int> ans;
    Solve(candidates, ans, 0, target, res);
    // findCombination(0, target, candidates, res, ans);
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
    vector<int> candiadtes = {2, 5, 2, 1, 2};
    candiadtes = {2, 3, 6, 7};
    candiadtes = {2, 3, 5};
    vector<vector<int>> res = combinationSum1(candiadtes, 8);
    DisplayArray(res);
    return 0;
}