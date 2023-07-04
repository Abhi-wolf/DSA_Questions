#include <iostream>
using namespace std;


/*
    You are given a pointer/ reference to the node which is to be deleted from the linked list of N nodes. 
    The task is to delete the node. Pointer/ reference to head node is not given. 
    Note: No head reference is given to you. It is guaranteed that the node to be deleted is not a 
    tail node in the linked list.


    Input:
    N = 4
    value[] = {10,20,4,30}
    node = 20
    Output: 10 4 30
    Explanation: After deleting 20 from
    the linked list, we have remaining
    nodes as 10, 4 and 30.

    Expected Time Complexity : O(1)
    Expected Auxilliary Space : O(1)
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



// instead of deleting we can shift the data in after nodes in
//  node to be deleted (shift data one node ahead)
void deleteNode(Node *del)
{
    while(del->next->next!=NULL)
    {
        del->data=del->next->data;
        del=del->next;
    }
    del->data=del->next->data;
    del->next=NULL;
}




int main()
{
    Node *head=NULL;
    Node *tail=NULL;
    InsertAtTail(head,tail,10);
    InsertAtTail(head,tail,20);
    InsertAtTail(head,tail,30);
    InsertAtTail(head,tail,40);
    InsertAtTail(head,tail,50);

    Display(head);

    Node *del=head->next;
    deleteNode(del);
    Display(head);
    return 0;
}