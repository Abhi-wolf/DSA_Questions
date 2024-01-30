#include <iostream>
#include <vector>
using namespace std;

/*
Given two strings, find the length of longest subsequence present in both of them. Both the
strings are in uppercase latin alphabets.

Example 1:
Input:
A = 6, B = 6
str1 = ABCDGH
str2 = AEDFHR
Output: 3
Explanation: LCS for input strings “ABCDGH” and “AEDFHR” is “ADH” of length 3.

Example 2:
Input:
A = 3, B = 2
str1 = ABC
str2 = AC
Output: 2
Explanation: LCS of "ABC" and "AC" is "AC" of length 2.

Your Task: Complete the function lcs() which takes the length of two strings respectively and
two strings as input parameters and returns the length of the longest subsequence present in
both of them.

Expected Time Complexity : O(|str1|*|str2|)
Expected Auxiliary Space: O(|str1|*|str2|)

Constraints:
1<=size(str1),size(str2)<=103
*/

// FIRST METHOD
int LongestSubSequence(string str1, string str2)
{
    int m = str1.size();
    int n = str2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];
}

// SECOND METHOD
int solve(string str1, string str2, int i, int j, vector<vector<int>> &dp)
{
    if (i >= str1.size() || j >= str2.size())
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (str1[i] == str2[j])
        return dp[i][j] = 1 + solve(str1, str2, i + 1, j + 1, dp);

    return dp[i][j] = max(solve(str1, str2, i + 1, j, dp), solve(str1, str2, i, j + 1, dp));
}
int LongestSubSequence2(string str1, string str2)
{
    int m = str1.size();
    int n = str2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return solve(str1, str2, 0, 0, dp);
}

int main()
{
    string str1 = "tsututssuususut";
    string str2 = "ttuusuuttss";
    string str3 = "sutsuutttususuttt";

    cout << "\n Method first\n";
    int ans = LongestSubSequence(str1, str2);
    cout << "Length of longest common subsequence = " << ans << endl;
    ans = LongestSubSequence(str1, str3);
    cout << "Length of longest common subsequence = " << ans << endl;
    ans = LongestSubSequence(str3, str2);
    cout << "Length of longest common subsequence = " << ans << endl;

    cout << "\n Method second\n";
    int ans1 = LongestSubSequence2(str1, str2);
    cout << "Length of longest common subsequence = " << ans1 << endl;
    ans1 = LongestSubSequence2(str1, str3);
    cout << "Length of longest common subsequence = " << ans1 << endl;
    ans1 = LongestSubSequence2(str3, str2);
    cout << "Length of longest common subsequence = " << ans1 << endl;
    return 0;
}