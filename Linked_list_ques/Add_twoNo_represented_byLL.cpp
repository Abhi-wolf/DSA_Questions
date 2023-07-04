#include <iostream>
using namespace std;

/*
    Given two decimal numbers represented by two linked lists of size N and M respectively.
    The task is to return a linked list that represents the sum of these two numbers.
    For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly
    25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null.
     You are required to return the head of the linked list 2->1->5->null.


    Input:
    N = 2
    valueN[] = {4,5}
    M = 3
    valueM[] = {3,4,5}
    Output: 3 9 0
    Explanation: For the given two linked
    list (4 5) and (3 4 5), after adding
    the two linked list resultant linked
    list will be (3 9 0).
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

Node *Reverse(Node *head)
{
    Node *p = head;
    Node *q = NULL;
    Node *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    return q;
}

Node *add(Node *first, Node *second)
{
    int carry = 0;
    Node *ansHead = NULL;
    Node *ansTail = NULL;

    while (first != NULL || second != NULL || carry != 0)
    {
        int val1 = 0;
        if (first != NULL)
            val1 = first->data;

        int val2 = 0;
        if (second)
            val2 = second->data;

        // calculates sum of last members of the given numbers
        int sum = carry + val1 + val2;

        // stores the remainder that is to be stored in LL
        int digit = sum % 10;

        // inserts the remainder in LL
        InsertAtTail(ansHead, ansTail, digit);

        // calculates carry(hasil) to carry forward
        carry = sum / 10;

        if (first)
            first = first->next;

        if (second)
            second = second->next;
    }
    return ansHead;
}

//  function to add two numbers represented by linked list
Node *Add_two_LL(Node *first, Node *second)
{
    // step 1 - reverse input LL
    first = Reverse(first);
    second = Reverse(second);

    // step 2 - add two LL
    Node *ans = add(first, second);

    // step 3 - reverse ans to print
    ans = Reverse(ans);

    return ans;
}

int main()
{
    Node *head1 = NULL;
    Node *tail1 = NULL;

    Node *head2 = NULL;
    Node *tail2 = NULL;

    InsertAtTail(head1, tail1, 3);
    InsertAtTail(head1, tail1, 4);
    InsertAtTail(head1, tail1, 4);

    InsertAtTail(head2, tail2, 4);
    InsertAtTail(head2, tail2, 5);
    InsertAtTail(head2, tail2, 8);

    Display(head1);
    Display(head2);

    Node *a = Add_two_LL(head1, head2);

    Display(a);

    return 0;
}