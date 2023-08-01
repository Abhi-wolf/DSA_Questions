#include <iostream>
using namespace std;

/*
    Write a program to find the transpose of a square matrix of size N*N. Transpose of a matrix is
    obtained by changing rows to columns and columns to rows.

Example 1:
Input:  N = 4
    mat[][] = {{1, 1, 1, 1},
                {2, 2, 2, 2}
                {3, 3, 3, 3}
                {4, 4, 4, 4}}
Output:
            {{1, 2, 3, 4},
            {1, 2, 3, 4}
            {1, 2, 3, 4}
            {1, 2, 3, 4}}
*/

void transpose(int matrix[4][4], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int x = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = x;
        }
    }
}

void print(int mat[4][4], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << "  ";
        }
        cout << endl;
    }
}

int main()
{
    int mat[4][4] = {{1, 1, 1, 1},
                     {2, 2, 2, 2},
                     {3, 3, 3, 3},
                     {4, 4, 4, 4}};

    print(mat, 4);
    transpose(mat, 4);
    print(mat, 4);
    return 0;
}