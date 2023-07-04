#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/* Question --> Given an array arr[] of size N and an integer K. Find the maximum for each and every
                    contiguous subarray of size K.

        Example :
        Input:
            N = 9, K = 3
            arr[] = 1 2 3 1 4 5 2 3 6
        Output:
            3 3 4 5 5 5 6
        Explanation:
            1st contiguous subarray = {1 2 3} Max = 3
            2nd contiguous subarray = {2 3 1} Max = 3
            3rd contiguous subarray = {3 1 4} Max = 4
            4th contiguous subarray = {1 4 5} Max = 5
            5th contiguous subarray = {4 5 2} Max = 5
            6th contiguous subarray = {5 2 3} Max = 5
            7th contiguous subarray = {2 3 6} Max = 6
*/

vector<int> Max_subarray(int arr[], int n, int k)
{
    vector<int> ans;
    deque<int> dq;

    int i = 0, j = 0;
    while (j < n)
    {
        //  remove all the previous smaller elements from deque
        while (!dq.empty() && dq.back() < arr[j])
            dq.pop_back();

        dq.push_back(arr[j]);

        //  if window is not reached
        if ((j - i + 1) < k)
            j++;

        //  window reached
        else if ((j - i + 1) == k)
        {
            ans.push_back(dq.front());

            // if the removing element is present in deque then remove it from deque
            if (dq.front() == arr[i])
                dq.pop_front();

            //  slide the window
            i++;
            j++;
        }
    }
   return ans; 
}

int main()
{
    int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};

    int size = sizeof(arr) / sizeof(arr[0]);

    vector<int> vec = Max_subarray(arr, size, 3);

    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << "     ";

    cout << endl;
    return 0;
}