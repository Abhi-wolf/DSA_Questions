#include <iostream>
#include <queue>
using namespace std;

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

// is the node a leaf node
bool path(Node *root,int x,vector<int>&vec) {
    if(root==NULL)
        return false;
    
    vec.push_back()
    if(root->val==x) {
        return true;
    }
}

int main()
{
    Node *root = NULL;
    root = Insert(root);
    cout << "Inorder = ";
    Inorder(root);
    cout << "\nPreorder =";
    Preorder(root);

    queue<Node *> que;
    que.push(root);
    // vector of answers
    vector<string> ans;
    // vector of leaf nodes
    vector<int> leafs;
    while (!que.empty())
    {
        Node *p = que.front();
        que.pop();


        if (p->left == NULL && p->right == NULL)
        {
            leafs.push_back(p->val);
        }

        if (p->left)
            que.push(p->left);
        if (p->right)
            que.push(p->right);
    }

    int i = 0;
    while (i < leafs.size())
    {
        int toFind = leafs[i++];

        vector<int> v;
        Path(root, toFind, v);

        // char ch = (char)root->val + 48;
        // string str = "";
        // str.push_back(ch);
        // str.push_back('-');
        // str.push_back('>');
        for (int i = 0; i < v.size(); i++)
        {
            char ch = (char)v[i] + 48;
            str.push_back(ch);
            if (i < v.size() - 1)
            {
                str.push_back('-');
                str.push_back('>');
            }
        }
        ans.push_back(str);
    }
}
