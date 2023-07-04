#include <iostream>
using namespace std;

template <typename T>
class node
{
public:
    T data;
    node<T> *next;
};

template <typename T>
class stack
{
private:
    node<T> *top;

public:
    stack()
    {
        top = NULL;
    }
    void push(T x);
    T pop();
    void print();
};

template <typename T>
void stack<T>::push(T x)
{
    node<T> *t = new node<T>;
    if (t == NULL)
        cout << "Stack overflow\n";

    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

template <typename T>
T stack<T>::pop()
{
    node<T> *t = new node<T>;
    T x;
    if (t == NULL)
        cout << "Stack is Empty\n";

    else
    {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

template <typename T>
void stack<T>::print()
{
    node<T> *t = top;
    while (t != NULL)
    {
        cout << t->data << "  ";
        t = t->next;
    }
    cout << "\n";
}

int main()
{
    stack<int> obj;
    obj.push(10);
    obj.push(20);
    obj.push(30);
    obj.push(40);
    obj.push(50);
    obj.push(60);
    obj.push(70);
    obj.print();
    cout << "poped item : " << obj.pop() << endl;
    obj.print();

    cout << "\n\n";
    stack<float> obj1;
    obj1.push(2.89);
    obj1.push(1.46);
    obj1.push(3.98);
    obj1.push(9.09);
    obj1.push(5.32);
    obj1.push(6.7);
    obj1.push(5.823);
    obj1.print();
    cout << "poped item : " << obj1.pop() << endl;
    obj1.print();

    cout << "\n\n";
    stack<string> obj2;
    obj2.push("godda");
    obj2.push("ranchi");
    obj2.push("hisar");
    obj2.push("kolkata");
    obj2.push("new delhi");
    obj2.print();
    cout << "popped item : " << obj2.pop() << endl;
    obj2.print();

    return 0;
}