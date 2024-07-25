#include <iostream>
#include <vector>
using namespace std;

/* Time Complexity: O(N*2^N), where n is the size of given array.
    Auxiliary Space:
        O(N) : if we only print our subsets, there will at max N recursion stack
        O(2^N) : if we would store all the subsets we will need 2^N memory blocks to store each subset*/
void solve(vector<int> nums, vector<vector<int>> &res, vector<int> &temp, int ind)
{
    if (ind == nums.size())
    {
        res.push_back(temp);
        return;
    }

    // take the element at index ind
    temp.push_back(nums[ind]);
    solve(nums, res, temp, ind + 1);

    // do not take the element at index ind
    temp.pop_back();
    solve(nums, res, temp, ind + 1);
}

vector<vector<int>> subSets(vector<int> nums)
{
    vector<vector<int>> res;
    vector<int> temp;
    solve(nums, res, temp, 0);
    return res;
}

/* Printing all Subsets Using BIT MANIPULATION

Observation: A bit can be either 0 or 1. What can we deduce from this?

Since, each element has only two choices i.e. either get included or get excluded. Assign these choices to a bit representation such that:
0 means Excluded
1 means Included
i’th bit represents i’th element of the array

Now let’s say, there are N elements in the array. This array will have 2^N subsets. These subsets can be uniquely expressed in form of Bit
representation of number from 0 to (2^N)-1.

Example: If elements in an array of size 2 = {A, B}
All the subsets of this array form the bit representation of number from 0 to (2^2)-1 i.e. 0 to 3
0 = 00 => A excluded, B excluded => { empty }
1 = 01 => A excluded, B included => { B }
2 = 10 => A included, B excluded => { A }
3 = 11 => A included, B included=> { A, B }

Illustration:
Suppose given an array of size 3 = {1, 2, 3}
i = 0 (binary 000): No bits set, subset is {}
i = 1 (binary 001): Only the 0th bit set, subset is {1}
i = 2 (binary 010): Only the 1st bit set, subset is {2}
i = 3 (binary 011): 0th and 1st bits set, subset is {1, 2}
i = 4 (binary 100): Only the 2nd bit set, subset is {3}
i = 5 (binary 101): 0th and 2nd bits set, subset is {1, 3}
i = 6 (binary 110): 1st and 2nd bits set, subset is {2, 3}
i = 7 (binary 111): 0th, 1st, and 2nd bits set, subset is {1, 2, 3}

bit-representation-of-subset
Below are the step-by-step approach:

    Iterate numbers from 0 to (2^n)-1
    Generate binary representation of that number and include the elements of array as per below cases:
        If the i’th bit is 1, then include i’th element of the array into current subset
        If the i’th bit is 0, do nothing and continue.
    Each bit representation of the number will give a unique subset.*/
vector<vector<int>> subSets2(vector<int> nums)
{
    vector<vector<int>> res;
    int n = nums.size();

    for (int i = 0; i < (1 << n); i++)
    {
        vector<int> temp;

        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) != 0)
                temp.push_back(nums[j]);
        }
        res.push_back(temp);
    }

    return res;
}

void Display2DArray(vector<vector<int>> arr)
{
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << ", ";
        }
        cout << endl;
    }
}

int main()
{
    vector<int> nums = {2, 8, 2, 5};
    // vector<vector<int>> res = subSets(nums);
    // Display2DArray(res);
    vector<vector<int>> res2 = subSets2(nums);
    Display2DArray(res2);
    return 0;
}