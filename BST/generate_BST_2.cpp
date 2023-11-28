#include <iostream>
using namespace std;

//  GENERATE BST FROM PREORDER TRAVERSAL

class Node {
    public:
        Node *left,*right;
        int data;
    Node(int x) {
        this->data=x;
        this->left=this->right=NULL;
    }
};

Node* createBST(int arr[],int &i,int n,int min,int max) {
    if(arr[i]<min || arr[i]>max || i>=n) return NULL;

    Node *t=new Node(arr[i++]);

    t->left=createBST(arr,i,n,min,t->data);
    t->right=createBST(arr,i,n,t->data,max);

    return t;
}

void inorder(Node *p) {
    if(p==NULL) return ;
    inorder(p->left);
    cout<<p->data<<", ";
    inorder(p->right);
}


void preorder(Node *p) {
    if(p==NULL) return ;
    cout<<p->data<<", ";
    preorder(p->left);
    preorder(p->right);
}

void postorder(Node *p) {
    if(p==NULL) return ;
    postorder(p->left);
    postorder(p->right);
    cout<<p->data<<", ";
}


int main() {
    int arr[8]={40,30,32,35,80,90,100,120};
    int i=0;
    Node *root=createBST(arr,i,8,INT_MIN,INT_MAX);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);

    return 0;
}