#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*
Given an integer array nums that may contain duplicates, return all possible
subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:
Input: nums = [0]
Output: [[],[0]]

Constraints:
    1 <= nums.length <= 10
    -10 <= nums[i] <= 10
*/

// FIRST METHOD
void Solve(int index, vector<int> arr, vector<int> temp, set<vector<int>> &st)
{
    if (index == arr.size())
    {
        st.insert(temp);
        return;
    }

    temp.push_back(arr[index]);
    Solve(index + 1, arr, temp, st);
    temp.pop_back();
    Solve(index + 1, arr, temp, st);
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> res;
    set<vector<int>> st;
    vector<int> temp;
    Solve(0, nums, temp, st);
    for (auto x : st)
        res.push_back(x);
    return res;
}

// SECOND METHOD (best)
void Solve2(int index, vector<int> arr, vector<int> temp, vector<vector<int>> &res)
{
    res.push_back(temp);

    for (int i = index; i < arr.size(); i++)
    {
        if (i != index && arr[i] == arr[i - 1])
            continue;
        temp.push_back(arr[i]);
        Solve2(i + 1, arr, temp, res);
        temp.pop_back();
    }
}

vector<vector<int>> subsetsWithDup2(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> temp;
    Solve2(0, nums, temp, res);
    return res;
}

void Display(vector<vector<int>> res)
{
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << ", ";

        cout << endl;
    }
    cout << endl;
}

int main()
{
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> res = subsetsWithDup(nums);
    Display(res);

    res.clear();
    res = subsetsWithDup2(nums);
    Display(res);
    return 0;
}