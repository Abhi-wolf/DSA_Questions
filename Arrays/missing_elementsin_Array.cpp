#include <iostream>
#include <stdio.h>
using namespace std;

//  if numbers are sorted and like (starts from 1) 1,2,3,4,5,.........
// single missing element
int missing_element1(int a[],int x)
{
    int sum1 = (x+1)*(x+2)/2;
    int sum2=0;
    for(int i=0;i<x;i++)
        sum2+=a[i];
    
    return (sum1-sum2);

}


// if numbers are sorted and like (starts from other than 1) 6,7,8,9,.................
//  single missing element
void missing_element2(int a[],int x)
{
    int diff = a[0]-0;                           // let array be 6,7,8,10,11  (missing element is 9)             
    for(int i=0;i<x;i++)                         //    index     0,1,2,3, 4         diff = (6-0) = 6
    {                                            //              6-0=6 , 7-1=6, 8-2=6, 10-3=7,11-4=7                   
        if((a[0]-i)!=diff){                     //                  so missing element is (diff+3) = (6+3) = 9
            cout<<"Missing element is "<<i+diff<<endl;
            break;
        }
    }
}



// multiple missing element         O(n)
void multiple_missing(int b[],int x)
{
    int diff=b[0]-0;
    for(int i=0;i<x;i++){

        if(diff!=(b[i]-i)){

            while(diff< b[i]-i){

                cout<<i+diff<<" ";
                diff++;
            }
        }
    }
}



//  using hash or bitset
void missing_3(int A[],int n,int l,int h){
    int arr[h+1]={0};
    for(int i=0;i<n;i++){
        arr[A[i]]++;
    }

    cout<<"Missing elements are : ";
    for(int i=1;i<=h;i++){
        if(arr[i]==0)
            cout<<i<<"  ";
    }
    cout<<endl;

    
}


//      Main function
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

  //  cout<<"Missing element is "<<missing_element1(arr,n)<<endl;

   // missing_element2(arr,n);

   //multiple_missing(arr,n);

   missing_3(arr,n,1,12);
    return 0;
}




