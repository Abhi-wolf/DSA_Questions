#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/*
    Given an array arr[] of integers of size N that might contain duplicates, the task is to find all
    possible unique subsets.
    Note: Each subset should be sorted.

Example 1:
Input: N = 3, arr[] = {2,1,2}
Output:(),(1),(1 2),(1 2 2),(2),(2 2)
Explanation:
All possible subsets = (),(2),(1),(1,2),(2),(2,2),(2,1),(2,1,2)
After Sorting each subset = (),(2),(1),(1,2),(2),(2,2),(1,2),(1,2,2)
Unique Susbsets in Lexicographical order = (),(1),(1,2),(1,2,2),(2),(2,2)

Example 2:
Input: N = 4, arr[] = {1,2,3,3}
Output: (),(1),(1 2),(1 2 3)
(1 2 3 3),(1 3),(1 3 3),(2),(2 3)
(2 3 3),(3),(3 3)

Your Task:Your task is to complete the function AllSubsets() which takes the array arr[] and N as input
        parameters and returns list of all possible unique subsets in lexicographical order.

Expected Time Complexity: O(2N).
Expected Auxiliary Space: O(2N * X), X = Length of each subset.

Constraints:
1 ≤ N ≤ 12
1 ≤ arr[i] ≤ 9
*/

// USING STRING
void subsets1(string input, string output, set<string> &st)
{
    if (input.size() == 0)
    {
        sort(output.begin(), output.end());
        st.insert(output);
        return;
    }

    string out1 = output;
    out1.push_back(input[0]);

    // take
    subsets1(input.substr(1), out1, st);

    // not take
    subsets1(input.substr(1), output, st);
}

vector<vector<int>> UniqueSubsets1(vector<int> arr, int n)
{
    vector<vector<int>> ans;
    set<string> st;
    string input = "";
    string output = "";

    for (int i = 0; i < n; i++)
        input += (arr[i] + '0');

    subsets1(input, output, st);

    for (auto x : st)
    {
        vector<int> v;
        string str = x;
        for (int i = 0; i < str.size(); i++)
            v.push_back(str[i] - '0');

        ans.push_back(v);
    }

    return ans;
}

// USING VECTOR OF INT
void subsets2(vector<int> input, vector<int> output, int index, int size, set<vector<int>> &st)
{
    if (index == size)
    {
        sort(output.begin(), output.end());
        st.insert(output);
        return;
    }

    vector<int> out1 = output;
    out1.push_back(input[index]);

    // take
    subsets2(input, out1, index + 1, size, st);

    // not take
    subsets2(input, output, index + 1, size, st);
}

vector<vector<int>> UniqueSubsets2(vector<int> arr, int n)
{
    vector<vector<int>> ans;
    set<vector<int>> st;

    vector<int> out;
    subsets2(arr, out, 0, n, st);

    for (auto y : st)
        ans.push_back(y);

    return ans;
}

void DisplaySubsets(vector<vector<int>> res)
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
    vector<int> vec = {1, 2, 3, 3};
    int n = vec.size();
    vector<vector<int>> res = UniqueSubsets1(vec, n);
    cout << "\nResult1";
    DisplaySubsets(res);

    res.clear();
    res = UniqueSubsets2(vec, n);
    cout << "\nResult2";
    DisplaySubsets(res);
    return 0;
}