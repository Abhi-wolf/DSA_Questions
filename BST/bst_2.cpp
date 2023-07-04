#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    struct Node* lchild;
    int data;
    struct Node* rchild; 
}*root=NULL;



//  ITERATIVE INSERT FUNCTION
void insert(int key)
{
    struct Node *t=root;
    struct Node *p, *r;

    if(root==NULL)
    {
        p=(struct Node*)malloc(sizeof(struct Node));
        p->data=key;
        p->lchild = p->rchild = NULL;
        root=p;
        return;
    }

    while(t!=NULL)
    {
        r=t;
        
        if(key < t->data)
            t=t->lchild;
        
        else if(key > t->data)
            t=t->rchild;
        
        else    
            return;
    }
    p=(struct Node*)malloc(sizeof(struct Node));
    p->data=key;
    p->lchild = p->rchild = NULL;

    if(key < r->data)
        r->lchild=p;
    else
        r->rchild=p;
        
}



//  RECURSIVE INSERT FUNCTION
struct Node* Rinsert(struct Node *p,int key)
{
    struct Node *t=NULL;
    if(p==NULL)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=key;
        t->lchild = t->rchild = NULL;
        return t;
    }

    if(key < p->data)
        p->lchild=Rinsert(p->lchild,key);
    else if(key > p->data)
        p->rchild=Rinsert(p->rchild,key);
    
    return p;
}



//  PREORDER TRAVERSAL
void Preorder(Node *root)
{
    if(root)
    {
        cout<<root->data<<"  ";
        Preorder(root->lchild);
        Preorder(root->rchild);
    }
}



//  INORDER TRAVERSAL
void Inorder(Node *root)
{
    if(root)
    {
        Inorder(root->lchild);
        cout<<root->data<<"  ";
        Inorder(root->rchild);
    }
}




//  HEIGHT OF TREE
int Height(struct Node *p)
{
    int x,y;
    if(p==NULL)
        return 0;
    x=Height(p->lchild);
    y=Height(p->rchild);

    return x>y?x+1:y+1;
}



//  INORDER PREDECESSOR (right most element of left subtree)
struct Node* InPre(struct Node *p)
{
    while(p && p->rchild!=NULL)
        p=p->rchild;
    
    return p;
}


//  INORDER SUCCESSOR (left most element of right subtree)
struct Node* InSucc(struct Node *p)
{
    while(p && p->lchild!=NULL)
        p=p->lchild;
    
    return p;
}




//  DELETE A NODE IN TREE
struct Node* Delete(struct Node *p,int key)
{
    struct Node *q=NULL;

    if(p==NULL)
        return NULL;

    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root)
            root=NULL;
        delete p;
        return NULL;
    }

    if(key < p->data)
        p->lchild=Delete(p->lchild,key);
    else if(key > p->data)
        p->rchild=Delete(p->rchild,key);

    else
    {
        if(Height(p->lchild) > Height(p->rchild))
        {
            q=InPre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=InSucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    return p;
}




int main()
{
    insert(10);
    insert(5);
    insert(100);
    insert(20);
    insert(8);
    insert(300); 

    // root=Rinsert(root,50);
    // Rinsert(root,10);
    // Rinsert(root,40);
    // Rinsert(root,20);
    // Rinsert(root,30);


    Inorder(root);
    cout<<endl;

    Delete(root,50);

    Inorder(root);
    cout<<endl;
    return 0;
}