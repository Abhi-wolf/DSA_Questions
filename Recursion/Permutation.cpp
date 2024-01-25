#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]

Constraints:
    1 <= nums.length <= 6
    -10 <= nums[i] <= 10
    All the integers of nums are unique.
*/

// first method
void solve(vector<int> arr, vector<int> &temp, vector<vector<int>> &res, vector<int> &freq)
{
    if (temp.size() == arr.size())
    {
        res.push_back(temp);
        return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (freq[i] == 0)
        {
            freq[i] = 1;
            temp.push_back(arr[i]);
            solve(arr, temp, res, freq);
            freq[i] = 0;
            temp.pop_back();
        }
    }
}

// second method (swap)
void solve2(int index, vector<int> arr, vector<vector<int>> &res)
{
    if (index == arr.size())
    {
        res.push_back(arr);
        return;
    }

    for (int i = index; i < arr.size(); i++)
    {
        swap(arr[index], arr[i]);
        solve2(index + 1, arr, res);
        swap(arr[index], arr[i]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> temp;
    vector<int> freq(nums.size(), 0);

    solve(nums, temp, res, freq);
    // solve2(0, nums, res);
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
    vector<int> nums = {4,4,4};
    vector<vector<int>> res = permute(nums);
    Display(res);
    return 0;
}