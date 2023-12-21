#include <iostream>
using namespace std;
// BST INSERT AND DELETE
class node {
    public:
        int data;
        node *left;
        node *right;
    
    node(int x) {
        this->data=x;
        this->left=this->right=NULL;
    }

    ~node() {
        delete left;
        delete right;
    }
};


int Height(node *p)
{
    if(p==NULL) return 0;
    int x=Height(p->left);
    int y=Height(p->right);

    return x>y? x+1:y+1;
}


node* InPre(node *p) {
    while(p && p->right) p=p->right;
    return p;
}


node* InSucc(node *p) {
    while(p && p->left) p=p->left;
    return p;
}

node* Insert(node *root,int key)
{
    if(root==NULL) {
        node *temp=new node(key);
        root=temp;
        return root;
    }

    else if(root->data > key) root->left= Insert(root->left,key);
    else if(root->data < key) root->right= Insert(root->right,key);
    return root;
}


node* Delete(node *root,int key)
{
    if(root==NULL) return NULL;

    if(root->left==NULL && root->right==NULL) {
        delete root;
        return NULL;
    }

    if(key < root->data) root->left=Delete(root->left,key);
    else if(key > root->data) root->right=Delete(root->right,key);
    else {
        if(Height(root->left) > Height(root->right)){
            node *temp=InPre(root->left);
            root->data=temp->data;
            root->left=Delete(root->left,temp->data);
        }

        else {
            node *temp=InSucc(root->right);
            root->data=temp->data;
            root->right=Delete(root->right,temp->data);
        }
    }
    return root;
}


void Inorder(node *p) {
    if(p==NULL) return;
    
    Inorder(p->left);
    cout<<p->data<<", ";
    Inorder(p->right);
}


void Postorder(node *p) {
    if(p==NULL) return;
    
    Postorder(p->left);
    Postorder(p->right);
    cout<<p->data<<", ";
}


int main() {
    int arr[]={40,30,32,35,80,90,100,120};
    node *root=NULL;
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++) root=Insert(root,arr[i]);

    cout<<"\n Inorder = ";
    Inorder(root);
    cout<<"\n Postorder = ";
    Postorder(root);


    root=Delete(root,40);
    cout<<"\n Inorder = ";
    Inorder(root);
    cout<<"\n Postorder = ";
    Postorder(root);

    return 0;
}
