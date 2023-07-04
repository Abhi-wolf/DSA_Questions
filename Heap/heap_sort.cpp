#include <iostream>
using namespace std;

/*
           Case	          Time Complexity
        Best Case	        O(n log n)
        Average Case	    O(n log n)
        Worst Case	        O(n log n)


        Space Complexity – Constant O(1).

    Algorithm:
    #1   Build the max heap from the given array.
    #2   After this, the largest element is stored at the top of the heap.
    #3   Replace that element with the last element of the heap.
    #4   Heapify the root of the tree.
    #5   Repeat steps 3 and 4 while the size of the heap is greater than 1.

*/

// heapify is performed on the node and on its child
//  it is not performed on grandparents of the node
// The reshaping of a binary tree into a heap tree is called heapify.
void heapify(int arr[], int n, int i)
{
    int largest = i;       // intialize largest as root
    int left = 2 * i + 1;  //  left node of root
    int right = 2 * i + 2; // right node of root

    //  if left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    //  if right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // if root is not the largest then swap
    // and perform heapify of the swapped child
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        //  recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n)
{
    // build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    //  one by one extract an element from heap
    for (int i = n - 1; i >= 0; i--)
    {
        //  move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

//  print function for display
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << "  ";
}

//  driver program
int main()
{
    int array[] = {12, 11, 13, 5, 6, 7, 1, 7, 4, 10, 9, 3, 2};

    cout << "\nBefore heapsort: ";
    print(array, sizeof(array) / sizeof(array[0]));

    heapsort(array, sizeof(array) / sizeof(array[0]));

    cout << "\nAfter heapsort : ";
    print(array, sizeof(array) / sizeof(array[0]));

    return 0;
}