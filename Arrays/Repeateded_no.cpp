#include <iostream>
#include <vector>
using namespace std;


// for multiple duplicate elements (time=O(n)  && space=O(x))
vector<int> duplicate(int arr[],int n) {
    vector<int>ans;
    for(int i=0;i<n;i++) {
        int index=arr[i]%n;
        arr[index]+=n;
    }

    for(int i=0;i<n;i++) {
        if(arr[i]/n >=2) ans.push_back(i);
    }

    return ans;
}


// for single duplicate element (time=O(n)  && space=O(1))
int findDuplicate(int arr[],int n) {
    int slow=0,fast=0;
    do {
        slow=arr[slow];
        fast=arr[arr[fast]];
    }while(slow!=fast);

    slow=0;
    while(slow!=fast) {
        slow=arr[slow];
        fast=arr[fast];
    }

    return slow;
}

int main() {
    int arr[5]={1,3,4,1,3};
    int res=findDuplicate(arr,5);
    cout<<"duplicate = "<<res<<endl;
    cout<<endl;
    vector<int>v=duplicate(arr,5);
    for(int i=0;i<v.size();i++) cout<<v[i]<<", ";
    
    return 0;
}
