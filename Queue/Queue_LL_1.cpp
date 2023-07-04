#include <iostream>
using namespace std;



class Node
{
    public:
        int data;
        Node *next;
};


class Queue
{
    private:
        Node *front;
        Node *rear;
    public:
        Queue();
        ~Queue();
        void enqueue(int x);
        int dequeue();
        bool isEmpty();
        void Display();
};


//  CONSTRUCTOR
Queue::Queue()
{
    front=NULL;
    rear=NULL;
}




//  INSERTIO IN QUEUE
void Queue::enqueue(int x)
{
    Node *t=new Node;
    if(t==NULL)
        cout<<"Queue Overflow\n";
    else
    {
        t->data=x;
        t->next=NULL;

        if(front==NULL)
            front=rear=t;
        
        else
        {
            rear->next=t;
            rear=t;
        }
    }
}




//  DELETION FROM QUEUE
int Queue::dequeue()
{
    Node *p=front;
    int x=-1;
    if(isEmpty())
        cout<<"Queue is Empty\n";
    else
    {
        front=front->next;
        x=p->data;
        delete p;
    }
    return x;
}





//  FUNCTION TO FIND IS QUEUE EMPTY
bool Queue::isEmpty()
{
    if(front==NULL)
        return true;
    return false;
}




//  DESTRUCTOR
Queue::~Queue()
{
    Node *p=front;
    while(front)
    {
        front=front->next;
        delete p;
        p=front;
    }
}




//  DISPLAY FUNCTION
void Queue::Display()
{
    Node *p=front;
    while(p)
    {
        cout<<p->data<<flush;
        p=p->next;
        if(p!=NULL)
            cout<<" <- "<<flush;
    }
    cout<<endl;
}



//  MAIN FUNCTION
int main()
{
    int A[]={1,2,3,4,5,6,7,8,9,10};
    Queue obj;
    for(int i=0;i<10;i++)
        obj.enqueue(A[i]);
    
    obj.Display();
    cout<<"Deleted item is "<<obj.dequeue()<<endl;
    obj.Display();
    return 0;
}