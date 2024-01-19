#include <iostream>
#include <vector>
using namespace std;

/*
Given an integer A pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*A.

Problem Constraints
1 <= A <= 10

Example Input
Input 1: A = 3

Input 2: A = 1

Example Output
Output 1: [ "((()))", "(()())", "(())()", "()(())", "()()()" ]

Output 2: [ "()" ]
*/

void solve(int open, int close, string output, vector<string> &ans)
{
    if (open == 0 && close == 0)
    {
        ans.push_back(output);
        return;
    }

    if (open != 0)
    {
        string out1 = output;
        out1.push_back('(');
        solve(open - 1, close, out1, ans);
    }

    if (close > open)
    {
        string out2 = output;
        out2.push_back(')');
        solve(open, close - 1, out2, ans);
    }
}

vector<string> balancedParanthesis(int n)
{
    vector<string> ans;
    string out = "";
    int open = n;
    int close = n;
    solve(open, close, out, ans);
    return ans;
}

void Display(vector<string> res)
{
    cout << "\n";
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << ", ";
    cout << "\n\n";
}

int main()
{
    int n = 3;
    vector<string> res = balancedParanthesis(n);
    Display(res);
    return 0;
}
