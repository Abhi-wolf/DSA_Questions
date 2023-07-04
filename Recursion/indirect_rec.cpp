#include<iostream>
using namespace std;
void funB(int);
void funA(int n)
{
    if(n>0)
    {
        cout<<n<<" ";
        funB(n-1);
    }
}

void funB(int x)
{
    if(x>0)
    {
        cout<<x<<" ";
        funA(x/2);
    }
}

int main()
{
    funA(20);
    cout<<"\n";
    return 0;
}