#include <iostream>
#include <unordered_map>
using namespace std;

/*
    Given a String S consisting only lowercase alphabets and an integer K. Find the count of all
        substrings of length K which have exactly K-1 distinct characters.

    Input:
        S = "aabab"
        K = 3
    Output :    3
    Explanation:
    Possible substrings of length K = 3 are
        aab : 2 distinct characters
        aba : 2 distinct characters
        bab : 2 distinct characters.
        All of these Substrings are a possible answer, so the count is 3.
*/

int countOfSubstrings(string s, int k)
{
    unordered_map<char, int> um;
    int i = 0, j = 0, cou = 0;

    while (j < s.size())
    {
        um[s[j]]++;

        if ((j - i + 1) < k)
            j++;

        else if ((j - i + 1) == k)
        {
            if (um.size() == k - 1)
                cou++;

            if (um[s[i]] == 1)
                um.erase(s[i]);
            else
                um[s[i]]--;

            i++;
            j++;
        }
    }
    return cou;
}

int main()
{
    string str = "aabab";
    int ans = countOfSubstrings(str, 3);
    cout << "answer = " << ans << endl;
    return 0;
}