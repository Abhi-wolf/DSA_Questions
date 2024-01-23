#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findCombination(int ind, int target, vector<int> arr, vector<vector<int>> &ans, vector<int> &ds)
{
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }

    for (int i = ind; i < arr.size(); i++)
    {
        if (i > ind && arr[i] == arr[i - 1])
            continue;

        if (arr[i] > target)
            break;

        ds.push_back(arr[i]);
        findCombination(i + 1, target - arr[i], arr, ans, ds);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum1(vector<int> &candidates, int target)
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
    vector<vector<int>> res = combinationSum1(candiadtes, 8);
    DisplayArray(res);
    return 0;
}