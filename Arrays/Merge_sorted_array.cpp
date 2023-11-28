#include <iostream>
#include <vector>
using namespace std;

/*
    You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two
    integers m and n, representing the number of elements in nums1 and nums2 respectively.
    Merge nums1 and nums2 into a single array sorted in non-decreasing order.
    The final sorted array should not be returned by the function, but instead be stored inside
    the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements
    denote the elements that should be merged, and the last n elements are set to 0 and should be ignored.
    nums2 has a length of n.
*/

void mergeSorted(vector<int> &arr1, int m, vector<int> &arr2, int n)
{
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (j >= 0)
    {
        // agar arr1 ka last element arr2 ka last element sey baad hai toh arr1 ka us element ko last mey
        //  kar doo aur i ko ek ghata doo
        if (i >= 0 && arr1[i] > arr2[j])
        {
            arr1[k--] = arr1[i--];
        }

        else
        {
            arr1[k--] = arr2[j--];
        }
    }
}

int main()
{
    vector<int> v1 = {-1, 0, 0, 3, 3, 3, 0, 0, 0};
    vector<int> v2 = {1, 2, 3};

    mergeSorted(v1, 6, v2, 3);
    for (auto x : v1)
    {
        cout << x << ", ";
    }
    cout << endl;
}