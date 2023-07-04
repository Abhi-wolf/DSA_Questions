#include<bits/stdc++.h>
using namespace std;

void permute(string str,string out)
{
    if(str.size()==0)
    {
        cout<<out<<endl;
        return;
    }

    for(int i=0;i<str.size();i++)
    {
        permute(str.substr(1),out+str[0]);

        rotate(str.begin(),str.begin()+1,str.end());
    }
}

void permute2(string str)
{
    sort(str.begin(),str.end());

    do{
        cout<<str<<endl;
    } while(next_permutation(str.begin(),str.end()));
}


void permute3(char s[],int k)
{
    static int A[10]={0};
    static char res[10];
    
    if(s[k]=='\0'){
        res[k]='\0';
        cout<<res<<endl;
    }

    else{
        for(int i=0;s[i]!='\0';i++)
        {
            if(A[i]==0)
            {
                res[k]=s[i];
                A[i]=1;
                permute3(s,k+1);
                A[i]=0;
            }
        }
    }
}

int main()
{
    char str[] = "ABHijeet";
   // permute(str,"");
   permute3(str,0);
    return 0;
}