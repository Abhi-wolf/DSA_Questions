#include <iostream>
#include <stack>
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
        this->left = this->right = NULL;
    }
};

Node *insert(Node *root, int x)
{
    if (root == NULL)
        return new Node(x);

    if (root->data > x)
        root->left = insert(root->left, x);
    else if (root->data < x)
        root->right = insert(root->right, x);

    return root;
}

//  PREORDER
void RPreorder(Node *q)
{
    if (q)
    {
        cout << q->data << "  ";
        RPreorder(q->left);
        RPreorder(q->right);
    }
}

void IPreorder(Node *q)
{
    stack<Node *> s;

    while (q || !s.empty())
    {
        if (q)
        {
            cout << q->data << "  ";
            s.push(q);
            q = q->left;
        }

        else
        {
            q = s.top();
            s.pop();
            q = q->right;
        }
    }
    cout << endl;
}

//  INORDER
void RInorder(Node *a)
{
    if (a)
    {
        RInorder(a->left);
        cout << a->data << "  ";
        RInorder(a->right);
    }
}

void IInorder(Node *a)
{
    stack<Node *> s;

    while (a || !s.empty())
    {
        if (a)
        {
            s.push(a);
            a = a->left;
        }

        else
        {
            a = s.top();
            s.pop();
            cout << a->data << "  ";
            a = a->right;
        }
    }
    cout << endl;
}

//  POSTORDER
void RPostorder(Node *p)
{
    if (p)
    {
        RPostorder(p->left);
        RPostorder(p->right);
        cout << p->data << "  ";
    }
}

/*  Iterative prorder using two stacks
    1. Push root to first stack.
    2. Loop while first stack is not empty
        2.1 Pop a node from first stack and push it to second stack
        2.2 Push left and right children of the popped node to first stack
    3. Print contents of second stack
*/
void IPostorder(Node *p)
{
    stack<Node *> s1, s2;
    s1.push(p);

    while (!s1.empty())
    {
        p = s1.top();
        s1.pop();
        s2.push(p);

        if (p->left)
            s1.push(p->left);
        if (p->right)
            s1.push(p->right);
    }

    while (!s2.empty())
    {
        p = s2.top();
        s2.pop();
        cout << p->data << "  ";
    }
    cout << endl;
}

//  iterative postorder using one stack
/*
    1.1 Create an empty stack

    2.1 Do following while root is not NULL
        a) Push root's right child and then root to stack.
        b) Set root as root's left child.

    2.2 Pop an item from stack and set it as root.
        a) If the popped item has a right child and the right child is at top of stack, then remove
            the right child from stack, push the root back and set root as root's right child.
        b) Else print root's data and set root as NULL.

    2.3 Repeat steps 2.1 and 2.2 while stack is not empty.
*/
void I_oneStack_preorder(Node *root)
{
    //  check for empty tree
    if (root == NULL)
        return;

    stack<Node *> st;
    st.push(root);

    Node *prev = NULL;

    while (!st.empty())
    {
        Node *curr = st.top();

        /* go down the tree in search of a leaf an if so process it and pop
                stack otherwise move down*/
        if (prev == NULL || prev->left == curr || prev->right == curr)
        {
            if (curr->left)
                st.push(curr->left);
            else if (curr->right)
                st.push(curr->right);
            else
            {
                st.pop();
                cout << curr->data << "  ";
            }
        }

        /* go up the tree from left node, if the child is right push it
              onto stack otherwise process parent and pop stack */
        else if (curr->left == prev)
        {
            if (curr->right)
                st.push(curr->right);
            else
            {
                st.pop();
                cout << curr->data << "  ";
            }
        }

        /* go up the tree from right node and after coming back from
              right node process parent and pop stack */
        else if (curr->right == prev)
        {
            st.pop();
            cout << curr->data << "  ";
        }
        prev = curr;
    }
}

int main()
{
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 90);

    cout << "\nRecursive postorder = ";
    RPostorder(root);
    cout << "\nIterative postorder = ";
    IPostorder(root);

    cout << "\nIterative postorder using one stack = ";
    I_oneStack_preorder(root);

    cout << "\n\nRecursive preorder = ";
    RPreorder(root);
    cout << "\nIterative preorder = ";
    IPreorder(root);

    cout << "\nRecursive inorder = ";
    RInorder(root);
    cout << "\nIterative inorder = ";
    IInorder(root);
    return 0;
}
