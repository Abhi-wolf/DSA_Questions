#include <bits/stdc++.h>
using namespace std;

/* Given a string s and a dictionary of n words dictionary, find out if a s can be segmented into
a space-separated sequence of dictionary words. Return 1 if it is possible to break the s into a
sequence of dictionary words, else return 0.
Note: From the dictionary dictionary each word can be taken any number of times and in any order.

Example 1:
Input:
n = 6
s = "ilike"
dictionary = { "i", "like", "sam", "sung", "samsung", "mobile"}
Output:1
Explanation:
The string can be segmented as "i like".

Example 2:
Input:
n = 6
s = "ilikesamsung"
dictionary = { "i", "like", "sam", "sung", "samsung", "mobile"}
Output:1
Explanation:
The string can be segmented as
"i like samsung" or "i like sam sung".

Your Task:
Complete wordBreak() function which takes a string and list of strings as a parameter and returns 1 if it is possible to break words, else return 0. You don't need to read any input or print any output, it is done by driver code.

Expected Time Complexity: O(len(s)2)
Expected Space Complexity: O(len(s))

Constraints:
1 ≤ n ≤ 12
1 ≤ len(s) ≤ 1100*/

int helper(int ind, string prefix, string s, unordered_set<string> dict)
{
    if (ind == s.size())
        return 0;

    prefix += s[ind];
    if (ind == s.size() - 1)
    {
        return dict.find(prefix) != dict.end();
    }

    int op1 = 0, op2 = 0;
    if (dict.find(prefix) != dict.end())
    {
        op1 = helper(ind + 1, "", s, dict);
    }

    op2 = helper(ind + 1, prefix, s, dict);
    return op1 || op2;
}

int wordBreak(int n, string s, vector<string> &dictionary)
{
    unordered_set<string> dict;

    for (auto x : dictionary)
        dict.insert(x);

    return helper(0, "", s, dict);
}

int main()
{
    vector<string> dictionary = {"i", "like", "sam", "sung", "samsung", "mobile"};
    cout << "Result = " << wordBreak(6, "ilike", dictionary) << endl;
    return 0;
}