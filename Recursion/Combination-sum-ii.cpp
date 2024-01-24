#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in
candidates where the candidate numbers sum to target. Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[[1,1,6],[1,2,5],[1,7],[2,6]]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5
Output:
[[1,2,2],[5]]

Constraints:
    1 <= candidates.length <= 100
    1 <= candidates[i] <= 50
    1 <= target <= 30

*/

//  FIRST METHOD (NOT SUITABLE FOR LARGER INPUTS)  (SET IS USED TO STORE UNIQUE VALUES)
void Solve(int index, int target, vector<int> arr, vector<int> vec, set<vector<int>> &st)
{
    if (target == 0)
        st.insert(vec);

    if (target < 0 || index >= arr.size())
        return;

    // taken
    int tar1 = target;
    vector<int> v1 = vec;
    tar1 -= arr[index];
    v1.push_back(arr[index]);
    Solve(index + 1, tar1, arr, v1, st);

    // not taken
    Solve(index + 1, target, arr, vec, st);
}

vector<vector<int>> combinationSum11(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> vec;
    set<vector<int>> st;
    sort(candidates.begin(), candidates.end());
    Solve(0, target, candidates, vec, st);

    for (auto x : st)
        ans.push_back(x);

    return ans;
}

// SECOND METHOD (BETTER) HERE WE ARE PASSING SORTED ARRAY
void findCombination(int ind, int target, vector<int> arr, vector<vector<int>> &ans, vector<int> &ds)
{
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }

    for (int i = ind; i < arr.size(); i++)
    {
        if (i > ind && arr[i] == arr[i - 1]) // IF(PREVIOUSLY ADDED NO IS SAME THEN SKIP IT)
            continue;

        if (arr[i] > target) // IF CURRENT ELEMENT IS GREATER THAN TARGET THEN ELEMENTS AFTER THIS WOULD
            break;           // ALSO BE GREATER BECAUSE THE ARRAY IS SORTED

        ds.push_back(arr[i]); // TAKE THE NUMBER
        findCombination(i + 1, target - arr[i], arr, ans, ds);
        ds.pop_back(); // BACKTRACK
    }
}

vector<vector<int>> combinationSum12(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(candidates.begin(), candidates.end());
    findCombination(0, target, candidates, ans, ds);
    return ans;
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
    candiadtes = {10, 1, 2, 7, 6, 1, 5};
    candiadtes = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    cout << "\nFirst Method \n";
    vector<vector<int>> res = combinationSum11(candiadtes, 27);
    DisplayArray(res);

    cout << "\n\nSecond Method\n";

    res.clear();
    res = combinationSum12(candiadtes, 27);
    DisplayArray(res);

    return 0;
}