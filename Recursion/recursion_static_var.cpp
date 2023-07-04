#include <iostream>
using namespace std;
int x=0;          // global variable
int rec(int n)
{
   // static int x=0;        //  static variable
    if(n>0)
    {
        x++;
        return rec(n-1)+x;
    }
    return 0;
}


int main()
{
    system("clear");
    cout<<rec(5)<<endl;

  //  system("clear");
    return 0;
}