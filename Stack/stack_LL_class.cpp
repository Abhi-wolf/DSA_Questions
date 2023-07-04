#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
};


class Stack
{
    private:
        Node *top;
    public:
        Stack()
        {
            top=NULL;
        }
        void Push(int x);
        int Pop();
        void Display();
};


void Stack::Push(int x)
{
    Node *t=new Node;
    if(t==NULL)
        cout<<"Stack Overflow\n";
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}


int Stack::Pop()
{
    Node *t=new Node;
    int x=-1;
    if(top==NULL)
        cout<<"Stack is Empty\n";
    else
    {
        t=top;
        top=top->next;
        x=t->data;
        delete t;
    }
    return x;
}



void Stack::Display()
{
    Node *p=top;
    while(p!=NULL)
    {
        cout<<p->data<<"  ";
        p=p->next;
    }
    cout<<"\n";
}




int main()
{
    Stack obj;
    obj.Push(20);
    obj.Push(10);
    obj.Push(50);
    obj.Push(40);
    obj.Push(30);
    obj.Push(100);
    obj.Push(200);

    obj.Display();

    cout<<"Pooped item is "<<obj.Pop()<<endl;
    obj.Display();
    return 0;
}