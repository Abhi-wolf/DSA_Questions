#include <iostream>
using namespace std;

// REVERSING OF ARRAY USING RECURSION

void Reverse(int arr[], int first, int last)
{
    if (first >= last)
        return;

    swap(arr[first], arr[last]);
    Reverse(arr, first + 1, last - 1);
}

void DisplayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << ", ";

    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    DisplayArray(arr, n);
    Reverse(arr, 0, n - 1);
    DisplayArray(arr, n);
    return 0;
}