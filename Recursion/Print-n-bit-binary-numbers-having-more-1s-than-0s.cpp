#include <iostream>
#include <vector>
using namespace std;

/*
Given a positive integer N, the task is to find all the N bit binary numbers having more than or equal 1’s than 0’s
for any prefix of the number.

Prefixes of 10101 are 1010, 101, 10,1

Example 1:
Input:  N = 2
Output: 11 10
Explanation: 11 and 10 have more than or equal 1's than 0's

Example 2:
Input:  N = 3
Output: 111 110 101
Explanation: 111, 110 and 101 have more than or equal 1's than 0's
User Task:
Your task is to complete the function NBitBinary() which takes a single number as input and returns the list of
strings in decreasing order. You need not take any input or print anything.

Input : N=5
Output : 11111, 11110, 11101, 11100, 11011, 11010, 11001, 10111, 10110, 10101
Input : N=4
Output: 1111, 1110, 1101, 1100, 1011, 1010
(1001) is not in answer because its prefix 100 has more zeros than ones

Expected Time Complexity: O(|2N|)
Expected Auxiliary Space: O(2N)

Constraints:
1 <= N <= 20
*/

void solve(int size, int ones, int zeroes, string output, vector<string> &ans)
{
    if (size == 0)
    {
        ans.push_back(output);
        return;
    }

    string out1 = output;
    string out2 = output;

    out1.push_back('1');
    solve(size - 1, ones + 1, zeroes, out1, ans);

    // we can only add zero when the size of ones is greater than zeroes
    if (ones > zeroes)
    {
        out2.push_back('0');
        solve(size - 1, ones, zeroes + 1, out2, ans);
    }
}

vector<string> NBitBinary(int n)
{
    vector<string> vec;
    string output = "";
    int ones = 0;
    int zeroes = 0;

    solve(n, ones, zeroes, output, vec);

    return vec;
}

void Display(vector<string> vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << ", ";
    cout << "\n\n";
}

int main()
{
    vector<string> res = NBitBinary(4);
    Display(res);
    res = NBitBinary(5);
    Display(res);
    res = NBitBinary(3);
    Display(res);
    res = NBitBinary(10);
    Display(res);
    return 0;
}