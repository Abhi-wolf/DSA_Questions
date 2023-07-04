#include <iostream>
using namespace std;


 
class Node
{
    public:
        int data;
        Node *next;
    Node(int x)
    {
        this->data=x;
        this->next=NULL;
    }
};



void enqueue(Node *&front,Node *&rear,int x)
{
    Node *temp=new Node(x);
    if(front==NULL)
    {
        front=temp;
        rear=temp;
    }

    else
    {
        rear->next=temp;
        rear=temp;
    }
}


int dequeue(Node *&front)
{
    int x=-1;
    Node *t;
    if(front==NULL)
    {
        cout<<"Queue underflow \n";
        return x;
    }

    else
    {
        t=front;
        x=front->data;
        front=front->next;
        delete t;   
    }
    return x;
}



void Display(Node *front)
{
    Node *p=front;
    if(front==NULL)
        cout<<"Queue underflow \n";
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





int getLength(Node *front)
{
    int len=0;
    Node *p=front;

    while(p!=NULL)
    {
        len++;
        p=p->next;
    }
    return len;
}



int main()
{
    Node *front=NULL;
    Node *rear=NULL;

    enqueue(front,rear,10);
    enqueue(front,rear,20);
    enqueue(front,rear,30);
    enqueue(front,rear,40);

    Display(front);
    cout<<"Length = "<<getLength(front)<<endl;

    cout<<dequeue(front)<<endl;
    cout<<dequeue(front)<<endl;

    Display(front);
    cout<<"Length = "<<getLength(front)<<endl;

    return 0;
}




