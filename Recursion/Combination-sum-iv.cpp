#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*Given an array of distinct integers nums and a target integer target, return the number of
possible combinations that add up to target.
The test cases are generated so that the answer can fit in a 32-bit integer.

Example 1:
Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.

Example 2:
Input: nums = [9], target = 3
Output: 0

Constraints:
    1 <= nums.length <= 200
    1 <= nums[i] <= 1000
    All the elements of nums are unique.
    1 <= target <= 1000
*/

// NOT SUITABLE FOR LARGE INPUTS (TLE)
void Solve(int index, int target, vector<int> arr, vector<int> &vec, set<vector<int>> &st)
{
    if (target == 0)
        st.insert(vec);

    if (target < 0)
        return;

    // we can start from any index and can have any repeated numbers(index)
    for (int i = 0; i < arr.size(); i++)
    {
        vec.push_back(arr[i]);
        Solve(i, target - arr[i], arr, vec, st);
        vec.pop_back();
    }
}

int combinationSum4(vector<int> &nums, int target)
{
    set<vector<int>> st;
    vector<int> vec;
    Solve(0, target, nums, vec, st);
    for (auto x : st)
    {
        vector<int> v = x;
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << ", ";
        cout << "\n";
    }
    cout << "\n";
    return st.size();
}

int main()
{
    vector<int> nums = {1, 2, 3};
    int res = combinationSum4(nums, 4);
    cout << "Result 1 = " << res << endl;

    // not suitable (TLE)
    nums = {4, 2, 1};
    res = combinationSum4(nums, 32);
    cout << "Result 1 = " << res << endl;
    return 0;
}