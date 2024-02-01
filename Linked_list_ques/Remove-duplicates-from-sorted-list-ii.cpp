#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from
the original list. Return the linked list sorted as well.

Example 1:
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Example 2:
Input: head = [1,1,1,2,3]
Output: [2,3]

Constraints:
    The number of nodes in the list is in the range [0, 300].
    -100 <= Node.val <= 100
    The list is guaranteed to be sorted in ascending order.
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


/*  check that if the two adjacent nodes are equal or not if the two adjacent nodes are equal then traverse the linked list 
upto end of the adjacent nodes that are not identical. Then directly connect the link from prev->next to the head->next.
While in other case is the adjacent nodes are not equal then simply traverse the linked list by prev=prev->next.
*/
ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *curr = head, *prev = dummy;

    while (curr != NULL)
    {
        if (curr->next != NULL && curr->val == curr->next->val)
        {
            while (curr->next != NULL && curr->val == curr->next->val)
                curr = curr->next;

            prev->next = curr->next;
        }
        else
        {
            prev = prev->next;
        }
        curr = curr->next;
    }

    return dummy->next;
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
        cout << p->val << ", ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 2, 3, 3, 4, 4, 5};
    // arr = {1, 1, 1, 2, 3};
    // arr = {1, 1};
    ListNode *head = createListFromArray(arr);
    Display(head);
    head = deleteDuplicates(head);
    Display(head);
    return 0;
}