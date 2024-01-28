#include <iostream>
#include <vector>
using namespace std;

/*
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values 
in the list's nodes (i.e., only nodes themselves may be changed.)

Example 1:
Input: head = [1,2,3,4]
Output: [2,1,4,3]

Example 2:
Input: head = []
Output: []

Example 3:
Input: head = [1]
Output: [1]

Constraints:
    The number of nodes in the list is in the range [0, 100].
    0 <= Node.val <= 100

*/

class Node
{
public:
    int val;
    Node *next;
    Node(int x)
    {
        this->val = x;
        this->next = NULL;
    }
};

Node *createLLFromArray(vector<int> arr, int n)
{
    if (n == 0)
        return NULL;
    int i = 0;
    Node *head = new Node(arr[i++]);
    Node *p = head;
    while (i < n)
    {
        Node *t = new Node(arr[i++]);
        p->next = t;
        p = p->next;
    }

    return head;
}

Node *swapPairs(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *newHead = new Node(0);
    newHead->next = head;

    Node *r, *q, *p;
    r = newHead;
    q = head;
    p = head->next;

    while (q->next)
    {
        q->next = p->next;
        p->next = q;
        r->next = p;

        r = q;
        if (q->next)
            q = q->next;

        if (q->next)
            p = q->next;
    }

    return newHead->next;
}

void Display(Node *p)
{
    cout << "\nLinked List = ";
    while (p)
    {
        cout << p->val << ", ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    Node *head = createLLFromArray(arr, n);
    Display(head);
    head = swapPairs(head);
    Display(head);
    return 0;
}