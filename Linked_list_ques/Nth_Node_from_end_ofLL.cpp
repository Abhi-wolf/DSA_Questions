#include <iostream>
using namespace std;

/*  Given a linked list consisting of L nodes and given a number N.The task is to find the
            Nth node from the end of the linked list.
    The task is to complete the function getNthFromLast() which takes two arguments: reference to
    head and N and you need to return Nth from the end or -1 in case node doesn't exist..


Input:
    N = 2
    LinkedList: 1->2->3->4->5->6->7->8->9
Output: 8
Explanation: In the first example, there
    are 9 nodes in linked list and we need
    to find 2nd node from end. 2nd node
    from end os 8.
*/

class Node
{
public:
    int data;
    struct Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

//  Insertion at the front
void InsertAtHead(Node *&head, Node *&tail, int x)
{
    Node *t = new Node(x);

    if (head == NULL)
    {
        head = t;
        tail = t;
    }
    else
    {
        t->next = head;
        head = t;
    }
}

//  Insertion at the end
void InsertAtTail(Node *&head, Node *&tail, int x)
{
    Node *t = new Node(x);

    if (tail == NULL)
    {
        head = tail = t;
    }

    else
    {
        tail->next = t;
        tail = t;
    }
}

//  Display node of linked list
void Display(Node *head)
{
    Node *p = head;
    if (p == NULL)
        cout << "List empty\n";
    else
    {
        while (p != NULL)
        {
            cout << p->data << "  ";
            p = p->next;
        }
        cout << endl;
    }
}

//  Count no of nodes
int getLength(Node *head)
{
    Node *p = head;
    int len = 0;
    while (p != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

//  function to find nth node from last
int getNthFromLast(Node *head, int n)
{
    Node *t = head;
    int len = getLength(head);

    // if n is greater than the size of linked list
    if (n > len)
        return -1;

    else
    {
        //  no of node from first
        int x = (len - n) + 1;
        int i = 1;
        while (i < x)
        {
            t = t->next;
            i++;
        }
        return t->data;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    InsertAtHead(head, tail, 2);
    InsertAtHead(head, tail, 1);
    InsertAtTail(head, tail, 3);
    InsertAtTail(head, tail, 4);
    InsertAtTail(head, tail, 5);
    InsertAtTail(head, tail, 6);
    InsertAtTail(head, tail, 7);
    InsertAtTail(head, tail, 8);
    InsertAtTail(head, tail, 9);

    Display(head);

    cout << "Length = " << getLength(head) << endl;
    cout << "Data on 6 Node from last = " << getNthFromLast(head, 6) << endl;

    return 0;
}