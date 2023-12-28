
#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();

    // TC - O(log(m) + log(n))
    int RowSt = 0;
    int RowEn = m - 1;

    while (RowSt <= RowEn)
    {
        int RowMid = RowSt + (RowEn - RowSt) / 2;

        int fir = matrix[RowMid][0];
        int last = matrix[RowMid][n - 1];

        if (target >= fir && target <= last)
        {
            int start = 0;
            int end = n - 1;
            while (start <= end)
            {
                int mid = start + (end - start) / 2;
                if (matrix[RowMid][mid] == target)
                    return true;
                else if (matrix[RowMid][mid] > target)
                    end = mid - 1;
                else if (matrix[RowMid][mid] < target)
                    start = mid + 1;
            }

            if (start >= end)
                return false;
        }

        else if (target < fir)
            RowEn = RowMid - 1;

        else if (target > last)
            RowSt = RowMid + 1;
    }
    return false;
}

bool searchMatrix2(vector<vector<int>> &matrix, int target)
{
    // TC -- O(log(m+n))
    int m = matrix.size();
    int n = matrix[0].size();

    int row = 0;
    int col = n - 1;

    while (row < m && col >= 0)
    {
        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] < target)
            row++;
        else
            col--;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 60}};
    if (searchMatrix2(matrix, 2))
        cout << "Target found\n";
    else
        cout << "target not found\n";
    if (searchMatrix2(matrix, 20))
        cout << "Target found\n";
    else
        cout << "target not found\n";

    return 0;
}