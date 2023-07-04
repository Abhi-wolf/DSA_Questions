#include <iostream>
using namespace std;


/*
         Delete nodes having greater value on right
link -- https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1?page=2&category[]=Linked%20List&sortBy=submissions
    Given a singly linked list, remove all the nodes which have a greater value on their right side.

    Input:
LinkedList = 12->15->10->11->5->6->2->3
Output: 15 11 6 3
Explanation: Since, 12, 10, 5 and 2 are
the elements which have greater elements
on the following nodes. So, after deleting
them, the linked list would like be 15,
11, 6, 3.
*/



struct Node
{
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next=NULL;
    }
};


void insertAtLast(struct Node *&head,struct Node *&last,int d)
{
    Node *t=new Node(d);
    if(head==NULL)
    {
        head=last=t;
    }

    else
    {
        last->next=t;
        last=t;
    }
}


void display(Node *head)
{
    Node *p=head;
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


Node* reverse(Node *head)
{
    Node *p=head;
    Node *q=NULL;
    Node *r=NULL;

    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    return q;
}



Node* compute(Node *head)
{
    head=reverse(head);

    Node *temp=head;

    while(head!=NULL && head->next!=NULL)
    {
        if(head->data > head->next->data)
        {
            head->next=head->next->next;
        }
        else
        {
            head=head->next;
        }
    }
    return reverse(temp);
}



int main()
{
    struct Node *head,*tail;
    head=tail=NULL;

    insertAtLast(head,tail,5);
    insertAtLast(head,tail,6);
    insertAtLast(head,tail,2);
    insertAtLast(head,tail,3);

    display(head);

    Node *ans=compute(head);

    display(ans);
    return 0;
}