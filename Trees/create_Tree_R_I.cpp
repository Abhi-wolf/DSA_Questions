#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// RECURSIVE CREATING OF TREE
Node *buildTree(Node *root)
{
    int x;
    cout << "Enter data = ";
    cin >> x;

    if (x == -1)
        return NULL;

    root = new Node(x);

    cout << "Enter data for left child of " << x;
    root->left = buildTree(root->left);

    cout << "Enter data for right child of " << x;
    root->right = buildTree(root->right);

    return root;
}


//  ITERATIVE CREATING TREE
Node* BuildTree(Node *root)
{
    Node *p,*temp;
    queue <Node*> queue;

    int x;
    cout<<"Enter root's data = ";
    cin>>x;

    root=new Node(x);
    queue.push(root);

    while(!queue.empty())
    {
        p=queue.front();
        queue.pop();

        cout<<"Enter left child's data of "<<p->data<<" = ";
        cin>>x;

        if(x!=-1)
        {
            temp=new Node(x);
            p->left=temp;
            queue.push(p->left);
        }

        cout<<"Enter right child's data of "<<p->data<<" = ";
        cin>>x;

        if(x!=-1)
        {
            temp=new Node(x);
            p->right=temp;
            queue.push(p->right);
        }
    }
    return root;
}

//  LEVEL ORDER TRAVERSAL
void level_order(Node *root)
{
    queue<Node *> que;
    que.push(root);
    que.push(NULL);

    while (!que.empty())
    {
        Node *temp = que.front();
        que.pop();

        if (temp == NULL)
        {
            cout << endl;

            if (!que.empty())
                que.push(NULL);
        }

        else
        {
            cout << temp->data << "  ";

            if (temp->left)
                que.push(temp->left);

            if (temp->right)
                que.push(temp->right);
        }
    }
}

int main()
{
    Node *root = NULL;
    //Node *ans = buildTree(root);
    Node *ans=BuildTree(root);
    level_order(ans);
    return 0;
}