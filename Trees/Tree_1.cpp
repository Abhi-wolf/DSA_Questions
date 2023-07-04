#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *lchild;
        Node *rchild;
    
    Node(int data)
    {
        this->data=data;
        this->lchild=nullptr;
        this->rchild=nullptr;
    }
};



Node* buildTree(Node *root)
{
    int x;
    cout<<"Enter data = ";
    cin>>x;

    root=new Node(x);

    if(x==-1)
        return NULL;
    
    cout<<"Enter data for inserting in left child  of "<<x<<endl;
    root->lchild=buildTree(root->lchild);

    cout<<"Enter data for inserting in rigth child  of "<<x<<"\n";
    root->rchild=buildTree(root->rchild);

    return root;
}



void preorder(Node *root)
{
    if(root==NULL)
        return;
    
    cout<<root->data<<" ";
    preorder(root->lchild);
    preorder(root->rchild);
    
}



void inorder(Node *root)
{
    if(root!=NULL)
    {
        inorder(root->lchild);
        cout<<root->data<<"  ";
        inorder(root->rchild);
    }
    
}



void postorder(Node *root)
{
    if(root!=NULL)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        cout<<root->data<<"  ";
    }
    
}



int main()
{
    Node *root=NULL;
    root=buildTree(root);

    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    return 0;
}