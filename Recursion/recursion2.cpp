#include <iostream>
using namespace std;

long long int fac(long long int x)
{
    if(x==0 || x==1)
     return 1;
    else
     return x*fac(x-1);
}

int main()
{
   long long  int n;
    cin>>n;

  //  int factorial=fac(n);
    cout<<"Factorial= "<<fac(n)<<endl;
}