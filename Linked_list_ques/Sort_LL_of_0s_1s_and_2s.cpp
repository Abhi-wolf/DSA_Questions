#include <iostream>
using namespace std;

//          Given a linked list of 0s, 1s and 2s, sort it.
//  https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1?page=2&category[]=Linked%20List&sortBy=submissions

/*
    Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to
    segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of
    the linked list, and 1s in the mid of 0s and 2s.


    Input:
    N = 8
    value[] = {1,2,2,1,2,0,2,2}
    Output: 0 1 1 2 2 2 2 2 
    Explanation: All the 0s are segregated
    to the left end of the linked list,
    2s to the right end of the list, and
    1s in between.
*/




class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

// function to insert at tail
void InsertAtTail(Node *&head, Node *&tail, int x)
{
    Node *t = new Node(x);
    // empty list
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

//  display function
void Display(Node *head)
{
    Node *t = head;

    if (head == NULL)
    {
        cout << "List empty \n";
        return;
    }

    while (t != NULL)
    {
        cout << t->data << "  ";
        t = t->next;
    }
    cout << endl;
}

//          FIRST APPROACH
Node *segregate1(Node *head)
{
    //  creating three LL one head for zero's one for one's and one for two's
    // and creating dummy nodes(first node) for all three LL
    Node *zerohead = new Node(-1);
    Node *zeroTail = zerohead;

    Node *onehead = new Node(-1);
    Node *oneTail = onehead;

    Node *twohead = new Node(-1);
    Node *twoTail = twohead;

    Node *p = head;

    while (p)
    {
        // if p's data is 0 insert in zero's LL
        if (p->data == 0)
        {
            InsertAtTail(zerohead, zeroTail, p->data);
        }

        // if p's data is 2 insert in zero's LL
        else if (p->data == 2)
        {
            InsertAtTail(twohead, twoTail, p->data);
        }

        // if p's data is 1 insert in zero's LL
        else
        {
            InsertAtTail(onehead, oneTail, p->data);
        }
        p = p->next;
    }

    // if there's no one's in LL
    if (onehead->next != NULL)
    {
        zeroTail->next = onehead->next;
    }

    // one's LL in present
    else
    {
        zeroTail->next = twohead->next;
    }

    oneTail->next = twohead->next;
    twoTail->next = NULL;

    // removeing dummy node
    head = zerohead->next;

    delete zerohead;
    delete onehead;
    delete twohead;

    return head;
}

//           SECOND APPROACH
// Counting number of 0's , 1's and 2's in the LL
//  then creating a new LL and inserting 0's first then 1's and 2's
Node *segregate2(Node *head)
{
    Node *p = head;
    int czero = 0;
    int cone = 0;
    int ctwo = 0;

    while (p != NULL)
    {
        if (p->data == 0)
            czero++;
        else if (p->data == 1)
            cone++;
        else
            ctwo++;
        p = p->next;
    }

    cout << czero << " " << cone << " " << ctwo << endl;

    Node *ansHead = new Node(-1);
    Node *ansTail = ansHead;

    while (czero--)
    {
        Node *t = new Node(0);
        ansTail->next = t;
        ansTail = t;
    }

    while (cone--)
    {
        Node *t = new Node(1);
        ansTail->next = t;
        ansTail = t;
    }

    while (ctwo--)
    {
        Node *t = new Node(2);
        ansTail->next = t;
        ansTail = t;
    }
    ansHead = ansHead->next;
    return ansHead;
}

int main()
{
    Node *head1 = NULL;
    Node *tail1 = NULL;

    InsertAtTail(head1, tail1, 1);
    InsertAtTail(head1, tail1, 1);
    InsertAtTail(head1, tail1, 0);
    InsertAtTail(head1, tail1, 2);
    InsertAtTail(head1, tail1, 1);
    InsertAtTail(head1, tail1, 0);
    InsertAtTail(head1, tail1, 2);
    InsertAtTail(head1, tail1, 2);

    Display(head1);

    Node *ans = segregate2(head1);

    Display(ans);

    return 0;
}