#include <iostream>
using namespace std;


class Node
{
    public:
        int data;
        Node *next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};


void Insert(Node **head,int x)
{
    Node *t=new Node(x);
    Node *temp=*head;
    
    if(*head==NULL)
    {
        *head=t;
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=t;
}




void Display(Node *p)
{
    if(p==NULL)
        cout<<"Empty\n";
    else
    {
        while(p!=NULL)
        {
            cout<<p->data<<"  ";
            p=p->next;
        }
        cout<<endl;
    }
}



Node * Merge(Node *p,Node *q)
{
    Node *third;
    Node *last;
    if(p==NULL)
        return q;
    if(q==NULL)
        return p;
    if(p->data < q->data)
    {
        third=last=p;
        p=p->next;
        last->next=NULL;
    }

    else
    {
        third=last=q;
        q=q->next;
        last->next=NULL;
    }

    while(p!=NULL && q!=NULL)
    {
        if(p->data < q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }

        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p!=NULL)
        last->next=p;
    if(q!=NULL)
        last->next=q;
    
    return third;
}





int main()
{
    Node *res=NULL;
    Node *a=NULL;
    Node *b=NULL;

    Insert(&a,1);
    Insert(&a,3);
    Insert(&a,5);
    Insert(&a,1000);
    Display(a);


    Insert(&b,2);
    Insert(&b,4);
    Insert(&b,6);
    Insert(&b,100);
    Display(b);

    res=Merge(a,b);
    Display(res);
    return 0;
}