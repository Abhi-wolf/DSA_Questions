#include <iostream>
using namespace std;

//  Circular linked list is a linked list where all nodes are connected to form a circle. There is no NULL at the end. 
//  A circular linked list can be a singly circular linked list or a doubly circular linked list.


//  A static int variable remains in memory while the program is running. A normal or auto variable is destroyed when 
//  a function call where the variable was declared is over. 

class Node
{
    public:
        int data;
        Node *next;
};



class CircularLL
{
    private:
        Node *head;
    public:
        CircularLL()
        {
            head=NULL;
        }

        CircularLL(int A[],int n);
        void Display();
        void Recursive_Display(Node *p);
        Node * Gethead()
        {
            return head;
        }
        int Length();
        void Insert(int index,int x);
        int Delete(int index);
        ~CircularLL();
};





//  CONSTRUCTOR
CircularLL::CircularLL(int *A,int n)
{
    Node *tail,*t;
    
    head= new Node;
    head->data=A[0];
    head->next=head;
    tail=head;

    for(int i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=tail->next;
        tail->next=t;
        tail=t;
    }
}



//  DISPLAY FUNCTION
void CircularLL::Display()
{
    Node *p=head;
    do
    {
        cout<<p->data<<"  ";
        p=p->next;
    } while (p!=head);
    cout<<endl;
}



//  (at first p will equal to head so it will not enter the loop to avoid this flag int is used)
//  (when Recursive_Display will be called again the int will become 0 to avoid this static int is used)
void CircularLL::Recursive_Display(Node *p)
{
    static int flag=0;
    if(p!=head || flag==0)
    {
        flag=1;
        cout<<p->data<<"  ";
        Recursive_Display(p=p->next);
    }
    flag=0;
}



//  DISTRUCTOR
CircularLL::~CircularLL()
{
    Node *p=head;
    while(p->next != head)
    {
        p=p->next;
    }

    while(p!=head)
    {
        p->next=head->next;
        delete head;
        head=p->next;
    }

    if(p==head)
    {
        delete head;
        head=nullptr;
    }
}



//  CALCULATES LENGTH OF CIRCULAR LINKED LIST
int CircularLL::Length()
{
    int count=0;
    Node *p=head;
    do
    {
        count++;
        p=p->next;
    }while(p!=head);
    return count;
}



//  INSERTION FUNCTION  
void CircularLL::Insert(int index,int x)
{
    Node *t,*p=head;

    if(index<0 && index>Length())
        return;

    if(index==0)
    {
        t=new Node;
        t->data=x;

        //  (if there is no nodes)
        if(head==NULL)
        {
            head=t;
            head->next=head;
        }

        //  (there are nodes but we have to insert in first node for this we have to change in next pointer of the last node
        //      because it points to the first node)
        else
        {
            while(p->next != head)    p=p->next;    // take pointer to last node

            p->next=t;
            t->next=head;
            head=t;
        }
    }

    // (to insert in any node except first)
    else
    {
        for(int i=0;i<index-1;i++)
            p=p->next;

        t=new Node;
        t->data=x;
        t->next=p->next;
        p->next=t;
    }
}




//  DELETION FUNCTION
int CircularLL::Delete(int index)
{
    Node *p=head,*q;
    int x;
    if(index <0 && index>Length())
        return -1;
    
    //  (to delete first or head index)
    if(index==1)
    {
        while(p->next != head)  p=p->next;
        x=head->data;

        // (if there is only one node)
        if(p==head)
        {
            delete head;
            head=NULL;
        }
        else
        {
            p->next=head->next;
            delete head;
            head=p->next;
        }
    }

    else
    {
        for(int i=0;i<index-2;i++)
            p=p->next;
        q=p->next;
        p->next=q->next;
        x=q->data;
        delete q;
    }
    return x;
}


int main()
{
    int A[]={1,2,6,7,8,10,12};
    CircularLL obj(A,sizeof(A)/sizeof(A[0]));
    Node *h=obj.Gethead();
    obj.Recursive_Display(h);
    cout<<"\nLength of linked list = "<<obj.Length()<<endl;
    obj.Insert(7,100);
    obj.Display();
    cout<<"Length of linked list = "<<obj.Length()<<endl;
    cout<<"Deleted element is = "<<obj.Delete(3)<<endl;
    obj.Display();
    return 0;
}