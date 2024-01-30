#include <iostream>
#include <vector>
using namespace std;

/*
Given 3 strings A, B and C, the task is to find the length of the longest sub-sequence that
is common in all the three given strings.

Example 1:
Input:
A = "geeks"
B = "geeksfor",
C = "geeksforgeeks"
Output: 5
Explanation: "geeks"is the longest common subsequence with length 5.

Example 2:
Input:
A = "abcd"
B = "efgh"
C = "ijkl"
Output: 0
Explanation: There's no subsequence common in all the three strings.
Your Task:
You don't need to read input or print anything. Your task is to complete the function LCSof3()
which takes the strings A, B, C and their lengths n1, n2, n3 as input and returns the length of
the longest common subsequence in all the 3 strings.

Expected Time Complexity: O(n1*n2*n3).
Expected Auxiliary Space: O(n1*n2*n3).

Constraints:
1 <= n1, n2, n3 <= 20
Elements of the strings constitutes only of the lower case english alphabets.
*/



int solve2(string str1, string str2, string str3, int i, int j, int k, vector<vector<vector<int>>> &dp)
{
    if (str1.size() <= i || str2.size() <= j || str3.size() <= k)
        return 0;

    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    if (str1[i] == str2[j] && str1[i] == str3[k])
        return dp[i][j][k] = 1 + solve2(str1, str2, str3, i + 1, j + 1, k + 1, dp);

    return dp[i][j][k] = max(solve2(str1, str2, str3, i + 1, j, k, dp), max(solve2(str1, str2, str3, i, j + 1, k, dp), solve2(str1, str2, str3, i, j, k + 1, dp)));
}

int LongestSubSequence(string str1, string str2, string str3, int n1, int n2, int n3)
{
    vector<vector<vector<int>>> dp(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(n3 + 1, -1)));
    return solve2(str1, str2, str3, 0, 0, 0, dp);
}

int main()
{
    string str1 = "tsututssuususut";
    string str2 = "ttuusuuttss";
    string str3 = "sutsuutttususuttt";

    int ans = LongestSubSequence(str1, str2, str3, str1.size(), str2.size(), str3.size());
    cout << "Length of longest common subsequence = " << ans << endl;
    return 0;
}