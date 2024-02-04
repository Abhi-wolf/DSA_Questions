#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/* You are given two linked lists that represent two large positive numbers. From the two numbers represented by the linked lists,
subtract the smaller number from the larger one. Look at the examples to get a better understanding of the task.

Example 1:
Input:
L1 = 1->0->0
L2 = 1->2
Output: 88
Explanation:
First linked list represents 100 and the
second one represents 12. 12 subtracted from 100
gives us 88 as the result. It is represented
as 8->8 in the linked list.

Example 2:
Input:
L1 = 0->0->6->3
L2 = 7->1->0
Output: 647
Explanation:
First linked list represents 0063 => 63 and
the second one represents 710. 63 subtracted
from 710 gives us 647 as the result. It is
represented as 6->4->7 in the linked list.

Your Task:
You do not have to take any input or print anything. The task is to complete the function subLinkedList() that takes heads of
two linked lists as input parameters and which should subtract the smaller number from the larger one represented by the given
linked lists and return the head of the linked list representing the result.

n and m are the length of the two linked lists respectively.
Expected Time Complexity:  O(n+m)
Expected Auxiliary Space: O(n+m)

Constraints:
1 <= n <= 10000
0 <= values represented by the linked lists < 10n
0 <= values represented by the linked lists < 10m
 */

class Node
{
public:
    int val;
    Node *next;

    Node()
    {
        this->val = 0;
        this->next = NULL;
    }

    Node(int x)
    {
        this->val = x;
        this->next = NULL;
    }
};

Node *createListFromArray(string arr);
void DisplayLL(Node *p);
int Length(Node *p);
Node *Reverse(Node *p);

bool findLargestLL(Node *h1, Node *h2)
{
    Node *p = h1, *q = h2;
    while (p && q)
    {
        if (p->val < q->val)
        {
            cout << p->val << ", " << q->val << endl;
            return true;
        }

        else if (p->val > q->val)
            return false;
        p = p->next;
        q = q->next;
    }
    return false;
}

// ANSWER
Node *subLinkedList(Node *head1, Node *head2)
{
    while (head1 && head1->val == 0)
        head1 = head1->next;
    while (head2 && head2->val == 0)
        head2 = head2->next;

    if (head1 == NULL && head2 == NULL)
    {
        Node *p = new Node(0);
        return p;
    }
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    int len1 = Length(head1);
    int len2 = Length(head2);

    cout << "head1 = ";
    DisplayLL(head1);
    cout << "head2 = ";
    DisplayLL(head2);

    if (len2 > len1)
    {
        Node *temp = head1;
        head1 = head2;
        head2 = temp;
    }

    else if (len1 == len2)
    {
        if (findLargestLL(head1, head2))
        {
            Node *temp = head1;
            head1 = head2;
            head2 = temp;
            cout << "found\n";
        }
    }

    cout << "head1 = ";
    DisplayLL(head1);
    cout << "head2 = ";
    DisplayLL(head2);

    head1 = Reverse(head1);
    head2 = Reverse(head2);

    // cout << "\nhead1 = ";
    // DisplayLL(head1);
    // cout << "head2 = ";
    // DisplayLL(head2);

    Node *newDummyHead = new Node(0);
    Node *p = newDummyHead;
    Node *fir = head1;
    Node *sec = head2;
    int hasil = 0;

    while (fir && sec)
    {
        int res = 0;
        if (fir->val < sec->val)
        {
            res = fir->val + 10 - sec->val;
            fir->next->val -= 1;
            cout << fir->val << ", " << sec->val << ", res = " << res << endl;
        }

        else
        {
            res = fir->val - sec->val;
        }

        p->next = new Node(res);
        p = p->next;
        fir = fir->next;
        sec = sec->next;
    }

    while (fir)
    {
        if (fir->val < 0)
        {
            fir->val += 10;
            fir->next->val -= 1;
        }
        p->next = fir;
        fir = fir->next;
        p = p->next;
    }

    while (sec)
        p->next = sec;

    newDummyHead->next = Reverse(newDummyHead->next);

    while (newDummyHead->next && newDummyHead->next->val == 0)
        newDummyHead = newDummyHead->next;

    DisplayLL(newDummyHead->next);

    if (newDummyHead->next)
        return newDummyHead->next;
    else
    {
        Node *p = new Node(0);
        return p;
    }
}

int main()
{
    vector<int> arr1 = {0, 0, 0, 0};
    vector<int> arr2 = {0, 0};

    string str1 = "020055383525634518999521060086463321841";
    string str2 = "10835173613544430215114275094755963004";

    Node *root1 = createListFromArray(str1);
    Node *root2 = createListFromArray(str2);
    // DisplayLL(root1);
    // DisplayLL(root2);

    Node *newRoot = subLinkedList(root1, root2);
    return 0;
}

Node *createListFromArray(string arr)
{
    int n = arr.size(), i = 0;
    if (n == 0)
        return NULL;

    Node *head = new Node(arr[i] - '0');
    Node *p = head;
    i++;
    while (i < n)
    {
        Node *temp = new Node(arr[i] - '0');
        p->next = temp;
        p = p->next;
        i++;
    }
    return head;
}

void DisplayLL(Node *p)
{
    if (p == NULL)
    {
        cout << "No data present\n";
        return;
    }

    while (p)
    {
        cout << p->val << ", ";
        p = p->next;
    }
    cout << endl;
}

int Length(Node *p)
{
    int cou = 0;
    while (p)
    {
        cou++;
        p = p->next;
    }
    return cou;
}

Node *Reverse(Node *p)
{
    Node *q = NULL, *r = NULL;

    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    return q;
}