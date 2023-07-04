#include <iostream>
using namespace std;

//  Question --> Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.

int Largest_sum(int arr[], int n, int k)
{
    if (k == 0)
        return -1;

    int ans = 0, sum = 0;
    int i = 0, j = 0;

    while (j < n)
    {
        sum += arr[j];
        if ((j - i + 1) < k)
            j++;

        else if ((j - i + 1) == k)
        {
            if (sum > ans)
                ans = sum;
            sum -= arr[i];
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {100, 200, 300, 400};
    int size = sizeof(arr) / sizeof(arr[0]);
    int res = Largest_sum(arr, size, 0);
    cout << "largest sum of subarray of size 2 is " << res << endl;
    return 0;
}