#include <iostream>
#include <vector>
using namespace std;

/*
    Given a String S, Find all possible Palindromic partitions of the given String.

    Example 1:
    Input:S = "geeks"
    Output:
    g e e k s
    g ee k s
    Explanation:
    All possible palindromic partitions
    are printed.
    Example 2:

    Input:S = "madam"
    Output:
    m a d a m
    m ada m
    madam

    Your Task:
    You don't need to read input or print anything. Your task is to complete the function allPalindromicPerms() which takes a
    String S as input parameter and returns a list of lists denoting all the possible palindromic partitions in the order of
    their appearance in the original string.

    Expected Time Complexity: O(N*2N)
    Expected Auxiliary Space: O(N2), where N is the length of the String

    Constraints:
    1 <= |S| <= 20
*/

bool isPalindrome(string s)
{
    int start = 0, end = s.size() - 1;
    while (start < end)
    {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

//  FIRST METHOD (this method is used to find strings created after partitions and are palindrome)
void solve(int index, string s, vector<string> &curr, vector<vector<string>> &ans)
{
    if (index == s.size())
    {
        ans.push_back(curr);
        return;
    }

    string t;
    for (int idx = index; idx < s.size(); idx++)
    {
        t.push_back(s[idx]);
        if (isPalindrome(t))
        {
            curr.push_back(t);
            solve(idx + 1, s, curr, ans);
            curr.pop_back();
        }
    }
}

vector<vector<string>> allPalindromicPerms(string s)
{
    vector<vector<string>> ans;
    vector<string> curr;
    solve(0, s, curr, ans);
    return ans;
}

//  SECOND METHOD  (this method is used find all substrings which are palindrome)
vector<string> allPalindromicPerms2(string s)
{
    vector<vector<string>> ans;
    vector<string> curr;

    for (int i = 0; i < s.size(); i++)
    {
        string temp = "";
        for (int j = i; j < s.size(); j++)
        {
            temp.push_back(s[j]);
            if (isPalindrome(temp))
                curr.push_back(temp);
        }
    }

    return curr;
}

void Display(vector<vector<string>> res)
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
    string str = "geeks";
    str = "madam";
    str = "aab";
    vector<vector<string>> res = allPalindromicPerms(str);
    Display(res);

    vector<string> res2 = allPalindromicPerms2(str);
    for (int i = 0; i < res2.size(); i++)
        cout << res2[i] << ", ";

    return 0;
}