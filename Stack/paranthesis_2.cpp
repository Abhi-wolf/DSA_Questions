#include <iostream>
using namespace std;

//  for expression like  [{(a+b)*c}/q]


struct Node 
{
    char data;
    Node *next;
}*top=NULL;




void Push(char x)
{
    struct Node *t=new Node;
    if(t==NULL)
        cout<<"Stack overflow\n";
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}





char Pop()
{
    struct Node *t=new Node;
    char x='\0';
    if(top==NULL)
        cout<<"Stack Empty\n";
    else
    {
        x=top->data;
        t=top;
        top=top->next;
        delete t;
    }
    return x;
}





void Display()
{
    struct Node *p;
    p=top;
    while(p!=NULL)
    {
        cout<<p->data<<"  ";
        p=p->next;
    }
    cout<<"\n";
}






int IsBalanced(char *exp)
{
    char ch='\0';
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='[' || exp[i]=='{' || exp[i]=='(') 
            Push(exp[i]);
        else
        { 
            if(exp[i]==']')
            {
                ch=Pop();
                if(ch=='[')
                    continue;
                else 
                    return 0;
            }


            else if(exp[i]=='}')
            {
                ch=Pop();
                if(ch=='{')
                    continue;
                else 
                    return 0;
            }

            else if(exp[i]==')')
            {
                ch=Pop();
                if(ch=='(')
                    continue;
                else 
                    return 0;
            }
        }
    }

    if(top==NULL)
        return 1;
    else
        return 0;
}





int main()
{
    // char *ch="[{(a+b)*(c-d)}]";
    char *ch="[{(a+b)*c}/e]";
    cout<<IsBalanced(ch)<<endl;
    return 0;
}