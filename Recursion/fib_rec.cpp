#include <iostream>
using namespace std;

//USING RECURSION
int fib1(int n)
{
    if(n<=1)
     return n;
    
    return fib1(n-2)+fib1(n-1);
}

//USING LOOP
int fib2(int n)
{
    int first=0,sec=1,res=0;

    if(n<=1) return n;

    for(int i=2;i<=n;i++)
    {
        res=first+sec;
        first=sec;
        sec=res;
    
    }

    return res;
}


// USING RECURSION (MEMOIAZIATION)
int arr[10];
int fib3(int n)
{
   if(n<=1) 
       {
           arr[n]=n;
           return n;
       }

   else
   {
       if(arr[n-2]==-1)
        arr[n-2]=fib3(n-2);
       if(arr[n-1]==-1)
        arr[n-1]=fib3(n-1);
       arr[n]=arr[n-2]+arr[n-1];
       return arr[n-2]+arr[n-1]; 
       
   }
}
int main()
{
  for(int i=0;i<10;i++)
    arr[i]=-1;
   cout<<"Fibonaci: "<<fib1(10)<<" "<<fib2(10)<<" "<<fib3(5)<<endl;
   return 0;
}