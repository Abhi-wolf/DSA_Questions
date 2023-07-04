#include <iostream>
using namespace std;

// USING RECURSION
int rec_sum(int n)
{
    if(n==0)
     return 0;
    
    return rec_sum(n-1)+n;
}

// USING LOOP
int loop_sum(int x)
{
   int sum=0;
    while(x>0)
    {
        sum+=x;
        x--;
    }
    return sum;
}
int main()
{
    int num=0;
    cout<<"Enter a number: ";
    cin>>num;

    
    cout<<rec_sum(num)<<" "<<loop_sum(num)<<endl;
    return 0;
}