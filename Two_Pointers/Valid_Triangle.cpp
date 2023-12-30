#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
Example 1:
Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are:
            2,3,4 (using the first 2)
            2,3,4 (using the second 2)
            2,2,3

Example 2:
Input: nums = [4,2,3,4]
Output: 4
*/



/* three digits to form the sides of a triangle it should satisfy
    a+b > c
    a+c > b
    b+c > a
*/
int triangleNumber(vector<int> &nums)
{
    int n = nums.size();
    if (n < 3)
        return 0;

    int cnt = 0;
    sort(nums.begin(), nums.end());

    for (int i = n - 1; i >= 2; i--)
    {
        int low = 0, high = i - 1;
        while (low < high)
        {
            if (nums[low] + nums[high] > nums[i])
            {
                cnt += (high - low);
                high--;
            }
            else
            {
                low++;
            }
        }
    }
    return cnt;
}


int main()
{
    vector<int>nums={4,2,3,4};
    int ans=triangleNumber(nums);
    cout<<"Answer = "<<ans<<endl;
    return 0;
}