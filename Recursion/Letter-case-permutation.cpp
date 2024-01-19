#include <iostream>
#include <vector>
using namespace std;

/*
Given a string s, you can transform every letter individually to be lowercase or uppercase to
create another string.
Return a list of all possible strings we could create. Return the output in any order.

Example 1:
Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]

Example 2:
Input: s = "3z4"
Output: ["3z4","3Z4"]

Constraints:
    1 <= s.length <= 12
    s consists of lowercase English letters, uppercase English letters, and digits.
*/

void solve(string input, string output, vector<string> &ans)
{
    if (input.size() == 0)
    {
        ans.push_back(output);
        return;
    }

    // if its a character than there's two possibility one uppercase and lowercase
    if ((input[0] >= 'A' && input[0] <= 'Z') || (input[0] >= 'a' && input[0] <= 'z'))
    {
        string out1 = output;
        string out2 = output;
        out1.push_back(tolower(input[0]));
        out2.push_back(toupper(input[0]));

        solve(input.substr(1), out1, ans);
        solve(input.substr(1), out2, ans);
    }

    // if its a number than there's only one possibility is to add no matter what
    else
    {
        string out3 = output;
        out3.push_back(input[0]);
        solve(input.substr(1), out3, ans);
    }
}

vector<string> letterCasePermutation(string s)
{
    vector<string> ans;
    string out = "";
    solve(s, out, ans);
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
    string inp = "a1b2";
    vector<string> res = letterCasePermutation(inp);
    Display(res);

    inp = "3z4";
    res = letterCasePermutation(inp);
    Display(res);
    return 0;
}