#include <iostream>
#include <vector>
using namespace std;

/*
Given a set of characters and a positive integer k, print all possible strings of length k that
can be formed from the given set.

Examples:
Input: set[] = {'a', 'b'}, k = 3
Output:
aaa
aab
aba
abb
baa
bab
bba
bbb


Input: set[] = {'a', 'b', 'c', 'd'}, k = 1
Output:
a
b
c
d
*/

void solve(string str, int k, string &curr, vector<string> &ans)
{
    if (curr.size() == k)
    {
        ans.push_back(curr);
        return;
    }

    for (int i = 0; i < str.size(); i++)
    {
        curr.push_back(str[i]);
        solve(str, k, curr, ans);
        curr.pop_back();
    }
}

vector<string> printAllCombinationsOfLengthK(string str, int k)
{
    vector<string> ans;
    string curr = "";
    solve(str, k, curr, ans);
    return ans;
}

void Display(vector<string> ans)
{
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ", ";
    cout << endl;
}

int main()
{
    string str = "ab";
    str = "abcd";
    vector<string> ans = printAllCombinationsOfLengthK(str, 3);
    cout << "No of Combinations = " << ans.size() << endl;
    Display(ans);
    return 0;
}
