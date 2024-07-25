#include <iostream>
using namespace std;

int helper(int startRow, int startCol, int endRow, int endCol, int &res)
{
    if (startRow == endRow && startCol == endCol)
    {
        res += 1;
        return 1;
    }

    int down = 0;
    if (startRow < endRow)
        down += helper(startRow + 1, startCol, endRow, endCol, res);

    int right = 0;
    if (startCol < endCol)
        right += helper(startRow, startCol + 1, endRow, endCol, res);

    return down + right;
}

int uniquePaths(int m, int n)
{
    int res = 0;
    helper(0, 0, m, n, res);
    return res;
}

int main()
{
    cout << uniquePaths(3, 2) << endl;
    return 0;
}