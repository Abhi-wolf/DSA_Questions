#include <iostream>
#include <vector>
using namespace std;

/*
Given an integer, K. Generate all binary strings of size k without consecutive 1’s.

Examples: 
Input : K = 3  
Output : 000 , 001 , 010 , 100 , 101 

Input : K  = 4 
Output :0000 0001 0010 0100 0101 1000 1001 1010
*/

void solve(string str, int k)
{
    if (str.size() == k)
    {
        cout << str << ", ";
        return;
    }

    // if the last element is 1 then we have only one option (we can only insert 0)
    if (str[str.size() - 1] == '1')
        solve(str + '0', k);

    // but if the last element is 0 then we can  insert 0 or 1 (we have two options)
    else
    {
        solve(str + '0', k);
        solve(str + '1', k);
    }
}

void generateAllStrings(int k)
{
    string str = "";
    solve(str, k);
}

int main()
{
    generateAllStrings(4);
    return 0;
}