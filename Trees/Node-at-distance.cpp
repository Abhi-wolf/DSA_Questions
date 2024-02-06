#include <iostream>
#include <queue>
#include <queue>
using namespace std;
int c = 0;

/* Given a binary tree with n nodes and a non-negative integer k, the task is to count the number of special nodes.
A node is considered special if there exists at least one leaf in its subtree such that the distance between the node
and leaf is exactly k.

Note: Any such node should be counted only once. For example, if a node is at a distance k from 2 or more leaf nodes,
then it would add only 1 to our count.

Example 1:
Input:
Binary tree
        1
      /   \
     2     3
   /  \   /  \
  4   5  6    7
          \
          8
k = 2
Output: 2
Explanation:
There are only two unique nodes that are at a distance of 2 units from the leaf node. (node 3 for leaf with value 8 and node 1
for leaves with values 4, 5 and 7) Note that node 2 isn't considered for leaf with value 8 because it isn't a direct ancestor
of node 8.

Example 2:
Input:
Binary tree
          1
         /
        3
       /
      5
    /  \
   7    8
         \
          9
k = 4
Output: 1
Explanation:
Only one node is there which is at a distance of 4 units from the leaf node.(node 1 for leaf with value 9)

Your Task:
You don't have to read input or print anything. Complete the function printKDistantFromLeaf() that takes root node and k as
inputs and returns the number of nodes that are at distance k from a leaf node.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= n <= 105
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

// ans

bool check(TreeNode *root, int k, int x)
{
    if (!root)
        return false;

    if (k == x)
    {
        if (!root->left && !root->right)
            return true;

        return false;
    }

    return check(root->left, k, x + 1) || check(root->right, k, x + 1);
}

void solve(TreeNode *root, int k)
{
    if (!root)
        return;

    if (check(root, k, 0))
        c++;

    solve(root->left, k);
    solve(root->right, k);
}

// Function to return count of nodes at a given distance from leaf nodes.
// FIRST METHOD
int printKDistantFromLeaf(TreeNode *root, int k)
{
    if (!root)
        return 0;
    solve(root, k);
    return c;
}

// SECOND METHOD
int printKDistantFromLeaf2(TreeNode *root, int k)
{
    if (!root)
        return 0;

    queue<TreeNode *> que;
    que.push(root);
    int res = 0;

    while (!que.empty())
    {
        TreeNode *p = que.front();
        que.pop();

        if (check(p, k, 0))
            res++;

        if (p->left)
            que.push(p->left);
        if (p->right)
            que.push(p->right);
    }
    return res;
}

int main()
{
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, -1, -1, -1, -1, -1, 8};
    int arr[] = {1, 3, -1, 5, -1, 7, 8, -1, -1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    TreeNode *root = createTreeFromArray(arr, n);
    LevelOrder(root);
    int ans = printKDistantFromLeaf(root, 4);
    cout << "First Method ans = " << ans << endl;

    ans = printKDistantFromLeaf2(root, 4);
    cout << "Second Method ans = " << ans << endl;
    return 0;
}