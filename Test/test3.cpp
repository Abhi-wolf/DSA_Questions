#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--)
	{
	   int n;
       cin>>n;
	   string str;
       cin>>str;
	        
	    unordered_map<char,int>u;
	    
	    for(int i=0;i<n;i++)
	        u[str[i]]++;
	    
	    int count1=-1;
        int count0=-1;
        int no;

         unordered_map<char,int> :: iterator itr;
	    // for(itr=u.begin();itr!=u.end();itr++)
	    // {
	    //     // if(itr->second % 2 == 0)
        //     // {
	    //     //     count=itr->second;
        //     //     no=itr->first;
        //     // }

        //     count1=
	    // }
	    
        count1=u.count('1');
        count0=u.count('0');

        cout<<count1<<"  "<<count0<<endl;
       
	    if(count1%2==0 || count0%2==0)
        {
         cout<<"Yes \n";   
        }
            
        else
            cout<<"No\n";
	}
	return 0;
}
