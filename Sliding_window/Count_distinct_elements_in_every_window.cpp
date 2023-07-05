#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.

Example 1:
Input:
    N = 7, K = 4
    A[] = {1,2,1,3,4,2,3}
Output: 3 4 4 3
Explanation: Window 1 of size k = 4 is 1 2 1 3. Number of distinct elements in this window are 3.
Window 2 of size k = 4 is 2 1 3 4. Number of distinct elements in this window are 4.
Window 3 of size k = 4 is 1 3 4 2. Number of distinct elements in this window are 4.
Window 4 of size k = 4 is 3 4 2 3. Number of distinct elements in this window are 3.
*/

vector<int> countDistinct(int A[], int n, int k)
{
    unordered_map<int, int> um;

    vector<int> vec;
    int i = 0, j = 0;
    while (j < n)
    {

        um[A[j]]++;

        if ((j - i + 1) < k)
            j++;

        else if ((j - i + 1) == k)
        {
            vec.push_back(um.size());

            if (um[A[i]] == 1)
                um.erase(A[i]);
            else
                um[A[i]]--;
            i++;
            j++;
        }
    }

    return vec;
}

int main()
{
    int arr[] = {4, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> ans = countDistinct(arr, n, 2);
    cout << "Answer = ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "     ";
    }

    cout << endl;
}