#include <iostream>
using namespace std;

/*
    Given a non-negative integer x, return the square root of x rounded down to the nearest integer.
    The returned integer should be non-negative as well.
*/

/*
    Base cases for the given problem are when the given number is 0 or 1, then return X;
    Create some variables, for storing the lower bound say l = 0, and for upper bound r = X / 2 (i.e, The
        floor of the square root of x cannot be more than x/2 when x > 1).
    Run a loop until l <= r, the search space vanishes
    Check if the square of mid or X/mid (mid = (l + r)/2 ) is less than or equal to X, If yes then search for a
        larger value in the second half of the search space, i.e l = mid + 1, update ans = mid
    Else if the square of mid or X/mid is more than X then search for a smaller value in the first half of the
         search space, i.e r = mid – 1
    Finally, Return the ans
*/

//  in case of mid*mid==x (gives error in case of large input) to avoid this mid = x/mid is used

int mySqrt(int x)
{
    if (x == 0 || x == 1)
        return x;

    int low = 1, high = x / 2, ans;

    while (low <= high)
    {
        int mid = (high - low) / 2 + low;

        if (mid == x / mid)
            return mid;

        else if (mid < x / mid)
        {
            low = mid + 1;
            ans = mid;
        }

        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int ans = mySqrt(90);
    cout << "Answer = " << ans << endl;
    return 0;
}