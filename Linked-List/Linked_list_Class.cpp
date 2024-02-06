
//  LINKED LIST USING CLASS AND OBJECTS

#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
};



class LinkedList
{
    private:
        Node *first;
    public:
        LinkedList()
        {
            first=NULL;
        }
        LinkedList(int A[],int n);
        ~LinkedList();

        void Display();
        void Insert(int num,int index);
        int Delete(int index);
        int Length();
};



//  CONSTRUCTOR TO ASSIGN VALUES
LinkedList::LinkedList(int A[],int n)
{
    Node *t,*last;

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



// DISTRUCTOR TO DEALLOCATE MEMORY
LinkedList::~LinkedList()
{
    Node *p=first;
    while(first)
    {
        first=first->next;
        delete p;
        p=first;
    }
}



//  DISPLAY FUNCTION
void LinkedList::Display()
{
    Node *p=first;
    if(p==NULL)
        cout<<"Empty\n";
    else
    {
        while(p)
        {
            cout<<p->data<<"  ";
            p=p->next;
        }
        cout<<endl;
    }
}



//  CALCULATES LENGTH OF LINKED LIST
int LinkedList::Length()
{
    Node *p=first;
    int count=0;
    while(p)
    {
        count++;
        p=p->next;
    }
    return count;
}



//  INSERT FUNCTION TO INSERT AT A GIVEN LOCATION
void LinkedList::Insert(int num,int index)
{
    Node *t,*p=first;

    if(index<0 || index>Length())
        return ;

    t=new Node;
    t->data=num;
    t->next=NULL;

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


//  DELETE FUNCTION TO DELETE A NODE
int LinkedList::Delete(int index)
{
    Node *p,*q;
    int x,i;
    if(index==0)
    {
        p=first;
        first=first->next;
        x=p->data;
        delete p;
    }

    else
    {
        p=first;
        for(i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
    }
    return x;
}



int main()
{
    int A[]={1,3,5,7,9};
    
    LinkedList obj(A,5);
    obj.Display();

    

    return 0;
}