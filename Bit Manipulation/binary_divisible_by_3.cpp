#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string str = "10011";
    reverse(str.begin(), str.end());

    int rem = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '1')
        {
            rem = (rem * 2 + 1) % 3;
        }
        else
        {
            rem = (rem * 2) % 3;
        }
    }

    if (rem % 3 == 0)
        cout << "divisible by 3\n";
    else
        cout << "not divisible by 3\n";

    // another method
    int even = 0, odd = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '1')
        {
            if ((i + 1) % 2 == 0)
                even++;
            else
                odd++;
        }
    }

    if ((even - odd) % 3 == 0)
        cout << "divisible by 3\n";
    else
        cout << "not divisible by 3\n";
    return 0;
}