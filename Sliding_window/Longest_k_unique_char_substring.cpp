#include <iostream>
#include <unordered_map>
using namespace std;

/*
    Given a string you need to print the size of the longest possible substring that has exactly K unique characters.
    If there is no possible substring then print -1.

Example 1:
Input:
    S = "aabacbebebe", K = 3
Output: 7
Explanation: "cbebebe" is the longest substring with K distinct characters.
*/

int longestKSubstr(string s, int k)
{
    // your code here
    unordered_map<char, int> um;
    int i = 0, j = 0, ans = -1;

    while (j < s.size())
    {
        um[s[j]]++;

        if (um.size() < k)
        {
            j++;
        }

        else if (um.size() == k)
        {
            ans = max(ans, j - i + 1);
            j++;
        }

        else if (um.size() > k)
        {
            while (um.size() > k)
            {
                um[s[i]]--;
                if (um[s[i]] == 0)
                    um.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    return ans;
}

int main()
{
    string str = "aabacbebebe";

    cout << "Answer = " << longestKSubstr(str, 3) << endl;
    return 0;
}