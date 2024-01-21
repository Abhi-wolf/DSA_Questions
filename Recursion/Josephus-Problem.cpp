#include <iostream>
#include <vector>
using namespace std;

/*      Game-of-death-in-a-circle

There are n people standing in a circle (numbered clockwise 1 to n) waiting to be executed. 
The counting begins at point 1 in the circle and proceeds around the circle in a fixed direction (clockwise).
In each step, a certain number of people are skipped and the next person is executed. The elimination 
proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), 
until only the last person remains, who is given freedom.
Given the total number of persons n and a number k which indicates that k-1 persons are skipped and 
kth person is killed in circle. The task is to choose the place in the initial circle so that you are 
the last one remaining and so survive.

Example 1:
Input: n = 2, k = 1
Output: 2
Explanation:
Here, n = 2 and k = 1, then safe position is 2 as the person at 1st position will be killed.

Example 2:
Input: n = 4, k = 2
Output: 1
Explanation:
The safe position is 1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function safePos() which 
takes an Integer n as input and returns the safe position.

Expected Time Complexity: O(n*n)
Expected Auxiliary Space: O(n)
*/

void Solve(int k, int index, vector<int> arr, int &ans)
{
    if (arr.size() == 1)
    {
        ans = arr[0];
        return;
    }

    // find index to be removed (by moduls we can find the circular index)  (6+2)%6=2, (6+3)%5=3, etc
    index = (index + k) % arr.size();

    // remove that index from the vector/array
    arr.erase(arr.begin() + index);

    // call for another round (stating index will the next index)
    Solve(k, index, arr, ans);
}

int safePos(int n, int k)
{
    vector<int> arr(n);
    int ans = 0;

    // store index no in the array
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;

    Solve(k-1, 0, arr, ans);
    return ans;
}

int main()
{
    int res = safePos(50, 3);
    cout << "Result = " << res << endl;
    return 0;
}