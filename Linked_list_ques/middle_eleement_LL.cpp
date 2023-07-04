#include <iostream>
using namespace std;


/* 
    Given a singly linked list of N nodes.
    The task is to find the middle of the linked list. For example, if the linked list is
    1-> 2->3->4->5, then the middle node of the list is 3.
    If there are two middle nodes(in case, when N is even), print the second middle element.
    For example, if the linked list given is 1->2->3->4->5->6, then the middle node of the list is 4.
*/


class Node 
{
    public:
        int data;
        struct Node *next;
    Node(int d)
    {
        this->data=d;
        this->next=NULL;
    }
};




//  Insertion at the front
void InsertAtHead(Node *&head,Node *&tail,int x)
{
    Node *t=new Node(x);

    if(head==NULL)
    {
        head=t;
        tail=t;
    }
    else
    {
        t->next=head;
        head=t;
    }
}




//  Insertion at the end
void InsertAtTail(Node *&head,Node *&tail,int x)
{
    Node *t=new Node(x);

    if(tail==NULL)
    {
        head=tail=t;
    }

    else
    {
        tail->next=t;
        tail=t;
    }
}



//  Display node of linked list 
void Display(Node *head)
{
    Node *p=head;
    if(p==NULL)
        cout<<"List empty\n";
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



//  Count no of nodes
int getLength(Node *head)
{
    Node *p=head;
    int len=0;
    while(p!=NULL)
    {
        p=p->next;
        len++;
    }
    return len;
}



int getMiddle(Node *head)
{
    Node *p=head;

    //  find length of LL and make its half
    int mid=(getLength(head)/2)+1;

    // traverse to the node just before the required node
    while(mid>1)
    {
        p=p->next;
        mid--;
    }
    return p->data;
}




int main()
{
    Node *head=NULL;
    Node *tail=NULL;

    InsertAtHead(head,tail,2);
    InsertAtHead(head,tail,1);
    InsertAtTail(head,tail,3);
    InsertAtTail(head,tail,4);
    InsertAtTail(head,tail,5);
    InsertAtTail(head,tail,6);


    Display(head);

    cout<<"Length = "<<getLength(head)<<endl;
    
    cout<<"Middle element = "<<getMiddle(head)<<endl;

    return 0;
}