#include <iostream>
#include <vector>
using namespace std;
#define MAX 4

/*
    Given a matrix with n rows and m columns. Your task is to find the kth element which is obtained
    while traversing the matrix spirally. You need to complete the method findK which takes four arguments the
    first argument is the matrix A and the next two arguments will be n and m denoting the size of the matrix A
    and then the forth argument is an integer k. The function will return the kth element obtained while traversing
    the matrix spirally.

Example 1:
Input:
    n = 4, m = 4, k = 10
    A[][] = {{1  2  3  4},
            {5  6  7  8},
            {9  10 11 12},
            {13 14 15 16}}
Output: 13
Explanation:
    The spiral order of matrix will look like 1->2->3->4->8->12->16->15->14->13->9->5->6->7->11->10.
    So the 10th element in this order is 13.
*/

void print(vector<int> vec)
{
    cout << "\nSpiral matrix = ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << "     ";
    }
    cout << "\n\n";
}

int findK(int a[MAX][MAX], int n, int m, int k)
{
    int row = n, col = m;
    int start_row = 0, start_col = 0;
    vector<int> vec;

    /*
        row = ending row index
        col = ending column index
        start_row = starting row index
        start_col = starting column index
    */

    while (start_row < row && start_col < col)
    {
        // print the first row from the remaining rows
        for (int i = start_col; i < col; i++)
        {
            vec.push_back(a[start_row][i]);
        }
        start_row++;

        //  print the last column from the remaining columns
        for (int i = start_row; i < row; i++)
        {
            vec.push_back(a[i][col - 1]);
        }
        col--;

        // print the last row from the remaining rows
        if (start_row < row)
        {
            for (int i = col - 1; i >= start_col; i--)
            {
                vec.push_back(a[row - 1][i]);
            }
            row--;
        }

        // print the first column from the remaining column
        if (start_col < col)
        {
            for (int i = row - 1; i >= start_row; i--)
            {
                vec.push_back(a[i][start_col]);
            }
            start_col++;
        }
    }
    print(vec);
    return vec[k - 1];
}

int main()
{
    int arr[4][4] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};
    int ans = findK(arr, 4, 4, 5);
    cout << "kth value = " << ans << endl;
    return 0;
}
