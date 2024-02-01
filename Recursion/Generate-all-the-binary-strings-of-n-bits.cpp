#include <iostream>
using namespace std;

/*
Given a positive integer number N. The task is to generate all the binary strings of N bits. These binary strings should be in ascending order.
Examples:
Input: 2
Output:
0 0
0 1
1 0
1 1

Input: 3
Output:
0 0 0
0 0 1
0 1 0
0 1 1
1 0 0
1 0 1
1 1 0
1 1 1
*/

void generate(int n, string res)
{
    if (n == 0)
    {
        cout << res << ", ";
        return;
    }

    generate(n - 1, res + '0');
    generate(n - 1, res + '1');
}

int main()
{
    generate(4, "");
    return 0;
}