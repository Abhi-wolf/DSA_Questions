#include <iostream>
using namespace std;

class node
{
public:
    node *left;
    int data;
    node *right;
    int height;

    node(int x)
    {
        this->data = x;
        this->left = this->right = NULL;
        this->height = 1;
    }
};

int nodeheight(node *q)
{
    int h1, h2;
    h1 = q && q->left ? q->left->height : 0;
    h2 = q && q->right ? q->right->height : 0;

    return h1 > h2 ? h1 + 1 : h2 + 1;
}

int balancefactor(node *q)
{
    int h1, h2;
    h1 = nodeheight(q->left);
    h2 = nodeheight(q->right);

    return (h1 - h2);
}

node *LLRotation(node *a)
{
    node *al = a->left;
    node *alr = al->right;

    al->right = a;
    a->left = alr;

    a->height = nodeheight(a);
    al->height = nodeheight(al);

    return al;
}

node *LRRotation(node *a)
{
    node *al = a->left;
    node *alr = al->right;

    al->right = alr->left;
    a->left = alr->right;

    alr->left = al;
    alr->right = a;

    a->height = nodeheight(a);
    al->height = nodeheight(al);
    alr->height = nodeheight(alr);

    return alr;
}

node *RRRotation(node *a)
{
    node *ar = a->right;
    node *arl = ar->left;

    ar->left = a;
    a->right = arl;

    a->height = nodeheight(a);
    ar->height = nodeheight(ar);

    return ar;
}

node *RLRotation(node *a)
{
    node *ar = a->right;
    node *arl = ar->left;

    a->right = arl->left;
    ar->left = arl->right;

    arl->left = a;
    arl->right = ar;

    a->height = nodeheight(a);
    ar->height = nodeheight(ar);
    arl->height = nodeheight(arl);

    return arl;
}

node *RInsert(node *p, int key)
{
    node *temp = NULL;
    if (p == NULL)
    {
        temp = new node(key);
        p = temp;
        return p;
    }

    if (key < p->data)
        p->left = RInsert(p->left, key);

    else if (key > p->data)
        p->right = RInsert(p->right, key);

    p->height = nodeheight(p);

    if (balancefactor(p) == 2 && balancefactor(p->left) == 1)
        return LLRotation(p);

    else if (balancefactor(p) == 2 && balancefactor(p->left) == -1)
        return LRRotation(p);

    else if (balancefactor(p) == -2 && balancefactor(p->right) == -1)
        return RRRotation(p);

    else if (balancefactor(p) == -2 && balancefactor(p->right) == 1)
        return RLRotation(p);

    return p;
}

node *Inpre(node *q)
{
    while (q && q->right)
        q = q->right;

    cout<<"pre:"<<q->data<<endl;
    return q;
}

node *Insucc(node *q)
{
    while (q && q->left)
        q = q->left;

    cout<<"succ:"<<q->data<<endl;
    return q;
}

node *Delete(node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (p->left == NULL && p->right == NULL)
    {
        delete p;
        return NULL;
    }

    if (key < p->data)
        p->left = Delete(p->left, key);

    else if (key > p->data)
        p->right = Delete(p->right, key);

    else
    {
        node *q;
        if (nodeheight(p->left) > nodeheight(p->right))
        {
            q = Inpre(p->left);
            p->data = q->data;
            p->left = Delete(p->left, q->data);
        }

        else
        {
            q = Insucc(p->right);
            p->data = q->data;
            p->right = Delete(p->right, q->data);
        }
    }

    p->height = nodeheight(p);

    if (balancefactor(p) == 2 && balancefactor(p->left) == 1)
        return LLRotation(p);

    else if (balancefactor(p) == 2 && balancefactor(p->left) == -1)
        return LRRotation(p);

    else if (balancefactor(p) == 2 && balancefactor(p->left) == 0)
        return LLRotation(p);

    else if (balancefactor(p) == -2 && balancefactor(p->right) == -1)
        return RRRotation(p);

    else if (balancefactor(p) == -2 && balancefactor(p->right) == 1)
        return RLRotation(p);

    else if (balancefactor(p) == -2 && balancefactor(p->right) == 0)
        return RRRotation(p);

    return p;
}

void preorder(node *p)
{
    if (p)
    {
        cout << p->data << "  ";
        preorder(p->left);
        preorder(p->right);
    }
}

void inorder(node *p)
{
    if (p)
    {
        inorder(p->left);
        cout << p->data << "  ";
        inorder(p->right);
    }
}

int main()
{
    node *root = NULL;
    root = RInsert(root, 46);
    root = RInsert(root, 20);
    root = RInsert(root, 54);
    root = RInsert(root, 18);
    root = RInsert(root, 60);
    root = RInsert(root, 7);
    root = RInsert(root, 23);
    root = RInsert(root, 24);


    cout << "\nPreorder : ";
    preorder(root);
    cout << "\nInorder : ";
    inorder(root);

    root=Delete(root,46);

    cout << "\nPreorder : ";
    preorder(root);
    cout << "\nInorder : ";
    inorder(root);

    return 0;
}
