#include <iostream>
#include <vector>
using namespace std;

/*
Given a string you need to print all possible strings that can be made by placing spaces (zero or one)
in between them. The output should be printed in sorted increasing order of strings

Example 1:
Input: S = "ABC"
Output: (A B C)(A BC)(AB C)(ABC)
Explanation:
ABC
AB C
A BC
A B C
These are the possible combination of "ABC".

Example 2:
Input: S = "AB"
Output: (A B)(AB)

Your Task:  You don't need to read input or print anything. Your task is to complete the function
permutation() which takes the string S as input parameters and returns the sorted array of the string
denoting the different permutation (DON'T ADD '(' and ')' it will be handled by the driver code only).

Expected Time Complexity: O(2^n)
Expected Auxiliary Space: O(1)

CONSTRAINTS:
1 <= |S| < 10
S only contains lowercase and Uppercase English letters.
*/

void Permutation1(string input, string output, vector<string> &ans)
{
    if (input.size() == 0)
    {
        if (output[output.size() - 1] != '0')
            ans.push_back(output);
        return;
    }

    output.push_back(input[0]);
    string out1 = output;
    out1.push_back('0');

    // take 0
    Permutation1(input.substr(1), out1, ans);

    // not take 0
    Permutation1(input.substr(1), output, ans);
}

void Permutation2(string input, string output, vector<string> &ans)
{
    if (input.size() == 1)
    {
        output.push_back(input[0]);
        ans.push_back(output);
        return;
    }

    output.push_back(input[0]);
    string out1 = output;
    out1.push_back('0');

    // take 0
    Permutation2(input.substr(1), out1, ans);

    // not take 0
    Permutation2(input.substr(1), output, ans);
}

int main()
{
    vector<string> ans;
    string str = "ABC";
    string output = "";

    Permutation1(str, output, ans);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ",  ";

    return 0;
}