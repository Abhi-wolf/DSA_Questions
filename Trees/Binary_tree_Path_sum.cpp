#include <iostream>
using namespace std;

/*              LEETCODE
    Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path 
    such that adding up all the values along the path equals targetSum.
    A leaf is a node with no children.
*/

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int x)
    {
        this->val = x;
        this->left = this->right = NULL;
    }
};

Node *Insert(Node *root)
{
    int x;
    cout << "Enter data = ";
    cin >> x;

    if (x == -1)
    {
        return NULL;
    }

    root = new Node(x);
    // return root;

    cout << "Enter data in left node of " << x << endl;
    root->left = Insert(root->left);
    cout << "Enter data in right node of " << x << endl;
    root->right = Insert(root->right);

    return root;
}

void Inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    Inorder(root->left);
    cout << root->val << ",  ";
    Inorder(root->right);
}

void Preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val << ",  ";
    Preorder(root->left);
    Preorder(root->right);
}

//  FIRST METHOD
bool hasPathSum_1(Node *root, int target)
{
    if (!root)
    {
        return false;
    }

    if (root->left == NULL && root->right == NULL && target - root->val == 0)
        return true;

    bool fir = hasPathSum_1(root->left, target - root->val);
    bool sec = hasPathSum_1(root->right, target - root->val);

    return fir || sec;
}

// SECOND METHOD
bool flag = true;
void helper_1(Node *root, int target, int sum)
{
    // base case
    if (root == NULL)
        return;

    sum += root->val;

    if (root->left == NULL && root->right == NULL && target == sum)
        flag = true;

    else
    {
        helper_1(root->left, target, sum);
        helper_1(root->right, target, sum);
    }
}

bool hasPathSum_2(Node *root, int target)
{
    helper_1(root, target, 0);
    if (flag == true)
        return true;
    else
        return false;
}

// THIRD METHOD
bool helper_2(Node *root, int target, int sum)
{
    // base case
    if (root == NULL)
        return false;

    if (root->left == NULL && root->right == NULL)
    {
        sum += root->val;
        if (target == sum)
            flag = true;
    }

    return helper_2(root->left, target, sum += root->val) || helper_2(root->right, target, sum += root->val);
}

bool hasPathSum_3(Node *root, int target)
{
    int sum=0;
    return helper_2(root, target, sum);
}

int main()
{
    Node *root = NULL;
    root = Insert(root);
    cout << "Inorder = ";
    Inorder(root);
    cout << "\nPreorder =";
    Preorder(root);

    cout << "\n\nfirst = " << hasPathSum_1(root, -5) << endl;
    cout << "second = " << hasPathSum_2(root, -5) << endl;
    cout << "third = " << hasPathSum_3(root, -5) << endl;

    return 0;
}