#include <iostream>
using namespace std;

/*void rec1(int a)
{
    if(a>0)
    {
        cout<<a<<" ";
        rec1 (a-1);
    }
}


void rec2(int b)
{
    if(b>0)
    {
        rec2 (b-1);
        cout<<b<<" ";
    }
}*/

// Factorial of n using recursion
int rec3(int x)
{
    if(x<2)
    return 1;

    return x*rec3(x-1);
}

int main()
{
    int n;
    cout<<"Enter a numbers: ";
    cin>>n;

  //  rec1(n);
    cout<<endl;
  //  rec2(n);

    int res=rec3(n);
    cout<<endl<<"Factorial: "<<res<<endl;
}