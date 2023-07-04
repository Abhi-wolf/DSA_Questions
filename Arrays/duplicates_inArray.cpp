#include <iostream>
#include <algorithm>
using namespace std;

//      duplicate elements
void duplicate_elements(int A[],int x)
{
    int last_duplicate = 0,count=0;
    cout<<"Duplicate elements are : ";
    for(int j=0;j<x;j++){

        if(A[j]==A[j+1] && A[j]!=last_duplicate)
        {
            cout<<A[j]<<" ";
            count++;
            last_duplicate=A[j];
        }
    }

    cout<<"\n";
    cout<<"Total no of duplicate elements are "<<count<<endl;
}


void count_of_each_dupliactes(int a[],int c)
{
    int j;
    for(int i=0;i<c-1;i++)
    {
        
        if(a[i]==a[i+1])
        {
            j=i+1;
            while(a[i]==a[j] && j<c) j++;  
            cout<<a[i]<<" is repeated "<<(j-i)<<" times\n";
            i=j-1; 
        }        
    }
}



int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    int arr[n];

    cout<<"Elements of array\n";
    for(int j=0;j<n;j++)
    {
        cin>>arr[j];
    }

    sort(arr,arr+n);

    duplicate_elements(arr,n);
    cout<<"\n";
    count_of_each_dupliactes(arr,n);
    return 0;
}