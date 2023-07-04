#include <iostream>
using namespace std;

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "   ";
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

void merge(int arr[], int low, int mid, int high)
{
    int n1, n2;
    int i, j, k;
    n1 = mid - low + 1;
    n2 = high - mid;

    int larray[n1], rarray[n2];
    for (i = 0; i < n1; i++)
        larray[i] = arr[low + i];

    for (j = 0; j < n2; j++)
        rarray[j] = arr[mid + j + 1];

    i = 0;
    j = 0;
    k = low;

    while (i < n1 && j < n2)
    {
        if (larray[i] <= rarray[j])
            arr[k++] = larray[i++];
        else
            arr[k++] = rarray[j++];
    }

    while (i < n1)
        arr[k++] = larray[i++];

    while (j < n2)
        arr[k++] = rarray[j++];
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {2, 8, 3, 4, 1, 9, 3, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);
    cout << endl;
    // quickSort(arr,0,n);
    mergeSort(arr, 0, n);
    print(arr, n);

    return 0;
}