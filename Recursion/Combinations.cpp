#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
You may return the answer in any order.

Example 1:
Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.

Example 2:
Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.

Constraints:
    1 <= n <= 20
    1 <= k <= n
*/

//  FIRST METHOD
void allCombinationOfSizeK(int element, int k, int n, vector<int> vec, vector<vector<int>> &st)
{
    if (vec.size() == k)
    {
        st.push_back(vec);
        return;
    }

    if (element > n)
        return;

    int ele1 = element;
    vector<int> v1 = vec;
    v1.push_back(element);
    allCombinationOfSizeK(ele1 + 1, k, n, v1, st);

    allCombinationOfSizeK(element + 1, k, n, vec, st);
}

//  SECOND METHOD (LESS MEMORY IS USED)
void allCombinationOfSizeK2(int element, int k, int n, vector<int> &vec,
                            vector<vector<int>> &st)
{
    if (vec.size() == k)
    {
        st.push_back(vec);
        return;
    }

    if (element > n)
        return;

    vec.push_back(element);
    allCombinationOfSizeK2(element + 1, k, n, vec, st);
    vec.pop_back(); // backtrack
    allCombinationOfSizeK2(element + 1, k, n, vec, st);
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> res;
    vector<int> vec;
    allCombinationOfSizeK2(1, k, n, vec, res);
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
    vector<vector<int>> res = combine(20, 3);
    DisplayArray(res);
    return 0;
}