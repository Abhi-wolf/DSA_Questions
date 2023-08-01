#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

//  gives time limit excedded exception
int countDistinctSubarray(int arr[], int n)
{
    set<int> st;
    unordered_map<int, int> um;
    int total_dist = 0;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }

    int ans = 0;
    total_dist = st.size();
    // cout << n << "      " << total_dist << endl;

    for (int k = 0; k < n; k++)
    {
        int i = k, j = k;
        um.clear();
        while (j < n)
        {
            um[arr[j]]++;

            if (um.size() < total_dist)
                j++;

            else if (um.size() == total_dist)
            {
                ans++;
                j++;
            }

            else if (um.size() > total_dist)
            {
                while (um.size() > total_dist)
                {
                    um[arr[i]]--;
                    if (um[arr[i]] == 0)
                        um.erase(arr[i]);
                    i++;
                }
                j++;
            }
        }
    }
    return ans;
}

//  without time limit exception
int CountdistinctsubArray(int arr[], int n)
{
    unordered_map<int, int> map;
    set<int> st;
    int total_dist = 0;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }

    int ans = 0;
    total_dist = st.size();

    int i = 0, j = 0;
    while (j < n)
    {
        map[arr[j]]++;
        while (map.size() == total_dist)
        {
            ans += (n - j);
            map[arr[i]]--;
            if (map[arr[i]] == 0)
                map.erase(arr[i]);
            i++;
        }
        j++;
    }
    return ans;
}

int main()
{
    int arr[] = {2, 1, 3, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = countDistinctSubarray(arr, n);
    int ans2 = CountdistinctsubArray(arr, n);
    cout << "\n answer_1 = " << ans << endl;
    cout << "\n answer_2 = " << ans2 << endl;
    return 0;
}