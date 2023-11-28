#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *left,*right;
    Node(int data) {
        this->data=data;
        this->left=this->right=NULL;
    }
};

// recursive insertion 
Node* Insert(Node *p,int x) {
    if(p==NULL)  return new Node(x);

    if(p->data > x)  p->left= Insert(p->left,x);
    else p->right= Insert(p->right,x);

    return p;
}

// inorder 
void Inorder(Node *p) {
    if(p==NULL) return;

    Inorder(p->left);
    cout<<p->data<<", ";
    Inorder(p->right);
}


// common ancestor
int commonAncestor(Node *p,int v1,int v2) {
    if(p==NULL) return 0;

    if(v1 < p->data && v2 < p->data)
        return commonAncestor(p->left,v1,v2);

    else if(v1 > p->data && v2 > p->data)
        return commonAncestor(p->right,v1,v2);

    else 
        return p->data;
    
}

int main() {
    int arr[8]={8,4,9,1,2,3,6,5};
    Node *root=NULL;
    for(int i=0;i<8;i++)
        root=Insert(root,arr[i]);
    
    Inorder(root);
    int x=commonAncestor(root,4,1);
    cout<<"\ncommon ancestor = "<<x<<endl;
    return 0;
}