#include <iostream>
using namespace std;



class Queue
{
    private:
        int size;
        int front;
        int rear;
        int *Q;
    public:
        Queue()
        {
            front=rear=-1;
            size=10;
            Q=new int[size];
        }

        Queue(int size)
        {
            front=-1;
            rear=-1;
            this->size=size;
            Q=new int[this->size];
        }

        ~Queue()
        {
            delete []Q;
        }

        bool isEmpty();
        bool isFull();
        void enqueue(int x);
        int dqueue();
        void Display();
};



bool Queue::isEmpty()
{
    if(front==rear)
        return true;
    return false;
}



bool Queue::isFull()
{
    if(rear == size-1)
        return true;
    return false;
}



void Queue::enqueue(int x)
{
    if(isFull())
        cout<<"Queue is full\n";
    else
    {
        rear++;
        Q[rear]=x;
    }
}



int Queue::dqueue()
{
    int x=-1;
    if(isEmpty())
        cout<<"Queue is empty\n";
    else {
        front++;
        x=Q[front];
    }
    return x;
}
    


void Queue::Display()
{
    for(int i=front+1;i<=rear;i++)
    {
        cout<<Q[i]<<"  ";
    }
    cout<<endl;
}



int main()
{
    Queue obj(5);
    obj.enqueue(10);
    obj.enqueue(20);
    obj.enqueue(30);
    obj.enqueue(10000);
    obj.enqueue(100000);

    obj.Display();

    cout<<"deleted element is "<<obj.dqueue()<<endl;
    cout<<"deleted element is "<<obj.dqueue()<<endl;
    obj.Display();
    return 0;
}