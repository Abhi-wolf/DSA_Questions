#include <iostream>
using namespace std;

int main()
{
       while(true)
       {
        int n;
        cin>>n;
        if(n==0)
         break;
        int arr1[n],arr2[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr1[i];
        }

        for(int i=0;i<n;i++)
        {
            arr2[arr1[i]-1]=i+1;
        }

        for(int i=0;i<n;i++)
         cout<<arr1[i]<<" ";
         cout<<endl;
        for(int i=0;i<n;i++)
         cout<<arr2[i]<<" ";
         cout<<endl;
       
       int count=0;
        for(int i=0;i<n;i++)
        {
            if(arr1[i]==arr2[i])
             count++;
        }

        if(count==n)
         cout<<"ambiguous \n";
        else
         cout<<"not ambiguous \n";

       }
    
    return 0;
}