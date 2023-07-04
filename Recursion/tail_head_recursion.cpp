#include <iostream>
#include <stdio.h>
using namespace std;

//  TAIL RECURSION
void fun1(int n)
{
    if(n>0)
    {
       printf("%d\n",n);
       fun1(n-1);
    }
}


// HEAD RECURSION
void fun2(int x)
{
    if(x>0)
    {
        fun2(x-1);
        printf("%d \n",x);
    }
}
int main()
{
    cout<<"Tail recursion \n";
    fun1(3);
    cout<<"Head recursion \n";
    fun2(3);
    return 0;
}