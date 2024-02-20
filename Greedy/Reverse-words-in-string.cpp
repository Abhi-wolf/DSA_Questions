#include <bits/stdc++.h>
using namespace std;

/* Given a String S, reverse the string without reversing its individual words. Words are separated by dots.

Example 1:
Input:
S = i.like.this.program.very.much
Output: much.very.program.this.like.i
Explanation: After reversing the whole string(not individual words), the input string becomes
much.very.program.this.like.i

Example 2:
Input:
S = pqr.mno
Output: mno.pqr
Explanation: After reversing the whole string , the input string becomes
mno.pqr

Your Task:
You dont need to read input or print anything. Complete the function reverseWords() which takes string S as input parameter
and returns a string containing the words in reversed order. Each word in the returning string should also be separated by '.'

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(|S|)

Constraints:
1 <= |S| <= 105*/

string reverseWords(string str)
{
    vector<string> vec;
    string reversedStr = "";
    int i = 0;
    while (i < str.size())
    {
        string s = "";
        int j = i;
        while (j < str.size() && str[j] != '.')
        {
            s += str[j];
            j++;
        }

        vec.push_back(s);
        i = j + 1;
    }

    reversedStr = "";
    for (int i = vec.size() - 1; i >= 0; i--)
    {
        reversedStr += vec[i];
        if (i != 0)
            reversedStr += '.';
    }

    return reversedStr;
}

//  2nd METHOD
string reverseWords2(string str)
{
    string ans = "";
    string temp = "";

    for (int i = str.size(); i >= 0; i--)
    {
        if (str[i] == '.')
        {
            reverse(temp.begin(), temp.end());
            ans += temp;
            ans += '.';
            temp = "";
        }

        else
        {
            temp.push_back(str[i]);
        }
    }
    reverse(temp.begin(), temp.end());
    ans += temp;
    return ans;
}

int main()
{
    string str = "i.like.this.program.very.much";
    cout << reverseWords(str) << endl;
    cout << reverseWords2(str) << endl;
    return 0;
}