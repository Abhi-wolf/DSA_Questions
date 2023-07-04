//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>

using namespace std;

/*
// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	bool fascinating(int n) {
	    // code here
	    int twomul=2*n;
	    int threemul=3*n;
	    
	    int arr[9];
	    
	    int mod;
	    int i=0;
	    
	    while(n!=0)
	    {
	        arr[i++]=n%10;
	        
	        if(i>10)
	            return false;
	            
	        n=n/10;
	    }
	    
	    while(twomul!=0)
	    {
	        arr[i++]=twomul%10;
	        
	        if(i>10)
	            return false;
	        
	        twomul=twomul/10;
	    }
	    
	    while(threemul!=0)
	    {
	        arr[i++]=threemul%10;
	        threemul=threemul/10;
	        if(i>10)
	            return false;
	    }
	    
	    sort(arr,arr+9);
	    for(int j=0;j<10;j++)
	    {
	        if(arr[j] != j+1)
	            return false;
	    }
	    
	    return true;
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.fascinating(n);
        if (ans) {
            cout << "Fascinating\n";
        } else {
            cout << "Not Fascinating\n";
        }
    }
    return 0;
}
// } Driver Code Ends */

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--)
	{
	    string str1,str2;
	    cin>>str1;
	    
	    int len=str1.size();
	    char ch=str1[0];
	    int i=0,j=0;
	    int count=0;
	    while(i<len)
	    {
            //cout<<"hello\n";
	        if(str1[i]==ch)
	            count++;
	        else
	        {
	            //str2[j++]=ch;
	            //str2[j++]=count;

                str2.push_back(ch);
                //string s=to_string(count);
	            str2.push_back(char(count));
	            ch=str1[i];
	            count=1;
	        }
	            i++;
	    }
        cout<<str1<<"  "<<str2<<endl;
        cout<<str1.size()<<"  "<<str2.size()<<endl;
	    if(str1.size() > str2.size())
	        cout<<"YES \n";
	    else
	        cout<<"NO \n";
	}
	return 0;
}
