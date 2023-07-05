#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

/*
    Given an array containing N integers and an integer K., Your task is to find the length of the longest Sub-Array
        with the sum of the elements equal to the given value K.

Example 1:
Input :
    A[] = {10, 5, 2, 7, 1, 9}
    K = 15
Output : 4
Explanation:
    The sub-array is {5, 2, 7, 1}.
*/

//  this function will not work with negative numbers
int Largest_subarray(int arr[], int n, int k)
{
    int sum = 0, i = 0, j = 0;
    int maxLen = 0;

    while (j < n)
    {
        sum += arr[j];

        if (sum == k)
        {
            if ((j - i + 1) > maxLen)
            {
                maxLen = (j - i + 1);
            }
            j++;
        }

        // adjusting window
        else if (sum < k)
        {
            j++;
        }

        // adjusting window
        else if (sum > k)
        {
            while (sum > k)
            {
                sum -= arr[i];
                i++;
            }

            if (sum == k)
            {
                maxLen = max(maxLen, j - i + 1);
            }
            j++;
        }
    }
    return maxLen;
}

//  for negative as well as positive numbers
int lenOfLongSubarr(int arr[], int N, int k)
{
    // Complete the function
    map<int, int> um;

    int maxLen = 0, sum = 0;

    for (int i = 0; i < N; i++)
    {
        // accumulate sum
        sum += arr[i];

        // when subarray starts from index '0'
        if (sum == k)
            maxLen = i + 1;

        // make an entry for 'sum' if it is
        // not present in 'um'
        if (um.find(sum) == um.end())
            um[sum] = i;

        // check if 'sum-k' is present in 'um'
        // or not
        if (um.find(sum - k) != um.end())
        {

            // update maxLength
            if (maxLen < (i - um[sum - k]))
                maxLen = i - um[sum - k];
        }
    }
    return maxLen;
}

int main()
{
    int arr[6] = {1, 4, 3, 3, 5, 5};

    int ans = Largest_subarray(arr, 6, 16);
    cout << "Answer = " << ans << endl;
    cout << "Ans = " << lenOfLongSubarr(arr, 6, 16) << endl;
    return 0;
}