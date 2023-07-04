#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string reverseWords(string S) 
    { 
        string str="";
        stack <char> stk;
        //stk.push('1');
        
        for(int i=S.size()-1;i>=0;i--)
        {
            if(S[i]!='.')
                stk.push(S[i]);
            else
            {
                //while(stk.top()!='1')
                while(!stk.empty())
                {
                    str+=stk.top();
                    stk.pop();
                }
                if(S[i]=='.')
                    str+='.';
            }
        }
        //str+=S[0];
        while(!stk.empty())
        {
            str+=stk.top();
            stk.pop();
        }
        return str;
    } 


int main()
{
    // string st="i.like.this.program.very.much";
    // cout<<reverseWords(st)<<endl;

    int arr[5]={1,2,3,4,5};
    int k=3;
    int i=0;
    while(i<5)
    {
        int j=i;
        while(j<(k+i) && j<5)
        {
            int temp=arr[k+i-1];
            arr[k+i-1]=arr[j];
            arr[j]=temp;
            j++;
        }
        i+=k;
    }

    for(int i=0;i<5;i++)
        cout<<arr[i]<<"  ";
    return 0;
}
