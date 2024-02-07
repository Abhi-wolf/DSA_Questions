#include <iostream>
using namespace std;

// USING RECURSION
int fun1(int n)
{
    if (n == 0)
        return 1;

    return n * fun1(n - 1);
}

// USING LOOP
int fun2(int x)
{
    int res = 1;
    if (x == 0)
        return 1;
    else
    {
        for (int i = 1; i <= x; i++)
        {
            res = res * i;
        }

        return res;
    }
}

// for large number
void Factorial(int num)
{
    int result[200] = {0};
    int digitCount = 1, carry = 0;
    result[0] = 1;

    for (int i = 2; i <= num; i++)
    {
        for (int j = 0; j < digitCount; j++)
        {
            int product = result[j] * i + carry;
            result[j] = product % 10;
            carry = product / 10;
        }

        while (carry)
        {
            result[digitCount] = carry % 10;
            carry = carry / 10;
            digitCount++;
        }
    }

    for (int i = digitCount - 1; i >= 0; i--)
        cout << result[i];
    cout << endl;
}

int main()
{
    int num = 20;

    // cout << fun1(num) << " " << fun2(num) << endl;
    Factorial(num);
    return 0;
}