#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
    Node(int d)
    {
        this->data=d;
        this->next=NULL;
    }

    ~Node()
    {
        int val=this->data;
        if(this->next!=NULL)
        {
            delete next;
            next=NULL;
        }
        cout<<"Memory is free for node with data "<<val<<endl;
    }
};





void InsertNode(Node *&tail,int element,int d)
{
    //empty list
    if(tail==NULL)
    {
        Node *temp=new Node(d);
        tail=temp;
        temp->next=temp;
    }

    else {
        Node *curr=tail;
        while(curr->data != element)
            curr=curr->next;
        
        Node *temp=new Node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}




void print(Node *tail)
{
    Node *t=tail;

    if(tail==NULL)
    {
        cout<<"List is Empty \n";
        return ;
    }


    do
    {
        cout<<t->data<<"  ";
        t=t->next;
    } while (t!=tail);
    cout<<endl;
}



void DeleteNode(Node *&tail,int x)
{
    if(tail==NULL)
    {
        cout<<"List is empty\n";
        return;
    }

    else
    {
        Node *prev=tail;
        Node *curr=prev->next;
        while(curr->data != x)
        {
            prev=curr;
            curr=curr->next;
        }

        
        prev->next=curr->next;

        // 1 Node exit in linked list
        if(curr==prev)
            tail=NULL;

        // >= 2 Node exit in linked list
        if(tail==curr)
            tail=prev;

        curr->next=NULL;
        delete curr;
    }
    
}




bool isCircularList(Node *tail)
{
    if(tail==NULL)
        return true;
    
    else
    {
        Node *temp=tail->next;
        while(temp!=NULL && temp!=tail)
        {
            temp=temp->next;
        }

        if(temp==tail)
            return true;
    }
    return false;
}



int main()
{
    Node *tail=NULL;
    InsertNode(tail,5,3);
    InsertNode(tail,3,4);
    InsertNode(tail,4,5);
    InsertNode(tail,5,6);
    print(tail);

    DeleteNode(tail,3);
    print(tail);

    if(isCircularList(tail))
        cout<<"Yes circular \n";
    else
        cout<<"Not circular \n";
    return 0;
}