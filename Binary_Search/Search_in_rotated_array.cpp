#include <iostream>
using namespace std;

int search(int arr[], int l, int h, int key)
{
    int low = l;
    int high = h;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
        {
            if (arr[high] <= arr[mid] && arr[high]>=key)
                low = mid + 1;
            else
                high = mid - 1;
        }
        else
        {
            if (arr[low] >= arr[mid] && arr[low]<=key)
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
    return -1;
}



int main()
{
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int key = 3;
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Answer = " << search(arr, 0, 8, key) << endl;
    return 0;
}