#include <iostream>
#include <deque>
using namespace std;

long countSubarrays(int a[], int n, int L, int R)
{
    int cou = 0;
    int i = 0, j = 0;
    int temp = 0;
    while (j < n)
    {
        if (a[j] >= L && a[j] <= R)
        {
            temp = j - i + 1;
        }

        else if (a[j] > R)
        {
            temp = 0;
            i = j + 1;
        }
        cou += temp;
        j++;
    }
    return cou;
}

int main()
{
    int Arr[] = {3, 4, 1};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    int ans = countSubarrays(Arr, n, 2, 4);
    cout << "Answer = " << ans << endl;
}