#include <iostream>
#include <unordered_map>
using namespace std;

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