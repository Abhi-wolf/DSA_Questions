#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
    Given a string S, find the length of the longest substring without repeating characters.

Example 1:
Input:
    S = "geeksforgeeks"
Output: 7
Explanation:
    Longest substring is "eksforg".
*/

int longest_substring(string str)
{
    deque<char> dq;

    int i = 0, j = 0;
    int max = 0;
    while (j < str.size())
    {
        //  search in deque that character if not present than that means that character is not repeated
        //  and insert that character in deque
        if (find(dq.begin(), dq.end(), str[j]) == dq.end())
        {
            dq.push_back(str[j]);
            j++;

            if (j >= str.size())
            {
                if (dq.size() > max)
                    max = dq.size();
            }
        }

        //  found a repeating character
        else
        {
            if (dq.size() > max)
                max = dq.size();

            // remove the repeating character that appeared first time and all the characters before it from deque
            while (dq.front() != str[j])
            {
                dq.pop_front();
            }

            dq.pop_front();
            dq.push_back(str[j]);
            j++;
        }
    }
    return max;
}

int main()
{
    string s = "abdefgabef";
    cout << "Answer = " << longest_substring(s) << endl;
    return 0;
}