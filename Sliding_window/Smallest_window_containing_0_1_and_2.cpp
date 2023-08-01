#include <iostream>
#include <unordered_map>
using namespace std;

/*
    Given a string S consisting of the characters 0, 1 and 2. Your task is to find the length
    of the smallest substring of string S that contains all the three characters 0, 1 and 2.
    If no such substring exists, then return -1.

Example 1:
Input:
    S = "01212"
Output: 3
Explanation:
    The substring 012 is the smallest substring that contains the characters 0, 1 and 2.
*/

int smallestSubstring(string s)
{
    unordered_map<char, int> um;

    int i = 0, j = 0;
    int win = INT_MAX;
    while (j < s.size())
    {
        um[s[j]]++;

        while (um.size() == 3)
        {
            win = min(win, (j - i + 1));

            um[s[i]]--;

            if (um[s[i]] == 0)
                um.erase(s[i]);

            i++;
        }
        j++;
    }

    if (win > s.size())
        return -1;
    else
        return win;
}

int main()
{
    string str = "1210";
    int ans = smallestSubstring(str);
    cout << "Window = " << ans << endl;
    return 0;
}