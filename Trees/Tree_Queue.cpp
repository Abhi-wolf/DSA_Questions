#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;

    Node(int d)
    {
        this->data = d;
        this->lchild = NULL;
        this->rchild = NULL;
    }
};

class Tree
{
private:
    Node *root;

public:
    Tree();
    ~Tree();
    void createTree();

    void preorder(Node *p);
    void preorder()
    {
        preorder(root);
    }

    void inorder(Node *p);
    void inorder()
    {
        inorder(root);
    }

    void postorder(Node *p);
    void postorder()
    {
        postorder(root);
    }

    void levelorder(Node *p);
    void levelorder()
    {
        levelorder(root);
    }
};

Tree::Tree()
{
    root = nullptr;
}

Tree::~Tree()
{
    delete root;
}

void Tree::createTree()
{
    Node *p, *t;
    int x;
    queue<Node *> q;
    cout << "Enter root's data : ";
    cin >> x;

    root = new Node(x);
    q.emplace(root);

    while (!q.empty())
    {
        p = q.front();
        q.pop();

        cout << "Enter left child's data of " << p->data << " : ";
        cin >> x;
        if (x != -1)
        {
            t = new Node(x);
            p->lchild = t;
            q.emplace(t);
        }

        cout << "Enter right child's data of " << p->data << " : ";
        cin >> x;
        if (x != -1)
        {
            t = new Node(x);
            p->rchild = t;
            q.emplace(t);
        }
    }
}

/*
//  RECURSIVE PROCEDURE FOR PREORDER TRAVERSAL
void Tree::preorder(Node *p)
{
    if (p)
    {
        cout << p->data << "  ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
*/
//  ITERATIVE PROCEDURE FOR PREORDER TRAVERSAL
void Tree::preorder(Node *p)
{
    stack<Node *> s;
    while (p || !s.empty())
    {
        if (p)
        {
            cout << p->data << "  ";
            s.push(p);
            p = p->lchild;
        }
        else
        {
            p = s.top();
            s.pop();
            p = p->rchild;
        }
    }
    cout << endl;
}

/*
//  RECURSIVE PROCEDURE FOR INORDER TRAVERSAL
void Tree::inorder(Node *p)
{
    if(p)
    {
        inorder(p->lchild);
        cout<<p->data<<"  ";
        inorder(p->rchild);
    }
} */


//  ITERATIVE PROCEDURE FOR INORDER TRAVERSAL
void Tree::inorder(Node *p)
{
    stack<Node *> s2;

    while (p || !s2.empty())
    {
        if (p)
        {
            s2.push(p);
            p = p->lchild;
        }
        else
        {
            p = s2.top();
            s2.pop();
            cout << p->data << "  ";
            p = p->rchild;
        }
    }
    cout << endl;
}


/*
void Tree::postorder(Node *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << "  ";
    }
}
*/



//  LEVEL ORDER TRAVERSAL
void Tree::levelorder(Node *p)
{
    queue <Node*> q2;
    cout<<p->data<<"  ";
    q2.push(p);

    while(!q2.empty())
    {
        p=q2.front();
        q2.pop();
        if(p->lchild)
        {
            cout<<p->lchild->data<<"  ";
            q2.push(p->lchild);
        }

        if(p->rchild)
        {
            cout<<p->rchild->data<<"  ";
            q2.push(p->rchild);
        }
    } 
    cout<<endl;
}





int main()
{
    Tree obj;
    obj.createTree();

    // cout<<"\nPreorder\n";
    // obj.preorder();

    // cout << "\nInorder\n";
    // obj.inorder();

    // cout<<"\nPostorder\n";
    // obj.postorder();

    cout << "\nLevel Order\n";
    obj.levelorder();
    cout << endl;


    return 0;
}
