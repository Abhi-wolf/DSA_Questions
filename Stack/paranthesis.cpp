#include <iostream>
using namespace std;


//  if the expression matches the condition push into stack
// and if not don't push
// if the expression is other than that then pop from stack 
// (it means the similar match has been found)


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
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(') 
            Push(exp[i]);
        else if(exp[i]==')')
        {
            if(top==NULL)
                return 0;
            Pop();
        }
    }

    if(top==NULL)
        return 1;
    else
        return 0;
}





int main()
{
    char *ch="(((a+b)*(c-d)))";
    cout<<IsBalanced(ch)<<endl;
    return 0;
}