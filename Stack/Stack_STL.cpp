#include <iostream>
#include <stack>
using namespace std;

//          STACK USING STL

/*
Difference between stack::emplace() and stack::push() function. 
While push() function inserts a copy of the value or the parameter passed to the function into the container at the top, 
the emplace() function constructs a new element as the value of the parameter and then adds it to the top of the container. 
*/
int main()
{
    stack <int> s;
    stack <int> p;
    s.push(1);
    s.push(2);

    cout<<s.top()<<endl;

    if(s.empty())
        cout<<"Stack is empty \n";
    else
        cout<<"Stack is not empty \n";

    s.pop();
    s.pop();
    

    if(s.empty())
        cout<<"Stack is empty \n";
    else
        cout<<"Stack is not empty \n";


    cout<<"Size of stack = "<<s.size()<<endl;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<"top element = "<<s.top()<<"\tsize = "<<s.size()<<endl;

    p.push(100);
    p.push(200);
    cout<<"top element = "<<p.top()<<"\tsize = "<<p.size()<<endl;
    
    p.swap(s);
    cout<<"top element = "<<p.top()<<"\tsize = "<<p.size()<<endl;
    return 0;
}