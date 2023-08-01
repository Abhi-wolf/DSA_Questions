#include <iostream>
#include <unordered_map>
using namespace std;

//  not correct -- not complited
int substrCount(string s, int k)
{
    int cou = 0;
    unordered_map<char, int> um;

    int i = 0, j = 0;
    while (j < s.size())
    {
        um[s[j]]++;
        if (um.size() < k)
            j++;

        else if (um.size() == k)
        {
            cou += (j - i + 1);
            j++;
        }

        else if (um.size() > k)
        {
            while (um.size() > k)
            {
                um[s[i]]--;
                if (um[s[i]] == 0)
                    um.erase(s[i]);
                i++;
            }

            cou += (j - i + 1);
            j++;
        }

    }
    return cou;
}

int countSubstringsWithKDistinctChars(string s, int k)
{
    int count = 0;
    int n = s.length();
    unordered_map<char, int> um;
    int distinctCount = 0;
    int i = 0, j = 0;

    while (j < n)
    {
        um[s[j]]++;
        if (um[s[j]] == 1)
            distinctCount++;

        while (distinctCount > k)
        {
            um[s[i]]--;
            if (um[s[i]] == 0)
                distinctCount--;
            i++;
        }

        count += j - i + 1;
        j++;
    }

    return count;
}

int main()
{
    string str = "aba";
    // int ans = substrCount(str, 1);
    // cout << "Answer = " << ans << endl;
    int ans=countSubstringsWithKDistinctChars(str,2);
    cout << "Answer = " << ans << endl;
    return 0;
}