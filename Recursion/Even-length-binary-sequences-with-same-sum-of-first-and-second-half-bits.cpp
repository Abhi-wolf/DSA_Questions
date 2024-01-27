#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// FIRST METHOD  (in every step we have four options to insert in left and right (0,0), (0,1), (1,0), (1,1))
void solve(string left, string right, int k, int n, vector<string> &ans)
{
    if (left.size() == n && right.size() == n)
    {
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < left.size(); i++)
            if (left[i] == '1')
                sum1 += 1;

        for (int i = 0; i < right.size(); i++)
            if (right[i] == '1')
                sum2 += 1;

        if (sum1 == sum2)
        {
            string comb = left + right;
            ans.push_back(comb);
        }
        return;
    }

    if (k == 0)
        return;

    // both left and right 1
    string s1 = left;
    string s2 = right;
    s1.push_back('1');
    s2.push_back('1');
    solve(s1, s2, k - 1, n, ans);

    // both left and right 0
    string s3 = left;
    string s4 = right;
    s3.push_back('0');
    s4.push_back('0');
    solve(s3, s4, k - 1, n, ans);

    // left 0 and right 1
    string s5 = left;
    string s6 = right;
    s5.push_back('0');
    s6.push_back('1');
    solve(s5, s6, k - 1, n, ans);

    // left 1 and right 0
    string s7 = left;
    string s8 = right;
    s7.push_back('1');
    s8.push_back('0');
    solve(s7, s8, k - 1, n, ans);
}

vector<string> EvenLengthSequenceWithEqualSumOfBothHalfs(int n)
{
    vector<string> ans;
    string left = "";
    string right = "";
    solve(left, right, n, n, ans);
    return ans;
}

// SECOND METHOD  (first generated all 0,1 combination of n and then generated different permutations of each combination)

/* The permutation function generates all possible permutations of a given string, which has a time complexity of O(n!).
The combinations function generates all possible combinations of '0' and '1' of a given size, which has a time complexity of O(2^n).
In the main function, we iterate through all combinations of size n and for each combination, we generate all permutations of that
combination. This results in a nested loop structure, where the outer loop has a time complexity of O(2^n) and the inner loop has
a time complexity of O(n!). Therefore, the overall time complexity of the code snippet is O(n! * 2^n)."} */
void permutation(string str, int index, unordered_set<string> &perm)
{
    if (index == str.size())
    {
        perm.insert(str);
        return;
    }

    for (int ind = index; ind < str.size(); ind++)
    {
        swap(str[ind], str[index]);
        permutation(str, ind + 1, perm);
        swap(str[ind], str[index]);
    }
}

void combinations(int size, string curr, vector<string> &comb)
{
    if (size == curr.size())
    {
        comb.push_back(curr);
        return;
    }

    // taken 0
    string s1 = curr;
    s1.push_back('0');
    combinations(size, s1, comb);

    // taken 1
    string s2 = curr;
    s2.push_back('1');
    combinations(size, s2, comb);
}

vector<string> EvenLengthWithEqualSumLeftRight(int n)
{
    vector<string> ans;
    vector<string> allCombinationsOfSizeN;
    string curr = "";
    combinations(n, curr, allCombinationsOfSizeN);
    for (int i = 0; i < allCombinationsOfSizeN.size(); i++)
    {
        unordered_set<string> allPermutation;
        string str = allCombinationsOfSizeN[i];
        permutation(str, 0, allPermutation);

        for (auto x : allPermutation)
        {
            string comb = allCombinationsOfSizeN[i] + x;
            ans.push_back(comb);
        }
    }
    return ans;
}

void Display(vector<string> ans)
{
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ", ";
    cout << endl;
}

int main()
{
    vector<string> ans = EvenLengthSequenceWithEqualSumOfBothHalfs(3);
    cout << "\n\tFirst Method";
    cout << "\nNo of results = " << ans.size() << endl;
    Display(ans);

    ans.clear();

    cout << "\n\tSecond Method";
    ans = EvenLengthWithEqualSumLeftRight(3);
    cout << "\nNo of results = " << ans.size() << endl;
    Display(ans);
    return 0;
}