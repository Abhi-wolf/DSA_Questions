#include <iostream>
using namespace std;
#define mod 1000000007
// USING RECURSION
int power_rec(int n, int m)
{
    if (m == 0)
        return 1;

    return n * power_rec(n, m - 1);
}

// USING LOOP
int power_loop(int x, int y)
{
    int pow = 1;
    if (y == 0)
        return 1;

    else
    {
        for (int i = 1; i <= y; i++)
        {
            pow = pow * x;
        }

        return pow;
    }
}

//  for large inputs
long long power(long long int N, int R)
{
     if(R==0)
        return 1;
        
        if(R%2==0) 
            return power((N*N)%mod,R/2)%mod;
        else
            return N*power((N*N)%mod,(R-1)/2)%mod;
}

int main()
{
    int num1 = 0, num2 = 0;
    cout << "Enter a number and power to it: ";
    cin >> num1 >> num2;

    cout << power_rec(num1, num2) << " " << power_loop(num1, num2) << endl;
    cout<<"pow = "<<power(num1,num2)<<endl;
}