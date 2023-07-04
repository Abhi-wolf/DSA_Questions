#include <bits/stdc++.h>
using namespace std;

int distinctAverages(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    unordered_set<float> set;

    int i=0;
        int j=nums.size()-1;
        while(i!=nums.size()/2)
        {
            float avg=(float)(nums[i]+nums[j])/2;
            set.insert(avg);
            cout<<avg<<"  ";
            i++;
            j--;
        }
    return set.size();
}

int main()
{
    vector<int> nums;
    for (int i = 0; i < 10; i++)
    {
        int x;
        cin >>x;
        nums.push_back(x);
    }

    cout << distinctAverages(nums);
    return 0;
}
