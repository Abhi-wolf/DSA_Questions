#include <iostream>
#include <vector>
using namespace std;

/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []

Constraints:
    k == lists.length
    0 <= k <= 104
    0 <= lists[i].length <= 500
    -104 <= lists[i][j] <= 104
    lists[i] is sorted in ascending order.
    The sum of lists[i].length will not exceed 104.
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

Node *mergeTwoLists(Node *list1, Node *list2)
{
    if (list1 == NULL && list2 == NULL)
        return NULL;
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    Node *head = new Node(0);
    Node *p = head;

    while (list1 && list2)
    {
        if (list1->val <= list2->val)
        {
            p->next = list1;
            p = p->next;
            list1 = list1->next;
        }

        else
        {
            p->next = list2;
            p = p->next;
            list2 = list2->next;
        }
    }

    if (list1)
        p->next = list1;
    if (list2)
        p->next = list2;

    return head->next;
}

// FIRST METHOD
Node *mergeKLists(vector<Node *> arr)
{
    Node *ans = NULL;
    for (int i = 0; i < arr.size(); i++)
    {
        ans = mergeTwoLists(ans, arr[i]);
    }
    return ans;
}

// SECOND METHOD (best)
Node *mergeSort(vector<Node *> arr, int start, int end)
{
    if (start == end)
        return arr[start];

    if (start + 1 == end)
        return mergeTwoLists(arr[start], arr[end]);

    int mid = start + (end - start) / 2;

    Node *left = mergeSort(arr, start, mid);
    Node *right = mergeSort(arr, mid + 1, end);

    return mergeTwoLists(left, right);
}

Node *mergeKLists2(vector<Node *> arr)
{
    if (arr.size() == 0)
        return NULL;

    return mergeSort(arr, 0, arr.size() - 1);
}

// PRINT FUNCTION
void Print(Node *root)
{
    Node *p = root;
    while (p)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    vector<Node *> lists;
    vector<vector<int>> arr = {{1, 4, 5},
                               {1, 3, 4},
                               {0, 2, 6, 9, 10, 11, 19},
                               {100, 200, 300}};

    for (int i = 0; i < arr.size(); i++)
    {
        int n = arr[i].size();
        Node *p = createLLFromArray(arr[i], n);
        lists.push_back(p);
    }

    Node *head = mergeKLists2(lists);
    Print(head);
    return 0;
}