#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
    Node(int x)
    {
        this->data=x;
        this->left=NULL;
        this->right=NULL;
    }
};

int searchInorder(int arr[],int start,int end,int key) {
    for(int i=start;i<=end;i++) if(arr[i]==key) return i;
    return -1;
}


Node* generateTreeFromTraversal(int inOrder[],int preOrder[],int inStart,int inEnd) {
    
    static int preIndex=0;
    if(inStart>inEnd) return NULL;

    Node *p=new Node(preOrder[preIndex++]);

    if(inStart==inEnd) return p;

    int splitIndex=searchInorder(inOrder,inStart,inEnd,p->data);

    p->left=generateTreeFromTraversal(inOrder,preOrder,inStart,splitIndex-1);
    p->right=generateTreeFromTraversal(inOrder,preOrder,splitIndex+1,inEnd);

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


int noOfNodes(Node *p) {
    if(p==NULL) return 0;

    return (noOfNodes(p->left) + noOfNodes(p->right))+1;
}

void printPath(int arr[],int n)
{
    for(int i=0;i<n;i++) cout<<arr[i]<<", ";
    cout<<endl;
}

// ROOT OT LEAF PATH
void rootToLeafPath(Node *root,int path[],int pathLen)
{
    if(root==NULL) return ;
    
    path[pathLen]=root->data;
    pathLen++;

    if(root->left==NULL && root->right==NULL) {
        printPath(path,pathLen);
    }

    else {
        rootToLeafPath(root->left,path,pathLen);
        rootToLeafPath(root->right,path,pathLen);
    }
}



int main() {
    // int preOrder[]={1,2,4,6,5,3,7};
    int preOrder[]={1,2,3,4,5,7,6,8,9,10,11};
    // int inOrder[]={6,4,2,5,1,3,7};
    int inOrder[]={5,4,3,7,2,6,1,8,10,9,11};
    int size=sizeof(preOrder)/sizeof(preOrder[0]);
    Node *root=generateTreeFromTraversal(inOrder,preOrder,0,size-1);
    cout<<"\nPreorder = ";
    preorderTraversal(root);
    cout<<"\nInorder = ";
    inorderTraversal(root);

    int num=noOfNodes(root);
    cout<<"\nNo of Nodes = "<<num;

    cout<<"\nRoot to Leaf paths \n";
    int vec[num];
    rootToLeafPath(root,vec,0);
    return 0;
}