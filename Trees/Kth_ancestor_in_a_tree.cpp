#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

/*
    Given a binary tree of size  N, a node, and a positive integer k., Your task is to complete the function kthAncestor(),
    the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor
    then return -1.
    Note: It is guaranteed that the node exists in the tree.
*/

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

Node *buildTree(Node *root)
{
    int num;
    cout << "Enter num = ";
    cin >> num;

    if (num == -1)
        return NULL;

    root = new Node(num);

    cout << "Enter data for inserting in left child of " << num << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for inserting in right child of " << num << endl;
    root->right = buildTree(root->right);

    return root;
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

/*
    I took a map and store the values of parents of each node that can be easily done while traversing the tree .
    make sure at last we have to put a condition to deal with edge cases like if the asked kth ancestor is not in
    the tree that can be handeled by { return res==0?-1:res } this statement.
*/

int kthAncestor(Node *root, int k, int node)
{
    unordered_map<int, int> um;
    queue<Node *> que;
    que.push(root);
    um[root->data] = -1;

    while (!que.empty())
    {
        Node *p = que.front();
        que.pop();

        if (p->left)
        {
            um[p->left->data] = p->data;
            que.push(p->left);
        }

        if (p->right)
        {
            um[p->right->data] = p->data;
            que.push(p->right);
        }
    }
    int res = node;
    for (int i = 0; i < k; i++)
        res = um[res];

    return res == 0 ? -1 : res;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    preorder(root);
    int res = kthAncestor(root, 1, 4);
    cout << "ans1 =  " << res << endl;
    res = kthAncestor(root, 2, 5);
    cout << "ans2 =  " << res << endl;
    res = kthAncestor(root, 3, 6);
    cout << "ans3 =  " << res << endl;
    return 0;
}