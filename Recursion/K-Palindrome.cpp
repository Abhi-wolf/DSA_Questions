#include <iostream>
#include <algorithm>
using namespace std;
/* Given a string str of length n, find if the string is K-Palindrome or not. A k-palindrome string transforms into a palindrome
on removing at most k characters from it.

Example 1:
Input: str = "abcdecba"
n = 8, k = 1
Output: 1
Explaination: By removing 'd' or 'e' we can make it a palindrome.

Example 2:
Input: str = "abcdefcba"
n = 9, k = 1
Output: 0
Explaination: By removing a single character we cannot make it a palindrome.

Your Task:
You do not need to read input or print anything. Your task is to complete the function kPalindrome() which takes string str, n,
and k as input parameters and returns 1 if str is a K-palindrome else returns 0.

Expected Time Complexity: O(n*n)
Expected Auxiliary Space: O(n*n)
*/

// function to check palindrome
bool isPalindrome(string str)
{
    int start = 0, end = str.size() - 1;
    while (start < end)
    {
        if (str[start] != str[end])
            return false;
        start++;
        end--;
    }
    return true;
}

void solve(string str, string temp, int ind, int &res, int k, int n)
{
    if (ind == n)
    {
        cout << temp << ", " << temp.size() << " , " << (n - k) << " \n";
        // check if the size of temp is greater than (n-k) or not and whether it is a plaindrome or not
        if ((temp.size() >= (n - k)) && isPalindrome(temp))
        {
            // if palindrome then store the max len in the res varibale
            int len = temp.size();
            cout << "\nlen = " << len << endl;
            res = max(res, len);
        }
        return;
    }

    // take the character at index ind
    solve(str, temp + str[ind], ind + 1, res, k, n);

    // don't take the character at index ind
    solve(str, temp, ind + 1, res, k, n);
}

// TODO time limit excedded
int kPalindrome(string str, int n, int k)
{
    int res = 0;
    solve(str, "", 0, res, k, n);
    if (res > 0)
    {
        return 1;
    }
    return 0;
}

int main()
{
    string str = "abcdecba";
    // str = "abcba";
    // str = "abcdefcba";
    int res = kPalindrome(str, 8, 1);
    cout << "res = " << res << endl;

    return 0;
}