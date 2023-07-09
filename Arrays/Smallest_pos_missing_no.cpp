#include <iostream>
#include <unordered_map>
using namespace std;

//  time -- O(n)  space -- O(n)
int missingNumber_1(int arr[], int n)
{
    unordered_map<int, int> um;
    //  inserted all the elements in hashmap
    for (int i = 0; i < n; i++)
    {
        um[arr[i]]++;
    }

    // now searching for the smallest +ve no that is not present in the map
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (um.find(ans) == um.end())
        {
            return ans;
        }
        else
        {
            ans++;
        }
    }
    return ans;
}

//  time -- O(n)  space -- O(1)
int missingNumber_2(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        //  find actual position of the element
        int pos = arr[i] - 1;
        // if the element is not at its actual position than place the element at its actual position
        if ((arr[i] > 0 && arr[i] <= n) && arr[i] != arr[pos])
        {
            swap(arr[i], arr[pos]);
            i--; // for upcoming swapped element
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != (i + 1))
        {
            return (i + 1);
        }
    }
    return n + 1;
}

int main()
{
    int arr[] = {0, -10, 1, 3, -20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans1 = missingNumber_1(arr, n);
    int ans2 = missingNumber_2(arr, n);
    cout << "\n Answer_1  =  " << ans1;
    cout << "\n Answer_2  =  " << ans2 << endl;
    return 0;
}