#include <iostream>
using namespace std;
/*
    every repetition of insertion sort removes an element from the input data,and inserts it 
    into the correct position in the already sorted array until no input elements remain

    worst case -- O(n^2)
    best case --- O(n)
    average case -- O(n^2)

    worst case space complexity -- O(n^2)total

*/
void insertion(int arr[], int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i;
        int v=arr[i];
        while(arr[j-1]>v&&j>=1)
        {
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=v;
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
    int arr[] = {2, 5, 9, 1, 0, 3, 8, 7, 4, 6};
    //int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    insertion(arr, n);
    printArray(arr, n);
    return 0;
}