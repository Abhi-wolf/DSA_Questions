#include <iostream>
using namespace std;

int Ascending(int arr[],int n)
{
    int res=0;
    bool isSorted=true;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1]) {
                swap(arr[j],arr[j+1]);
                res++;
                isSorted=false;
            }
        }
        if(isSorted) break;
    }

    return res;
}

int Descending(int arr[],int n)
{
    int res=0;
    bool isSorted=true;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]<arr[j+1]) {
                swap(arr[j],arr[j+1]);
                res++;
                isSorted=false;
            }
        }
        if(isSorted) break;
    }

    return res;
}


int main()
{
    int arr1[]={4,5,1,2,3};
    int arr2[]={4,5,1,2,3};
    int n=sizeof(arr1)/sizeof(arr1[0]);
    int ans1=Ascending(arr1,n);
    int ans2=Descending(arr2,n);

    cout<<"ans1= "<<ans1<<endl;
    cout<<"ans2= "<<ans2<<endl;
    return 0;
}