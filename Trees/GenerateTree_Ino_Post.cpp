#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

int searchInorder(int inOrder[], int inStart, int inEnd, int key)
{
    for (int i = inStart; i <= inEnd; i++)
        if (inOrder[i] == key)
            return i;
    return -1;
}

Node *buildTree(int inOrder[], int postOrder[], int inStart, int inEnd, int index)
{
    if (inStart > inEnd)
        return NULL;

    Node *node = new Node(postOrder[index]);

    int splitIndex = searchInorder(inOrder, inStart, inEnd, node->data);

    node->right = buildTree(inOrder, postOrder, splitIndex + 1, inEnd, index - 1);
    node->left = buildTree(inOrder, postOrder, inStart, splitIndex - 1, index - (inEnd - splitIndex) - 1);

    return node;
}

void InOrder(Node *root)
{
    if (!root)
        return;
    InOrder(root->left);
    cout << root->data << " , ";
    InOrder(root->right);
}

void PostOrder(Node *root)
{
    if (!root)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " , ";
}

void PreOrder(Node *root)
{
    if (!root)
        return;
    cout << root->data << " , ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void levelOrder(Node *root)
{
    queue<Node *> que;
    que.push(root);
    que.push(NULL);

    while (!que.empty())
    {
        Node *p = que.front();
        que.pop();

        if (p == NULL)
        {
            cout << endl;
            if (!que.empty())
            {
                que.push(NULL);
            }
        }

        else
        {
            cout << p->data << ", ";
            if (p->left)
                que.push(p->left);
            if (p->right)
                que.push(p->right);
        }
    }
}

int main()
{
    // int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    // int post[] = {8, 4, 5, 2, 6, 7, 3, 1};

    int in[] = {20, 7, 13, 12, 5, 6, 11, 1};
    int post[] = {20, 13, 7, 5, 12, 11, 1, 6};

    Node *root = buildTree(in, post, 0, 7, 7);
    cout << "\n Inorder = ";
    InOrder(root);
    cout << "\n Postorder = ";
    PostOrder(root);
    cout << "\n Preorder = ";
    PreOrder(root);
    cout << "\n Levelorder \n";
    levelOrder(root);

    return 0;
}