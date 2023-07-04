#include <iostream>
using namespace std;

/*double e(int x,int n)
{
    static double p=1,f=1;
    double r;
    if(n==0)
      return 1;
    else
    {
      r=e(x,n-1);
      p=p*x;
      f=f*n;
      return r+p/f;
    }
} */

//best method
double e(int x,int n)
{
    static double s=1;
    if(n==0)
      return s;
    s=1+s*x/n;
    return e(x,n-1);
}
int main()
{
   cout<<e(3,10)<<endl;
   return 0;
}