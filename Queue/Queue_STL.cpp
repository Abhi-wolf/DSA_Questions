#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue <int> q1;

    //  insert an element at last
    q1.push(10);
    q1.push(12);
    q1.push(23);

    // returns size 
    cout<<"size = "<<q1.size()<<endl;

    //  removes a element from first
    q1.pop();
    cout<<"size = "<<q1.size()<<endl;

    //  returns first element
    cout<<"front = "<<q1.front()<<endl;

    // returns last element
    cout<<"last = "<<q1.back()<<endl;

    // construct and insert an element
    q1.emplace(100);

    if(q1.empty())
        cout<<"yes empty\n";
    else
        cout<<"not empty \n";

    
    queue <int> q2;

    q2.push(1);
    q2.push(3);
    q2.push(5);
    q2.push(7);

    cout<<"\tBefore swap \n";
    cout<<"Size of first queue = "<<q1.size()<<"\t top of first queue = "<<q1.front()<<endl;
    cout<<"Size of second queue = "<<q2.size()<<" \ttop of second queue = "<<q2.front()<<endl;

    q1.swap(q2);

    cout<<"\tAfter swap \n";
    cout<<"Size of first queue = "<<q1.size()<<" \ttop of first queue = "<<q1.front()<<endl;
    cout<<"Size of second queue = "<<q2.size()<<" \ttop of second queue = "<<q2.front()<<endl;
    return 0;
}