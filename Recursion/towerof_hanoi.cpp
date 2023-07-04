#include <iostream>
using namespace std;

void hanoi(int n,int x,int y,int z)
{
    if(n>0)
    {
      hanoi(n-1,x,z,y);
      cout<<"from "<<x<<" to "<<z<<endl;
      hanoi(n-1,y,x,z);
    }
}

int main()
{
    
   hanoi(3,1,2,3);
   return 0;
}