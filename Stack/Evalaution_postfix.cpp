#include <iostream>
#include <string.h>
using namespace std;


struct Node
{
  int data;
  Node *next;
}*top=NULL;


void push(int x)
{
  struct Node *t;
  t=new Node;
  if(t==NULL)
      cout<<"Stack is full\n";
  else
  {
    t->data=x;
    t->next=top;
    top=t;
  }
}



int pop()
{
  struct Node *t;
  int x=-1;
  if(top==NULL)
    cout<<"Stack is empty\n";
  else
  {
    t=top;
    top=top->next;
    x=t->data;
    delete t;
  }
  return x;
}



int pre(char x)
{
  if(x=='+' || x=='-')
    return 1;
  else if(x=='*' || x=='/')
    return 2;
  return 0;
}



int isOperand(char x)
{
  if(x=='+' || x=='-' || x=='*' || x=='/')
    return 0;
  return 1;
}



/*
char * InfixToPostfix(char *infix)
{
  int i=0,j=0;
  char *postfix;
  long len=strlen(infix);
  postfix=new char[len+2];

  while(infix[i]!='\0')
  {
    if(isOperand(infix[i])) 
      postfix[j++]=infix[i++];
    else 
    {
      if(pre(infix[i]) > pre(top->data))
        push(infix[i++]);
      else
        postfix[j++]=pop();
    }
  }

  while(top!=NULL)
    postfix[j++]=pop();
  postfix[j]='\0';
  return postfix;
} */




int Evaluate(char *postfix)
{
  int i=0;
  int x1,x2,r=0;
  for(i=0;postfix[i]!='\0';i++)
    {
      if(isOperand(postfix[i]))
        push(postfix[i]-'0');
      else  
      {
        x2=pop();
        x1=pop();
        switch(postfix[i])
          {
             case '+':
                r=x1+x2;
                break;
             case '-':
                r=x1-x2;
                break;
             case '*':
                r=x1*x2;
                break;
             case '/':
                r=x1/x2;
                break;
          }
        push(r);
      }
    }
  return top->data;
}




int main() {
  char *postfix="234*+62/-";
  cout<<"Result "<<Evaluate(postfix)<<endl;
  return 0;
}