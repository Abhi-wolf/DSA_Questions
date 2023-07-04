#include <iostream>
using namespace std;
/*
    1.  find the minimum value in th elist
    2.  swap it with the value in the current position
    3.  repeat this process for all the  elements until the entire array is sorted

    worst case -- O(n^2)
    best case --- O(n^2)
    average case -- O(n^2)

    worst case space complexity -- O(1) auxiliary
*/
void selection(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
                min=j;
        }

        if(min!=i)
        {
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
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
     int arr[] = {2, 5, 9, 1, 0, 3, 8, 7, 4, 6};
    //int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    selection(arr, n);
    printArray(arr, n);
    return 0;
}