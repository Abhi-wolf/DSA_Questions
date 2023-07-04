#include<iostream>
using namespace std;

//NESTED RECURSION


int fun(int n)
{
    if(n>100)
    {
        return n-10;
    }

    return fun(fun(n+11));
}

int main()
{
    int x=fun(95);
    cout<<x<<endl;
    return 0;

}