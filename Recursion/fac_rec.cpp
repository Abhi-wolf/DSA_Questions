#include <iostream>
using namespace std;

//USING RECURSION
int fun1(int n)
{
    if(n==0)
     return 1;
    
    return n*fun1(n-1);
}


//USING LOOP
int fun2(int x)
{
    int res=1;
    if(x==0)
     return 1;
    else
    {
        for(int i=1;i<=x;i++)
        {
           res=res*i;
        }

        return res;
    }

}
int main()
{
    int num=0;
    cout<<"Enter a number: ";
    cin>>num;

    cout<<fun1(num)<<" "<<fun2(num)<<endl;
}