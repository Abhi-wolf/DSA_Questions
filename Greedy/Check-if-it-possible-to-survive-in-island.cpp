#include <iostream>
using namespace std;

/* Geekina got stuck on an island. There is only one shop on this island and it is open on all days of the week except for Sunday.
Consider following constraints:

N – The maximum unit of food you can buy each day.
S – Number of days you are required to survive.
M – Unit of food required each day to survive.
Currently, it’s Monday, and she needs to survive for the next S days.
Find the minimum number of days on which you need to buy food from the shop so that she can survive the next S days, or determine
that it isn’t possible to survive.

Example 1:

Input: S = 10, N = 16, M = 2
Output: 2
Explaination: One possible solution is to buy a box on the first day (Monday), it’s sufficient to eat from this box up to
8th day (Monday) inclusive. Now, on the 9th day (Tuesday), you buy another box and use the chocolates in it to survive the 9th and
10th day.

Example 2:
Input: S = 10, N = 20, M = 30
Output: -1
Explaination: She can’t survive even if she buy food because the maximum number
of units she can buy in 1 day is less the required food for 1 day.

Your Task:
You do not need to read input or print anything. Your task is to complete the function minimumDays() which takes S, N, and M as input parameters and returns the minimum number of days Geekina needs to buy food. Otherwise, returns -1 if she cannot survive.

Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N, S ≤ 50
1 ≤ M ≤ 30*/

int minimumDays(int S, int N, int M)
{
    int sundays = S / 7; // no of sundays (store is closed on sundays)

    int buyingDays = S - sundays; // buying days left
    int totalFood = S * M;        // total food required to survive
    int ans = 0;

    if (totalFood % N == 0)
    {
        ans = totalFood / N;
    }
    else
    {
        ans = totalFood / N + 1;
    }

    if (ans <= buyingDays) // no of days we bought should be less than or equal to the total buying days
        return ans;
    else
        return -1;
}

int main()
{
    cout << "S=10,N=20,M=30  == " << minimumDays(10, 20, 30) << endl;
    cout << "S=10,N=16,M=2 == " << minimumDays(10, 16, 2) << endl;
    return 0;
}