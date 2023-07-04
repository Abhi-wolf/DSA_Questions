#include <iostream>
using namespace std;


/* 
    Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

    Input:
    LinkList1 = 3->6->9->common
    LinkList2 = 10->common
    common = 15->30->NULL
    Output: 15
    
    first LL    3->6->9->15->30
    second LL        10->15->30 
    ans = 15
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



// jis LL ka size kam hoga uten size ka hee dusrey LL ka size alag kar leyengey last sey
//  jab traverse karengey taab dono ka distance intersection point sey bara bar hoga
int IntersectionPoint(Node *head1,Node *head2)
{
    //  found size of both LL
    int len1=getLength(head1);
    int len2=getLength(head2);


    Node *ptr1=NULL;
    Node *ptr2=NULL;

    int d=0;

    //  if size of first LL is greater than second
    if(len1>len2)
    {
        d=len1-len2;
        ptr1=head1;
        ptr2=head2;
    }

    //   size of first LL is greater than second
    else
    {
        d=len2=len1;
        ptr1=head2;
        ptr2=head1;
    }

    // traverse the large LL to make size of both the LL same
    while(d)
    {
        ptr1=ptr1->next;
        if(ptr1==NULL)
            return -1;
        d--;
    }

    // starts comparing both LL 
    while(ptr1!=NULL && ptr2!=NULL)
    {
        //  if both LL intersects return intersectionpoint data
        if(ptr1==ptr2)
            return ptr1->data;
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}





int main()
{
    Node *head1=NULL;
    Node *tail1=NULL;

    Node *head2=NULL;
    Node *tail2=NULL;

    InsertAtHead(head1,tail1,6);
    InsertAtHead(head1,tail1,3);
    InsertAtTail(head1,tail1,9);

    InsertAtHead(head2,tail2,10);
    tail2->next=tail1;

    InsertAtTail(head1,tail1,15);
    InsertAtTail(head1,tail1,30);


    


    Display(head1);
    Display(head2);

    cout<<"Length of LL 1 = "<<getLength(head1)<<endl;
    cout<<"Length of LL 2 = "<<getLength(head2)<<endl;

    cout<<"Intersection point= "<<IntersectionPoint(head1,head2)<<endl;
    return 0;
}