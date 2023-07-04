#include <iostream>
#include <vector>
using namespace std;

/*
Sliding Window Technique : The technique can be best understood with the window pane in bus, consider a window of length n 
and the pane which is fixed in it of length k.Consider, initially the pane is at extreme left i.e., at 0 units from the left.
Now, co - relate the window with array arr[] of size n and pane with current_sum of size k elements.Now, if we apply force on 
the window such that it moves a unit distance ahead.The pane will cover next k consecutive elements.

Applying sliding window technique :

1. We compute the sum of first k elements out of n terms using a linear loop and store the sum in variable window_sum.
2. Then we will graze linearly over the array till it reaches the end and simultaneously keep track of maximum sum.
3. To get the current sum of block of k elements just subtract the first element from the previous block and add the last element of the current block.
*/


vector<int> subArraySum(int arr[],int n,long long int s)
{
    int first=-1;
    int last=-1;

    //  initialize currsum as value of first element and starting point to 0
    long long int currsum=arr[0];
    int start=0;

    //  add elements one by one to currsum and if the currsum 
    //  exceds the sum then remove starting element
    for(int i=1;i<=n;i++)
    {

        //  if currsum exceeds the sum then remove the starting elements
        while(currsum > s && start<i-1)
        {
            currsum=currsum-arr[start];
            start++;
        }

        //  if currsum becomes equal to s then return the first and last indexof the array
        if(currsum == s)
        {
            first=start+1;
            last=i;
            return {first,last};        // 1 based index is returend
        }

        //  currsum is still less than s
        if(i<n)
            currsum+=arr[i];
    }

    //  if we reach here,then it means there's no subarray
    return {-1};

}





int main()
{
    //  unsorted array is given
    //int a[]={1,2,6,3,9,8,4,5,10,7};
    int a[]={1,2,3,4,5,6,7,8,9,10};
    vector <int> v;
    v=subArraySum(a,10,15);

    int l=v[v.size()-1];
    for(int i=v[0];i<=l;i++)
        cout<<a[i-1]<<"  ";
    cout<<endl;
    return 0;
}