#include <iostream>
using namespace std;


struct Node
{
    int data;
    struct Node *next;
}*first=NULL;



//      CREATE FUNCTION
void Create(int A[],int n)
{
    struct Node *t,*last;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}


//  COUNT FUNCTION
int Count(struct Node *p)
{
    int count=0;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}



//      DISPLAY FUNCTION
void Display(struct Node *p)
{
    if(p==NULL)
        cout<<"Empty\n";
    
    else
    {
        while(p!=NULL)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl;
    }
}

//      INSERTION FUNCTION
void Insert(struct Node *p,int index,int x)
{
    struct Node *t;
    if(index<0 || index>Count(p))
        return;
    
    t=new Node;
    t->data=x;

    if(index==0)
    {
        t->next=first;
        first=t;
    }

    else
    {
        for(int i=0;i<index-1;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
    }
}


//  ALWAYS INSERTS AT LAST OF NODE
void InsertLast(int x)
{
    struct Node *t,*last;
    t=new Node;
    t->data=x;
    t->next=NULL;

    if(first==NULL)
        first=last=t;
    
    else
    {
        last->next=t;
        last=t;
    }
}



//      INSERT IN SORTED LINKED LIST
void InsertSortedList(struct Node *p,int x)
{
    struct Node *t,*q=NULL;
    t=new Node;
    t->data=x;
    t->next=NULL;
    
    if(first==NULL)
        first=t;
    
    else
    {
        while(p!=NULL && p->data<x)
        {
            q=p;
            p=p->next;
        }

        if(p==first)
        {
            t->next=first;
            first=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }
}

int main()
{
    int A[]={1,2,3,4,5,6,7,8,9,10};
    Create(A,10);
    Display(first);
    // cout<<"Size = "<<Count(first)<<endl;
    // Insert(first,10,10000);
    // Display(first);
    // cout<<"Size = "<<Count(first)<<endl;

    // InsertLast(1);
    // InsertLast(10);
    // InsertLast(20);
    // InsertLast(30);
    // Display(first);

    InsertSortedList(first,11);
    Display(first);
    
    return 0;
}