#include <iostream>
using namespace std;
int arr[10][10] = {0};

void add_edge(int arr[][10], int r, int c)
{
    arr[r][c] = 1;
    arr[c][r] = 1;
}

void print(int arr[][10], int v)
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            cout << arr[i][j] << "   ";
        cout << endl;
    }
}

int main()
{
    int v = 6;

    add_edge(arr, 0, 4);
    add_edge(arr, 0, 3);
    add_edge(arr, 1, 2);
    add_edge(arr, 1, 4);
    add_edge(arr, 1, 5);
    add_edge(arr, 2, 3);
    add_edge(arr, 2, 5);
    add_edge(arr, 5, 3);
    add_edge(arr, 5, 4);

    print(arr, v);

    return 0;
}