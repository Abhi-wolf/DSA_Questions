#include <iostream>
using namespace std;

class Node
{
    public:
        Node *prev;
        int data;
        Node *next;
};


class DoublyLL
{
    private:
        Node *first;
    public:
        DoublyLL()
        {
            first=NULL;
        }
        void Create(int A[],int n);
        void Display();
        int Length();
        void Insert(int index,int x);
        int Delete(int index);
        void Reverse();
};



void DoublyLL::Create(int A[],int n)
{
    Node *t,*last;
    int i;

    first=new Node;
    first->data=A[0];
    first->prev = first->next = NULL;
    last=first;

    for(i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}



void DoublyLL::Display()
{
    Node *p=first;
    if(p==NULL)
        cout<<"Empty\n";
    else
    {
        while(p != NULL)
        {
            cout<<p->data<<"  ";
            p=p->next;
        }
        cout<<endl;
    }
}




int DoublyLL::Length()
{
    Node *q=first;
    int count=0;
    while(q!=NULL)
    {
        count++;
        q=q->next;
    }
    return count;
}






void DoublyLL::Insert(int index,int x)
{
    Node *t,*p=first;


    if(index<0 || index>Length())
        return;

    t=new Node;
    t->data=x;
    if(index==0)
    {
        t->next=first;
        t->prev=NULL;
        first->prev=t;
        first=t;
    }

    else
    {
        for(int i=0;i<index-1;i++)
            p=p->next;

        t->next=p->next;
        t->prev=p;
        if(p->next)     // to check if there is any other node after this
            p->next->prev=t;
        p->next=t;   
    }
}


int DoublyLL::Delete(int index)
{
    Node *p=first;
    int x;

    if(index==1)
    {
        first=first->next;
        if(first)    first->prev=NULL;
        x=p->data;
        delete p;
    }

    else
    {
        for(int i=0;i<index-1;i++)
            p=p->next;
        p->prev->next=p->next;
        if(p->next)
            p->next->prev=p->prev;
        x=p->data;
        delete p;
    }
    return x;
}




void DoublyLL::Reverse()
{
    Node *p=first;
    Node *temp;
    while(p!=NULL)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;

        if(p!=NULL &&p->next==NULL)
            first=p;
    }
}





int main()
{
    int A[]={1,2,3,4,5,6,7,8,9,10};
    DoublyLL obj;
    obj.Create(A,10);
    obj.Display();
    // cout<<"Length = "<<obj.Length()<<endl;
    obj.Insert(10,10000);
    obj.Display();

    // cout<<obj.Delete(10)<<endl;
    // obj.Reverse();
    obj.Display();
    return 0;
}