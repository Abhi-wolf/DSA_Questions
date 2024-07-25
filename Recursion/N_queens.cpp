#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &board, int row, int col)
{
    // check in row
    for (int j = 0; j < row; j++)
        if (board[j][col] == 1)
            return false;

    // check in diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

void helper(vector<vector<int>> &board, int n, int r, vector<vector<int>> &ans)
{
    if (r == n)
    {
        vector<int> temp;
        cout << "hello word \n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 1)
                    temp.push_back(j + 1);
            }
        }
        ans.push_back(temp);
        return;
    }

    // check for row r
    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, r, i))
        {
            cout << "yes safe \n";

            board[r][i] = 1;
            helper(board, n, r + 1, ans);
            board[r][i] = 0;
        }
    }
}

void Display1DArray(vector<vector<int>> arr)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << ", ";
        }
    }
    cout << endl;
}
void queens(int n)
{
    vector<vector<int>> board(n, vector<int>(0, n));
    vector<vector<int>> ans;
    cout << "hello word \n";

    helper(board, n, 0, ans);
    // return ans;
}

int main()
{
    queens(4);
    return 0;
}