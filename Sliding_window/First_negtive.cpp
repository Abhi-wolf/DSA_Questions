#include <iostream>
#include <vector>
#include <Queue>
using namespace std;

//  Question --> Given an array A[] of size N and a positive integer K, find the first
//          negative integer for each and every window(contiguous subarray) of size K.

vector<long long> First_negative(long long int arr[], long long int n, long long int k)
{
    vector<long long> ans;
    queue<long long> que;

    int i = 0, j = 0;
    while (j < n)
    {
        if (arr[j] < 0)
            que.push(arr[j]);

        if ((j - i + 1) < k)
            j++;

        else if ((j - i + 1) == k)
        {
            if (que.empty())
                ans.push_back(0);

            else
            {
                ans.push_back(que.front());

                if (arr[i] == que.front())
                    que.pop();
            }
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    long long int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    long long int size = sizeof(arr) / sizeof(arr[0]);

    vector<long long> res;
    res = First_negative(arr, size, 3);

    cout << "Result = ";
    for (auto x : res)
        cout << x << "     ";

    return 0;
}