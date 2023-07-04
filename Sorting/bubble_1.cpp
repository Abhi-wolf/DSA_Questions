#include <iostream>
using namespace std;

/*
    worst case -- O(n^2)
    best case (improved version) --- O(n)
    average case (basic version) -- O(n^2)

    worst case space complexity -- O(1) auxiliary
*/

void bubble(int arr[], int n)
{
    bool swap_requ = true;
    for (int i = 0; i < n && swap_requ; i++)
    {
        swap_requ = false;
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap_requ = true;
            }
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int main()
{
    // int arr[] = {2, 5, 9, 1, 0, 3, 8, 7, 4, 6};
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    bubble(arr, n);
    printArray(arr, n);
    return 0;
}