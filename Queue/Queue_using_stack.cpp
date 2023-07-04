#include <iostream>
#include <stack>
using namespace std;

//  Implement Queue data structure using two stacks
 
class Queue
{
    stack<int> s1,s2;
    public:
        void enqueue(int x);
        int dequeue();
};


//  push  elements in first stack
void Queue::enqueue(int x)
{
    s1.push(x);
}



// during poping first pop all elements from first stack and 
//  push into second stack and then pop the top element from the second stack 
int Queue::dequeue()
{
    int x=-1;

    // check if second stack is empty if not empty then directly pop from second stack
    if(s2.empty())
    {
        // check if first stack is also empty ,if empty then the list is empty
        if(s1.empty())
        {
            cout<<"Queue underflow \n";
            return x;
        }

        else
        {
            // pop all elements from stack 1 and push to stack 2
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }
    // pop first element from stack 2 and return
    x=s2.top();
    s2.pop();
    return x;
}




int main()
{
    Queue obj;
    obj.enqueue(10);
    obj.enqueue(20);
    obj.enqueue(30);
    obj.enqueue(40);
    obj.enqueue(50);

    cout<<obj.dequeue()<<endl;
    cout<<obj.dequeue()<<endl;

    obj.enqueue(10);
    obj.enqueue(20);

    cout<<obj.dequeue()<<endl;
    cout<<obj.dequeue()<<endl;

    return 0;
}