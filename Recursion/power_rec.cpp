#include <iostream>
using namespace std;

// USING RECURSION
int power_rec(int n,int m)
{
   if(m==0)
    return 1;

   return n*power_rec(n,m-1);
}


//USING LOOP
int power_loop(int x,int y)
{
    int pow=1;
    if(y==0)
     return 1;
    
    else
    {
        for(int i=1;i<=y;i++)
        {
           pow=pow*x;
        }

        return pow;
    }
}
int main()
{
    int num1=0,num2=0;
    cout<<"Enter a number and power to it: ";
    cin>>num1>>num2;

    cout<<power_rec(num1,num2)<<" "<<power_loop(num1,num2)<<endl;
}