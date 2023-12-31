#include <iostream>
#include <vector>
using namespace std;

/*
    The Boyer-Moore voting algorithm is one of the popular optimal algorithms which is used to find the
    majority element among the given elements that have more than N/ 2 occurrences. This works perfectly
    fine for finding the majority element which takes 2 traversals over the given elements, which works
    in O(N) time complexity and O(1) space complexity.


    Steps to implement the algorithm :

    Step 1 – Find a candidate with the majority –
    Initialize a variable say i ,votes = 0, candidate =-1
    Traverse through the array using for loop
    If votes = 0, choose the candidate = arr[i] , make votes=1.
    else if the current element is the same as the candidate increment votes
    else decrement votes.

    Step 2 – Check if the candidate has more than N/2 votes –
    Initialize a variable count =0 and increment count if it is the same as the candidate.
    If the count is >N/2, return the candidate.
    else return -1.
*/

int majorityElement(vector<int> &nums)
{
    int ans = -1;
    int count = 0, c = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
            ans = nums[i];
        if (nums[i] == ans)
            count++;
        else
            count--;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == ans)
            c++;
    }

    if (c > nums.size() / 2)
        return ans;
    else
        return -1;
}

int main()
{
    cout << "hello\n";
    vector<int> vec = {2, 2, 1, 1, 1, 2};
    cout << "Result = " << majorityElement(vec);
    return 0;
}