#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Given the head of a singly linked list where elements are sorted in ascending order, convert it to a
height-balanced
binary search tree.

Example 1:
Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.

Example 2:
Input: head = []
Output: []

Constraints:
    The number of nodes in head is in the range [0, 2 * 104].
    -105 <= Node.val <= 105
*/

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int x)
    {
        this->val = x;
        this->next = NULL;
    }
};

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        this->val = x;
        this->left = this->right = NULL;
    }
};

ListNode *createListFromArray(vector<int> arr)
{
    int n = arr.size();
    if (n == 0)
        return NULL;

    ListNode *head = new ListNode(arr[0]);
    ListNode *p = head;
    int i = 1;
    while (i < n)
    {
        p->next = new ListNode(arr[i++]);
        p = p->next;
    }

    return head;
}

// linked list to height balanced binary tree
TreeNode *makeTree(vector<int> vec, int start, int end)
{
    if (start > end)
        return NULL;

    int mid = start + (end - start) / 2;
    TreeNode *root = new TreeNode(vec[mid]);
    root->left = makeTree(vec, start, mid - 1);
    root->right = makeTree(vec, mid + 1, end);

    return root;
}

TreeNode *sortedListToBST(ListNode *head)
{
    if (head == NULL)
        return NULL;

    vector<int> vec;
    ListNode *p = head;
    while (p)
    {
        vec.push_back(p->val);
        p = p->next;
    }

    TreeNode *root = makeTree(vec, 0, vec.size() - 1);
    return root;
}

void DisplayLinkedList(ListNode *p)
{
    if (p == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    while (p)
    {
        cout << p->val << ", ";
        p = p->next;
    }
    cout << endl;
}

void LevelOrder(TreeNode *p)
{
    if (p == NULL)
    {
        cout << "Tree is empty\n";
        return;
    }
    queue<TreeNode *> que;
    que.push(p);
    que.push(NULL);

    while (!que.empty())
    {
        TreeNode *temp = que.front();
        que.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!que.empty())
            {
                que.push(NULL);
            }
        }

        else
        {
            cout << temp->val << ", ";
            if (temp->left)
                que.push(temp->left);
            if (temp->right)
                que.push(temp->right);
        }
    }
}

int main()
{
    vector<int> arr = {};
    ListNode *head = createListFromArray(arr);
    DisplayLinkedList(head);
    TreeNode *root = sortedListToBST(head);
    LevelOrder(root);
    return 0;
}