#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int leftArray[n1], rightArray[n2];
    for (i = 0; i < n1; i++)
        leftArray[i] = arr[low + i];
    for (j = 0; j < n2; j++)
        rightArray[j] = arr[mid + j + 1];

    i = 0;
    j = 0;
    k = low;

    while (i < n1 && j < n2)
    {
        if (leftArray[i] <= rightArray[j])
            arr[k++] = leftArray[i++];

        else
            arr[k++] = rightArray[j++];
    }

    while (i < n1)
        arr[k++] = leftArray[i++];

    while (j < n2)
        arr[k++] = rightArray[j++];
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
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
    int arr[] = {2, 5, 9, 1, 0, 3, 8, 7, 4, 6, -450, -34};
    // int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    mergeSort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}