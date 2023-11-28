#include <iostream>
using namespace std;

// DIAMETER OF TREE -- number of nodes between two farthest nodes in tree (including them)


class Node {
    public:
        int data;
        Node *left;
        Node *right;

    Node(int x){
        this->data=x;
        this->left=NULL;
        this->right=NULL;
    }
};

int searchInorder(int arr[],int start,int end,int key)
{
    for(int i=start;i<=end;i++)
    {
        if(arr[i]==key) return i;
    }
    return -1;
}

Node* generateTreeFromTraversal(int *inorder,int *preorder,int instart,int inend)
{
    static int preIndex=0;
    if(instart > inend) return NULL;

    Node *p=new Node(preorder[preIndex++]);

    if(instart==inend) return p;

    int splitIndex=searchInorder(inorder,instart,inend,p->data);

    p->left=generateTreeFromTraversal(inorder,preorder,instart,splitIndex-1);
    p->right=generateTreeFromTraversal(inorder,preorder,splitIndex+1,inend);

    return p;
}

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

int Height(Node *p) {
    if(p==NULL) return 0;
    int left=Height(p->left);
    int right=Height(p->right);

    return left>right? left+1:right+1;
}

// FIRST METHOD
int DiameterOfTree(Node *p,int *height)
{
    int leftDia=0,rightDia=0;
    int lh=0,rh=0;

    if(p==NULL) {
        *height=0;
        return 0;
    }

    leftDia=DiameterOfTree(p->left,&lh);
    rightDia=DiameterOfTree(p->right,&rh);

    *height=max(lh,rh)+1;

    return max(lh+rh+1 ,max(leftDia,rightDia));
}

// SECOND METHOD
int Diameter2(Node *p)
{
    if(p==NULL) return 0;

    int lHeight=Height(p->left);
    int rHeight=Height(p->right);

    int lDia=Diameter2(p->left);
    int rDia=Diameter2(p->right);

    return max(lHeight+rHeight+1,max(lDia,rDia));
}


int main() {
    int preOrder[]={1,2,4,6,5,3,7};
    // int preOrder[]={1,2,3,4,5,7,6,8,9,10,11};
    int inOrder[]={6,4,2,5,1,3,7};
    // int inOrder[]={5,4,3,7,2,6,1,8,10,9,11};
    Node *root=generateTreeFromTraversal(inOrder,preOrder,0,6);
    cout<<"\nPreorder = ";
    preorderTraversal(root);
    cout<<"\nInorder = ";
    inorderTraversal(root);
    int a=0;
    int x=DiameterOfTree(root,&a);
    cout<<"\nDiameter = "<<x<<", "<<a<<endl;
    a=Diameter2(root);
    cout<<"\nDiameter2 = "<<a<<endl;
    return 0;
}