#include <iostream>
#include <vector>
using namespace std;

/*
Print all permutations of a string keeping the sequence but changing cases.

Examples:
Input : ab
Output : AB Ab ab aB

Input : ABC
Output : abc Abc aBc ABc abC AbC aBC ABC
*/

void PermuteString(string input, string output, vector<string> &ans)
{
    if (input.size() == 0)
    {
        ans.push_back(output);
        return;
    }

    string out1 = output;
    string out2 = output;

    out1 += toupper(input[0]);
    out2 += tolower(input[0]);

    // upper case
    PermuteString(input.substr(1), out1, ans);

    // lower case
    PermuteString(input.substr(1), out2, ans);
}

int main()
{
    string str = "ABC";
    string output = "";
    vector<string> ans;
    PermuteString(str, output, ans);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ", ";

    return 0;
}