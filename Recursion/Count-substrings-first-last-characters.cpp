#include <iostream>
#include <unordered_set>
using namespace std;

// prints all substrings (prints duplicates also)
void solve(string str, int start, int end)
{
    if (start > end)
        return;

    cout << str.substr(start, (end - start + 1)) << ", ";

    solve(str, start + 1, end);
    solve(str, start, end - 1);
    solve(str, start + 1, end - 1);
}

/*
We are given a string S, we need to find count of all contiguous substrings starting and ending with same character.

Examples :
Input  : S = "abcab"
Output : 7
There are 15 substrings of "abcab" => a, ab, abc, abca, abcab, b, bc, bca,bcab, c, ca, cab, a, ab, b
Out of the above substrings, there are 7 substrings : a, abca, b, bcab, c, a and b.

Input  : S = "aba"
Output : 4
The substrings are a, b, a and aba
*/
int countSubStrs(string str, int i, int j, int n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;

    int res = countSubStrs(str, i + 1, j, n - 1) + countSubStrs(str, i, j - 1, n - 1) - countSubStrs(str, i + 1, j - 1, n - 2);

    if (str[i] == str[j])
        res++;

    return res;
}

int main()
{
    string str = "aba";
    cout << "\ncount of substrings of " << str << " whose first and last characters are same is " << countSubStrs(str, 0, str.size() - 1, str.size()) << endl;
    str = "abcab";
    cout << "\ncount of substrings of " << str << " whose first and last characters are same is " << countSubStrs(str, 0, str.size() - 1, str.size()) << endl;
    return 0;
}