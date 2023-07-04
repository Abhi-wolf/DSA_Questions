#include <iostream>
using namespace std;

// pallindrom means when we reverse the string or num we get same string or num
// abccba,121,111 etc

bool palindromic_Array(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int reverse=0;
        int p=arr[i];
        int mod=0;

        // calculating revrse of each numbers
        while(p!=0)
        {
            mod=p%10;
            reverse=reverse*10+mod;
            p=p/10;
        }

        if(reverse!=arr[i])
            return false;
    }

    return true;
}



int main()
{
    int a1[]={111,333,454,909};

    if(palindromic_Array(a1,4))
        cout<<"Array is pallindromic \n";
    else
        cout<<"Array is not pallindromic \n";



    int a2[]={111,345,454,956};

    if(palindromic_Array(a2,4))
        cout<<"Yes the array is pallindromic \n";
    else
        cout<<"Array is not pallindromic \n";
    
    return 0;
}