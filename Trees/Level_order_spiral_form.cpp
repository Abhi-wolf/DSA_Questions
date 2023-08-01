#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;


/*
    Given a binary tree and the task is to find the spiral order traversal of the tree.
    Spiral order Traversal mean: Starting from level 0 for root node, for all the even levels we print the node's 
    value from right to left and for all the odd levels we print the node's value from left to right. 

    inorder of tree = 7 2 6 1 5 3 4
    preorder of tree = 1 2 7 6 3 5 4
    function should return 1, 2, 3, 4, 5, 6, 7.
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

Node *Insert(Node *root)
{
    int num;
    cout << "\nenter num = ";
    cin >> num;

    if (num == -1)
        return NULL;

    root = new Node(num);
    cout << "Enter date of left node of " << num;
    root->left = Insert(root->left);
    cout << "Enter date of right node of " << num;
    root->right = Insert(root->right);

    return root;
}

void preOrder(Node *p)
{
    if (p == NULL)
        return;

    cout << p->data << "    ";
    preOrder(p->left);
    preOrder(p->right);
}

void inOrder(Node *p)
{
    if (p == NULL)
        return;

    inOrder(p->left);
    cout << p->data << "    ";
    inOrder(p->right);
}

void LevelOrder(Node *root)
{
    queue<Node *> que;
    que.push(root);
    que.push(NULL);

    vector<int> ans, vec;
    int level = 0;

    while (!que.empty())
    {
        Node *p = que.front();
        que.pop();

        if (p == NULL)
        {
            if (!que.empty())
                que.push(NULL);

            if (level % 2 == 0)
                reverse(vec.begin(), vec.end());

            for (int i = 0; i < vec.size(); i++)
                ans.push_back(vec[i]);

            // or
            // ans.insert(ans.end(),vec.begin(),vec.end());

            level++;

            vec.clear();
            // cout << endl;
        }
        else
        {
            // cout << p->data << "    ";
            vec.push_back(p->data);
            if (p->left)
                que.push(p->left);
            if (p->right)
                que.push(p->right);
        }
    }

    cout << "level order spiral = ";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << "     ";

    cout << endl;
}

int main()
{
    Node *root = NULL;
    root = Insert(root);
    cout << "\n Preorder = ";
    preOrder(root);
    cout << "\n Inorder = ";
    inOrder(root);
    cout << "\n\n";
    LevelOrder(root);
    return 0;
}
