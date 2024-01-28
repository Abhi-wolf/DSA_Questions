#include <iostream>
using namespace std;

/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]

Constraints:
    The number of nodes in the list is sz.
    1 <= sz <= 30
    0 <= Node.val <= 100
    1 <= n <= sz
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

Node *createLLFromArray(int arr[], int n)
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

// FIRST METHOD
Node *removeKthFromEnd(Node *head, int k)
{
    if (head == NULL)
        return NULL;

    int len = 0;
    Node *p = head;
    while (p)
    {
        len++;
        p = p->next;
    }

    if (len == k)
        return head->next;
    if (k > len)
        return head;

    p = head;
    int fromFirst = len - k - 1;
    while (fromFirst--)
        p = p->next;

    if (p->next)
        p->next = p->next->next;

    else
        p->next = NULL;

    return head;
}

// SECOND METHOD (fast and slow pointer)
Node *removeKthFromEnd2(Node *head, int k)
{
    Node *fast = head, *slow = head;

    for (int i = 0; i < k; i++)
        fast = fast->next;

    if (!fast)
        return head->next;

    while (fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;
    return head;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *head = createLLFromArray(arr, n);
    Display(head);
    head = removeKthFromEnd(head, 6);
    Display(head);
    // head = removeKthFromEnd2(head, 3);
    // Display(head);
    return 0;
}