#include <iostream>
using namespace std;

void countSort(int arr[], int n)
{
    int k = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > k)
            k = arr[i];
    }
    cout<<"k= "<<k<<endl;
    int count[k+1] = {0};
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 1; i <= k; i++)
        count[i] += count[i - 1];

    int output[n];
    for (int i = n - 1; i >= 0; i--)
        output[--count[arr[i]]] = arr[i];

    for(int i=0;i<n;i++)
    {
        arr[i]=output[i];
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
    int arr[] = {2, 5, 9, 1, 0, 3, 8, 7, 4, 6,90};
    // int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    countSort(arr, n);
    printArray(arr, n);
    return 0;
}