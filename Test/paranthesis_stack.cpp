
#include <iostream>
#include <stack>
using namespace std;


bool ispar(string x)
{
    stack<char> s;
    char ch;
    for (int i = 0; i < x.length(); i++)
    {
        if (x[i] == '[' || x[i] == '{' || x[i] == '(')
            s.push(x[i]);
        else
        {
            ch = s.top();
                s.pop();
            if (x[i] == ']')
            {
                if (ch == '[')
                    continue;
                else
                    return false;
            }

            else if (x[i] == '}')
            {
                if (ch == '{')
                    continue;
                else
                    return false;
            }

            else if (x[i] == ')')
            {
                if (ch == '(')
                    continue;
                else
                    return false;
            }
            else
                return false;
        }
    }
    if (s.empty())
        return true;
    else
        return false;
}


/*

bool ispar(string str)
    {
        stack<char>stk;
        for(int i=0;i<str.length();i++){
            if(str[i]=='{' || str[i]=='[' || str[i]=='('){
                stk.push(str[i]);
            }
            else{
                if(!stk.empty()){
                    char top=stk.top();
                    if( top=='{' && str[i]=='}' || top=='[' && str[i]==']' || top=='(' && str[i]==')' ){
                        stk.pop();
                    }
                    else{
                        return false;
                    }

                }
                else{
                    return false;
                }
            }
        }
        if(stk.empty()){
            return true;
        }
        else{
            return false;
        }

    }

    */

int main()
{
    string str = "[{()}]";
    cout << ispar(str) << endl;
    return 0;
}