#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/* Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously
following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is
connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.

Example 2:
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.

Example 3:
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.

Constraints:
    The number of the nodes in the list is in the range [0, 104].
    -105 <= Node.val <= 105
    pos is -1 or a valid index in the linked-list.
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

// FIRST METHOD
ListNode *detectCycle(ListNode *head)
{
    if (head == NULL)
        return NULL;
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (!(fast && fast->next))
        return NULL;

    while (head != slow)
    {
        head = head->next;
        slow = slow->next;
    }
    return head;
}

// SECOND METHOD
ListNode *detectCycle2(ListNode *head)
{
    if (head == NULL)
        return NULL;

    unordered_set<ListNode *> ust;
    ListNode *p = head;

    while (p)
    {
        if (ust.count(p))
            return p;

        else
            ust.insert(p);

        p = p->next;
    }
    return NULL;
}

void makeCycle(ListNode *head, ListNode *tail, int k)
{
    ListNode *p = head;
    while (k > 0)
    {
        p = p->next;
        k--;
    }

    tail->next = p;
}

ListNode *createListFromArray(vector<int> arr, int k)
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
    makeCycle(head, p, k - 1);
    return head;
}

bool isCyclePresent(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    return false;
}

int main()
{
    vector<int> arr = {3, 2, 0, -4};
    ListNode *head = createListFromArray(arr, 3);
    if (isCyclePresent(head))
        cout << "Yes cycle present\n";
    else
        cout << "Cycle not present\n";

    ListNode *cycleEndNode = detectCycle(head);
    cout << cycleEndNode->val << endl;

    ListNode *cycleEndNode2 = detectCycle2(head);
    cout << cycleEndNode2->val << endl;

    return 0;
}