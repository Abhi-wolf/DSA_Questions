#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
You are given the head of a linked list.
Remove every node which has a node with a greater value anywhere to the right
side of it.
Return the head of the modified linked list.

Example 1:
Input: head = [5,2,13,3,8]
Output: [13,8]
Explanation: The nodes that should be removed are 5, 2 and 3.
- Node 13 is to the right of node 5.
- Node 13 is to the right of node 2.
- Node 8 is to the right of node 3.

Example 2:
Input: head = [1,1,1,1]
Output: [1,1,1,1]
Explanation: Every node has value 1, so no nodes are removed.

Constraints:
    The number of the nodes in the given list is in the range [1, 105].
    1 <= Node.val <= 105
*/

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode()
    {
        this->val = 0;
        this->next = NULL;
    }

    ListNode(int x)
    {
        this->val = x;
        this->next = NULL;
    }
};

ListNode *ReverseLL(ListNode *head)
{
    ListNode *p = head, *q = NULL, *r = NULL;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    return q;
}

// FIRST METHOD
ListNode *removeNodes(ListNode *head)
{
    if (head == NULL)
        return NULL;

    stack<ListNode *> stk;
    ListNode *p = head;

    while (p)
    {
        while (!stk.empty() && p->val > stk.top()->val)
            stk.pop();

        stk.push(p);
        p = p->next;
    }

    ListNode *newDummyHead = new ListNode(-1);
    p = newDummyHead;

    while (!stk.empty())
    {
        p->next = stk.top();
        p = p->next;
        p->next = NULL;
        stk.pop();
    }

    newDummyHead->next = ReverseLL(newDummyHead->next);
    return newDummyHead->next;
}

ListNode *createListFromArray(vector<int> arr)
{
    int n = arr.size(), i = 0;
    if (n == 0)
        return NULL;

    ListNode *head = new ListNode(arr[i++]);
    ListNode *p = head;

    while (i < n)
    {
        ListNode *temp = new ListNode(arr[i++]);
        p->next = temp;
        p = p->next;
    }

    return head;
}

void Display(ListNode *p)
{
    if (p == NULL)
    {
        cout << "No data \n";
        return;
    }
    while (p)
    {
        cout << p->val << " -> ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {5, 2, 13, 3, 8};
    // arr = {1, 1, 1, 1};
    ListNode *head = createListFromArray(arr);
    Display(head);
    head = removeNodes(head);
    Display(head);
    return 0;
}