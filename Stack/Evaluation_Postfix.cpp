#include <bits/stdc++.h>
using namespace std;








int precedence(char x)
{
  switch(x)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
      }
}




bool isOperand(char ch)
{
  return (ch>='0' && ch<='9');
}



string infixTOpostfix(string infix)
{
  string postfix;
  int n=infix.size();
  stack <char> st;
  for(int i=0;i<n;i++)
    {
      if(isOperand(infix[i]))
          postfix.push_back(infix[i]);
      else if(infix[i]=='(')
          st.push(infix[i]);
      else if(infix[i]==')')
      {
        while(st.top()!='(')
          {
            postfix.push_back(st.top());
              st.pop();
          }
        st.pop();
      }

      else
      {
        while(!st.empty() && st.top()!='(' && precedence(st.top())>=precedence(infix[i]))
          {
            postfix.push_back(st.top());
            st.pop();
          }
        st.push(infix[i]);
      }
    }
  while(!st.empty())
    {
      postfix.push_back(st.top());
      st.pop();
    }
  return postfix;
}


int calculate(string postfix)
{
    stack<int>stk;
    int n=postfix.size();
    for(int i=0;i<n;i++)
    {
        if(isOperand(postfix[i]))
        {
            char x=postfix[i];
            int y=x-48;
            stk.push(y);
            
        }
        else
        {
            int a=stk.top();
            stk.pop();
            int b=stk.top();
            stk.pop();
            
            int s;
          
            switch(postfix[i])
            {
                case '^': s=pow(b,a);
                        break;
                case '*': s=(b*a);
                        break;
                case '/': s=(b/a);
                        break;
                case '+': s=(b+a);
                        break;
                case '-': s=(b-a);
                        break;
            }
            stk.push(s);
            
        }
    }
    return stk.top();
}











int main()
{


  // string infix="8+2-3^2+3^4-2^6+5";
   // string infix="3+3*5/3+2^6+6-2^3";
  string infix="5*3-2+1-6/2+7-5*8/2";
    //string infix="3+2^3^2^1-6+7*4";
  string postfix=infixTOpostfix(infix);
  cout<<"INFIX = "<<infix<<endl;
  cout<<"POSTFIX = "<<postfix<<endl;

  cout<<"\n Calculation = "<<calculate(postfix)<<endl;
  //calculate(postfix);
  return 0;
}


