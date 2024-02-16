#include <iostream>
#include <queue>
using namespace std;

/* You are given a Binary Search Tree (BST) with n nodes, each node has a distinct value assigned to it. The goal is to flatten the
tree such that, the left child of each element points to nothing (NULL), and the right child points to the next element in the sorted
 list of elements of the BST (look at the examples for clarity). You must accomplish this without using any extra storage, except for
  recursive calls, which are allowed.
Note: If your BST does have a left child, then the system will print a -1 and will skip it, resulting in an incorrect solution.

Example 1:
Input:
          5
        /    \
       3      7
      /  \    /   \
     2   4  6     8
Output: 2 3 4 5 6 7 8
Explanation:
After flattening, the tree looks
like this
    2
     \
      3
       \
        4
         \
          5
           \
            6
             \
              7
               \
                8
Here, left of each node points
to NULL and right contains the
next node.

Example 2:
Input:
       5
        \
         8
       /   \
      7     9
Output: 5 7 8 9
Explanation:
After flattening, the tree looks like this:
   5
    \
     7
      \
       8
        \
         9

Your Task:
You don't need to read input or print anything. Your task is to complete the function flattenBST() which takes root node of the BST
as input parameter and returns the root node after transforming the tree.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= Number of nodes <= 103
1 <= Data of a node <= 105
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

void Inorder(TreeNode *root, vector<int> &vec)
{
    if (root == NULL)
        return;
    Inorder(root->left, vec);
    vec.push_back(root->val);
    Inorder(root->right, vec);
}

void solve2(TreeNode *root, vector<int> vec, int ind)
{
    if (ind == vec.size())
        return;

    root->left = NULL;
    root->right = new TreeNode(vec[ind]);
    solve2(root->right, vec, ind + 1);
}

TreeNode *flattenBST(TreeNode *root)
{
    if (root == NULL)
        return NULL;

    vector<int> vec;
    Inorder(root, vec);
    TreeNode *newRoot = new TreeNode(-1);
    TreeNode *p = newRoot;

    solve2(newRoot, vec, 0);
    return newRoot->right;
}

void Inorder(TreeNode *curr, TreeNode *&prev)
{
    if (curr == NULL)
        return;
    Inorder(curr->left, prev);
    prev->left = NULL;
    prev->right = curr;
    prev = curr;
    Inorder(curr->right, prev);
}

TreeNode *flattenBST2(TreeNode *root)
{
    if (root == NULL)
        return NULL;

    TreeNode *dummy = new TreeNode(-1);
    TreeNode *prev = dummy;

    Inorder(root, prev);
    prev->left = NULL;
    prev->right = NULL;

    root = dummy->right;
    delete dummy;

    return root;
}

int main()
{
    int arr[] = {5, 3, 7, 2, 4, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    TreeNode *root = createTreeFromArray(arr, n);
    LevelOrder(root);
    TreeNode *r1 = flattenBST(root);
    LevelOrder(r1);
    TreeNode *r2 = flattenBST2(root);
    LevelOrder(r2);
    return 0;
}