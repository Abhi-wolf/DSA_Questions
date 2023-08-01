#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
};

Node *Insert(Node *head, int num)
{
    Node *temp = new Node(num);
    Node *p = head;
    if (head == NULL)
    {
        head = temp;
        return head;
    }

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
    return head;
}

void print(Node *p)
{
    while (p)
    {
        cout << p->data << "    ";
        p = p->next;
    }
    cout << endl;
}

//  iterative approach
Node *Reverse(Node *head, int k)
{
    Node *p = head;
    Node *q, *r;
    q = r = NULL;

    while (p != NULL && k--)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    return q;
}

int size(Node *head)
{
    int n = 0;
    while (head)
    {
        n++;
        head = head->next;
    }
    return n;
}

Node *reverse_every_k_node(Node *head, int k)
{
    int n = size(head);
    int noOfTimes = 0;
    if (n % k == 0)
        noOfTimes = n / k;
    else
        noOfTimes = (n / k) + 1;

    cout << "size = " << n << " noOf = " << noOfTimes << endl;
    int x = k;
    Node *prev, *curr, *temp;
    prev = curr = temp = head;
    while (noOfTimes--)
    {
        while (x-- && temp)
        {
            temp = temp->next;
        }

        if (curr == head)
        {
            head = Reverse(curr, k);
            print(head);
        }
        else
        {
            prev->next = Reverse(curr, k);
            prev = curr;
        }
        curr = temp;
        x = k;
    }
    return head;
}

//  recursive approach
Node *reverse_after_every_k_node(Node *head, int k)
{
    int count = 0;
    Node *prev, *curr, *nextPtr;
    prev = NULL;
    curr = head;
    nextPtr = NULL;

    while (curr != NULL && count < k)
    {
        nextPtr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextPtr;
        count++;
    }

    if (nextPtr != NULL)
        head->next = reverse_after_every_k_node(nextPtr, k);

    return prev;
}

int main()
{
    Node *head = NULL;
    head = Insert(head, 1);
    Insert(head, 2);
    Insert(head, 3);
    Insert(head, 4);
    Insert(head, 5);
    Insert(head, 6);

    print(head);
    // head = Reverse(head);
    // head = reverse_every_k_node(head, 4);
    head = reverse_after_every_k_node(head, 9);
    print(head);
    return 0;
}