#include <iostream>
#include <vector>
using namespace std;

vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void helper(int a[], int n, int ind, string res, vector<string> &ans)
{
    if (ind == n)
    {
        ans.push_back(res);
        return;
    }

    for (int i = 0; i < letters[a[ind]].size(); i++)
    {
        helper(a, n, ind + 1, res + letters[a[ind]][i], ans);
    }
}

void Display1DArray(vector<string> arr)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
    cout << endl;
}

vector<string> possibleWords(int a[], int n)
{
    vector<string> ans;
    string res = "";
    helper(a, n, 0, res, ans);

    Display1DArray(ans);
    return ans;
}

int main()
{
    int a[] = {2, 3, 4};
    vector<string> ans = possibleWords(a, 3);
    return 0;
}