#include <iostream>
#define MAX 100
using namespace std;

void heapify(int arr[], int n, int i)
{
    // Find parent
    int parent = (i - 1) / 2;

    if (arr[parent] > 0)
    {
        // For Max-Heap
        // If current node is greater than its parent
        // Swap both of them and call heapify again
        // for the parent

        if (arr[i] > arr[parent])
        {
            swap(arr[i], arr[parent]);

            // Recursively heapify the parent node
            heapify(arr, n, parent);
        }
    }
}

void InsertNode(int arr[], int &n, int key)
{
    // Increase the size of Heap by 1
    n = n + 1;

    // Insert the element at end of Heap
    arr[n - 1] = key;

    // Heapify the new node following a
    // Bottom-up approach
    heapify(arr, n, n - 1);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << "   ";
    cout << endl;
}

int main()
{
    int arr[MAX] = {10};

    int n = 1;

    InsertNode(arr, n, 20);
    InsertNode(arr, n, 30);
    InsertNode(arr, n, 25);
    InsertNode(arr, n, 5);

    printArray(arr, n);
    return 0;
}