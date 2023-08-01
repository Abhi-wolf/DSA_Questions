#include <iostream>
using namespace std;
/*
    Given two linked lists, your task is to complete the function mergeList() which inserts nodes
    of second list into first list at alternate positions of first list. The lists are given in the
    reverse order.
*/
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

void insert(Node **head, int num)
{
    Node *temp = new Node(num);
    if (*head == NULL)
    {
        *head = temp;
    }
    else
    {
        temp->next = *head;
        *head = temp;
    }
}

void print(Node *p)
{
    cout << endl;
    while (p != NULL)
    {
        cout << p->data << "    ";
        p = p->next;
    }
    cout << endl;
}

void reverse(Node **root)
{
    Node *p, *q, *r;
    p = *root;
    q = r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    *root = q;
}

void merge(Node **h1, Node **h2)
{
    Node *fir, *sec, *temp1, *temp2;
    temp1 = fir = *h1;
    temp2 = sec = *h2;
    while (temp1 && temp2)
    {
        temp1 = temp1->next;
        fir->next = sec;
        temp2 = temp2->next;

        if (temp1 == NULL)
        {
            sec->next = NULL;
        }
        else
        {
            sec->next = temp1;
        }
        if (temp1)
            fir = temp1;
        else
            break;

        if (temp2)
            sec = temp2;
    }
    *h2 = temp2;
}

int main()
{
    Node *head = NULL;
    insert(&head, 50);
    insert(&head, 6);
    // insert(&head, 7);
    // insert(&head, 8);
    // insert(&head, 9);
    print(head);

    Node *head2 = NULL;
    insert(&head2, 1);
    insert(&head2, 2);
    insert(&head2, 3);
    insert(&head2, 4);
    insert(&head2, 5);
    print(head2);

    merge(&head, &head2);
    print(head);
    // print(head2);
    return 0;
}