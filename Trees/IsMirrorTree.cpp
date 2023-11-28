#include <iostream>
using namespace std;

class Node {
    public: 
        int data;
        Node *left;
        Node *right;
    
    Node(int x) {
        this->data=x;
        this->left=NULL;
        this->right=NULL;
    }
};

void inorderTraversal(Node *p)
{
    if(p==NULL) return ;
    inorderTraversal(p->left);
    cout<<p->data<<", ";
    inorderTraversal(p->right);
}

void preorderTraversal(Node *p)
{
    if(p==NULL) return ;
    cout<<p->data<<", ";
    preorderTraversal(p->left);
    preorderTraversal(p->right);
}



int searchInorder(int arr[],int s,int e,int key) {
    for(int i=s;i<=e;i++) if(arr[i]==key) return i;
    return -1;
}

//  CREATING FIRST TREE
Node* createTreeFromTraversal1(int inorder[],int preorder[],int inStart,int inEnd) {
    static int preIndex1=0;

    if(inStart>inEnd) return NULL;

    Node *p=new Node(preorder[preIndex1++]);

    if(inStart==inEnd) return p;

    int splitIndex=searchInorder(inorder,inStart,inEnd,p->data);

    p->left=createTreeFromTraversal1(inorder,preorder,inStart,splitIndex-1);
    p->right=createTreeFromTraversal1(inorder,preorder,splitIndex+1,inEnd);

    return p;
}

//  CREATING SECOND TREE
Node* createTreeFromTraversal2(int inorder[],int preorder[],int inStart,int inEnd) {
    static int preIndex2=0;

    if(inStart>inEnd) return NULL;

    Node *p=new Node(preorder[preIndex2++]);

    if(inStart==inEnd) return p;

    int splitIndex=searchInorder(inorder,inStart,inEnd,p->data);

    p->left=createTreeFromTraversal2(inorder,preorder,inStart,splitIndex-1);
    p->right=createTreeFromTraversal2(inorder,preorder,splitIndex+1,inEnd);

    return p;
}


// FUNCTION TO CREATE MIRROR TREE
Node* mirrorBinaryTree(Node *root) {
    Node *temp=NULL;

    if(root) {
        mirrorBinaryTree(root->left);
        mirrorBinaryTree(root->right);

        temp=root->left;
        root->left=root->right;
        root->right=temp;
    }

    return root;
}


// FUNCTION TO CHECK IF THE TREES ARE MIRRORS OF EACH OTHER
bool areMirrors(Node *r1,Node *r2) {
    if(r1==NULL && r2==NULL) return  true;
    if(r1==NULL || r2==NULL) return  false;
    if(r1->data != r2->data) return false;

    return areMirrors(r1->left,r2->right) && areMirrors(r1->right,r2->left);
}


int main() {
    int in1[]={4,2,5,1,3};   
    int pre1[]={1,2,4,5,3}; 
    int in2[]={3,1,5,2,6};   
    int pre2[]={1,3,2,5,6};   

    int s=sizeof(in1)/sizeof(in1[0]);

    Node *root1=createTreeFromTraversal1(in1,pre1,0,s-1);
    Node *root2=createTreeFromTraversal2(in2,pre2,0,s-1);
    cout<<"\nInorder root 1 = ";
    inorderTraversal(root1);
    cout<<"\nPreorder root 1 = ";
    preorderTraversal(root1);
    cout<<"\n\nInorder root 2 = ";
    inorderTraversal(root2);
    cout<<"\nPreorder root 2 = ";
    preorderTraversal(root2);

    bool ans=areMirrors(root1,root2);
    if(ans) cout<<"\nYes the trees are mirrors of each other";
    else cout<<"\nNo the trees are not mirrors of each other";
    

    Node *root3=mirrorBinaryTree(root1);
    cout<<"\n\nInorder mirror tree = ";
    inorderTraversal(root3);
    cout<<"\nPreorder mirror tree  = ";
    preorderTraversal(root3);
    
    return 0;
}

