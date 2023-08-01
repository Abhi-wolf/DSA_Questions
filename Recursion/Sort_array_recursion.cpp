#include <iostream>
#include <vector>
using namespace std;

/*
    Given an array of integers nums, sort the array in ascending order and return it.
    You must solve the problem without using any built-in functions in O(nlog(n)) time complexity
    and with the smallest space complexity possible.
*/

vector<int> insert(vector<int> &v, int num)
{
    if (v.size() == 0 || v[v.size() - 1] <= num)
    {
        v.push_back(num);
        return v;
    }

    int last = v[v.size() - 1];
    v.pop_back();
    insert(v, num);
    v.push_back(last);
    return v;
}

vector<int> sortArray(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return nums;
    }

    int last = nums[nums.size() - 1];
    nums.pop_back();
    vector<int> v = sortArray(nums);
    vector<int> vec = insert(nums, last);
    return vec;
}

int main()
{
    vector<int> arr = {1, 7, 3, 9, 2, 6, 0, -2};
    arr = sortArray(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << "    ";
    return 0;
}