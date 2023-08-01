#include <iostream>
#include <vector>
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

//  recursive approach
void LeftViewREC(Node *root, int level, vector<int> &vec)
{
    if (root == NULL)
        return;

    if (level == vec.size())
        vec.push_back(root->data);

    LeftViewREC(root->left, level + 1, vec);
    LeftViewREC(root->right, level + 1, vec);
}

//  iterative approach
vector<int> leftViewIterative(Node *root)
{
    vector<int> vec;
    queue<Node *> que;
    que.push(root);
    while (!que.empty())
    {
        int n = que.size();
        for (int i = 1; i <= n; i++)
        {
            Node *p = que.front();
            que.pop();

            if (i == 1)
                vec.push_back(p->data);

            if (p->left != NULL)
                que.push(p->left);

            if (p->right != NULL)
                que.push(p->right);
        }
    }
    return vec;
}

//  recursive approach
void RightViewREC(Node *root, int level, vector<int> &vec)
{
    if (root == NULL)
        return;

    if (level == vec.size())
        vec.push_back(root->data);

    RightViewREC(root->right, level + 1, vec);
    RightViewREC(root->left, level + 1, vec);
}

//  iterative approach
vector<int> rightViewIterative(Node *root)
{
    vector<int> vec;
    queue<Node *> que;
    que.push(root);
    while (!que.empty())
    {
        int n = que.size();
        for (int i = 1; i <= n; i++)
        {
            Node *p = que.front();
            que.pop();

            if (i == 1)
                vec.push_back(p->data);

            if (p->right != NULL)
                que.push(p->right);

            if (p->left != NULL)
                que.push(p->left);
        }
    }
    return vec;
}

void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ", ";
    cout << endl;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    preorder(root);
    vector<int> ans1, ans2;
    LeftViewREC(root, 0, ans1);
    cout << "\nRecusive left = ";
    print(ans1);
    ans2 = leftViewIterative(root);
    cout << "\nIterative left = ";
    print(ans2);

    ans1.clear();
    ans2.clear();
    RightViewREC(root, 0, ans1);
    cout << "\nRecusive right = ";
    print(ans1);
    ans2 = rightViewIterative(root);
    cout << "\nIterative right = ";
    print(ans2);
    return 0;
}