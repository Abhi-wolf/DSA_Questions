#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        int val=this->data;
        if(next!=NULL)
        {
            delete next;
            next=NULL;
        }
        cout<<"Memory free for node with data "<<val<<endl;
    }
};




//  DISPLAY FUNCTION
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}





//  GIVES SIZE OF DOUBLY LINKED LIST
int getLength(Node *head)
{
    Node *p = head;
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}






//  INSERTION AT HEAD
void InsertAtHead(Node *&head, Node *&tail, int x)
{
    //  no nodes are present
    if (head == NULL)
    {
        Node *t = new Node(x);
        head = t;
        tail = t;
    }
    else
    {
        Node *t = new Node(x);
        t->next = head;
        head->prev = t;
        head = t;
    }
}





//  INSERTION AT TAIL
void InsertAtTail(Node *&tail, int x)
{
    //  no nodes are present
    if (tail == NULL)
    {
        Node *t = new Node(x);
        tail = t;
    }
    else
    {
        Node *t = new Node(x);
        t->prev = tail;
        tail->next = t;
        tail = t;
    }
}





//  INSERTION AT DESIRED POSITION
void InsertAtPosition(Node *&head, Node *tail, int index, int x)
{
    Node *t = new Node(x);
    Node *p = head;

    if (index < 0 || index > getLength(head) + 1)
    {
        cout << "Invalid index\n";
        return;
    }

    // before head
    if (index == 1)
    {
        t->next = head;
        head = t;
    }

    else
    {
        for (int i = 1; i < index - 1; i++)
            p = p->next;

        // after last node
        if (p->next == NULL)
        {
            InsertAtTail(tail, x);
            return;
        }

        else
        {
            t->next = p->next;
            t->prev = p;
            p->next->prev = t;
            p->next = t;
        }
    }
}




//  DELETING DESIRED NODE
void DeleteNode(Node *&head, int pos)
{
    //  deletng first Node
    if (pos == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }

    else
    {
        Node *curr=head;
        Node *prev=NULL;

        int count=1;
        while(count<pos)
        {
            prev=curr;
            curr=curr->next;
            count++;
        }

        if(curr->next)      // if next node exit
            curr->next->prev=curr->prev;
        
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}





//  MAIN FUNCTION
int main()
{
    // Node *node1=new Node(10);
    // Node *head=node1;
    // Node *tail=node1;

    Node *head = NULL;
    Node *tail = NULL;

    print(head);
    cout << "Length = " << getLength(head) << endl;

    InsertAtHead(head, tail, 1000);
    InsertAtHead(head, tail, 99);
    print(head);

    InsertAtTail(tail, 1000000);
    print(head);
    cout << "Length = " << getLength(head) << endl;
    InsertAtPosition(head, tail, 1, 12);
    print(head);

    DeleteNode(head,4);
    print(head);

    

    return 0;
}