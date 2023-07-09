#include <iostream>
#include <algorithm>
using namespace std;

/*
    Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in
    sorted order without using any extra space. Modify arr1 so that it contains the first N elements
    and modify arr2 so that it contains the last M elements.

Example 1:

Input:
    n = 4, arr1[] = [1 3 5 7]
    m = 5, arr2[] = [0 2 6 8 9]
Output:
    arr1[] = [0 1 2 3]
    arr2[] = [5 6 7 8 9]
Explanation:
    After merging the two non-decreasing arrays, we get, 0 1 2 3 5 6 7 8 9.
*/

int main()
{
    int n, m, i, j;
    int arr1[] = {2, 2, 3, 4};
    int arr2[] = {1, 2, 3, 8, 9};

    n = sizeof(arr1) / sizeof(arr1[0]);
    m = sizeof(arr2) / sizeof(arr2[0]);

    i = n - 1, j = 0;

    while (i >= 0 && j < m)
    {
        if (arr1[i] > arr2[j])
        {
            int temp = arr1[i];
            arr1[i] = arr2[j];
            arr2[j] = temp;

            i--;
        }
        j++;
    }

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);

    for (i = 0; i < n; i++)
        cout << arr1[i] << "    ";

    cout << endl;

    for (i = 0; i < m; i++)
        cout << arr2[i] << "    ";

    return 0;
}