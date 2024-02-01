#include <iostream>
#include <queue>
using namespace std;

/*
Given the root of a binary tree, flatten the tree into a "linked list":
    The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
    The "linked list" should be in the same order as a pre-order traversal of the binary tree.

Example 1:
Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [0]
Output: [0]

Constraints:
    The number of nodes in the tree is in the range [0, 2000].
    -100 <= Node.val <= 100

Follow up: Can you flatten the tree in-place (with O(1) extra space)?
*/

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

TreeNode *createTreeFromArray(int arr[], int n)
{
    if (n == 0)
        return NULL;

    TreeNode *root = new TreeNode(arr[0]);
    queue<TreeNode *> que;
    int i = 1;
    que.push(root);
    while (i < n)
    {

        TreeNode *p = que.front();
        que.pop();
        if (arr[i] != -1)
        {
            p->left = new TreeNode(arr[i]);
            que.push(p->left);
        }
        else
        {
            p->left = NULL;
        }

        i++;

        if (i < n)
        {
            if (arr[i] != -1)
            {
                p->right = new TreeNode(arr[i]);
                que.push(p->right);
            }
            else
            {
                p->right = NULL;
            }
            i++;
        }
    }
    return root;
}

void solve(TreeNode *root, TreeNode *&prev)
{
    if (root == NULL)
        return;

    solve(root->right, prev);
    solve(root->left, prev);

    root->right = prev;
    root->left = NULL;
    prev = root;
}
void flatten(TreeNode *root)
{
    if (root == NULL)
        return;

    TreeNode *prev = NULL;
    solve(root, prev);
}

void LevelOrder(TreeNode *root)
{
    queue<TreeNode *> que;
    que.push(root);
    que.push(NULL);

    while (!que.empty())
    {
        TreeNode *p = que.front();
        que.pop();

        if (p == NULL)
        {
            cout << endl;
            if (!que.empty())
                que.push(NULL);
        }

        else
        {
            cout << p->val << ", ";
            if (p->left)
                que.push(p->left);
            if (p->right)
                que.push(p->right);
        }
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 5, 3, 4, -1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    TreeNode *root = createTreeFromArray(arr, n);
    LevelOrder(root);
    flatten(root);
    LevelOrder(root);
    return 0;
}