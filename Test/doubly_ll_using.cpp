#include <iostream>
using namespace std;

// Define a struct to represent each node in the linked list
// struct node {
//   int data;
//   node *next;
//   node *prev;
// };

//  OR
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int x)
    {
        this->data = x;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Define a class to represent the linked list itself
class linkedlist
{
private:
    node *head;

public:
    linkedlist()
    {
        head = NULL;
    }
    void insert(int key);
    int Delete(int key);
    void display();
    void reverse();
};

//    ADDING NEW ITEM IN HEAD
void linkedlist::insert(int key)
{
    node *t = new node(key);
    if (head == NULL)
    {
        t->next = head;
        head = t;
    }

    else
    {
        t->next = head;
        head->prev = t;
        head = t;
    }
}

int linkedlist::Delete(int key)
{
    node *p = NULL;
    node *curr = head;

    int x = -1;
    while (curr != NULL && curr->data != key)
    {
        p = curr;
        curr = curr->next;
    }

    if (curr != NULL)
    {
        x = curr->data;
        if (p != NULL)
        {
            p->next = curr->next;
            curr->next->prev = p;
        }
        else
        {
            head = curr->next;
            head->prev = NULL;
        }
        delete curr;
    }
    return x;
}

void linkedlist::display()
{
    node *p = head;
    if (p == NULL)
        cout << "empty\n";
    else
    {
        while (p != NULL)
        {
            cout << p->data << "  ";
            p = p->next;
        }
    }
    cout << endl;
}

void linkedlist::reverse()
{
    node *p, *q, *r;
    p = head;
    q = r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}

int main()
{
    linkedlist obj;
    obj.insert(10);
    obj.insert(20);
    obj.insert(50);
    obj.insert(30);
    obj.insert(80);

    obj.display();

    // int ans=obj.Delete(10);
    // cout<<"deleted item is "<<ans<<endl;
    // obj.display();

    // ans=obj.Delete(40);
    // cout<<"deleted item is "<<ans<<endl;
    // obj.display();

    // obj.reverse();
    // obj.display();
}