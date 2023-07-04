#include <iostream>
#include <stack>
using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data=d;
        this->left = this->right = NULL;
    }
};



Node* Insert(Node *root,int key)
{
    if(root==NULL)
        return new Node(key);
    else if(key < root->data)
        root->left=Insert(root->left,key);
    else
        root->right=Insert(root->right,key);
    
    return root;
}




void Preorder(Node *root)
{
    if(root)
    {
        cout<<root->data<<"  ";
        Preorder(root->left);
        Preorder(root->right);
    }
}



void Inorder(Node *root)
{
    if(root)
    {
        Inorder(root->left);
        cout<<root->data<<"  ";
        Inorder(root->right);
    }
}









Node* Create_preorder(int pre[],int n)
{
    stack <Node*> stk;
    Node *root1=NULL;
    Node *p,*t;
    int i=0;
    root1=new Node(pre[i++]);
    p=root1;

    while(i<n)
    {
        if(pre[i] < p->data)
        {
            t=new Node(pre[i++]);
            p->left=t;
            stk.push(p);
            p=t;
        }

        else
        {
            if(pre[i] > p->data && pre[i] < stk.top()->data && !stk.empty())
            {
                t=new Node(pre[i++]);
                p->right=t;
                p=t;
            }
            else
            {
                p=stk.top();
                stk.pop();
            }
        }
    }
    
    Inorder(root1);
    return root1;
}











int main()
{
    Node *root=NULL;
    root=Insert(root,50);
    Insert(root,30);
    Insert(root,20);
    Insert(root,40);
    Insert(root,70);
    Insert(root,60);
    Insert(root,80);

    // Preorder(root);
    cout<<endl;
    // Inorder(root);

    int arr[]={50,30,20,40,70,60,80};
    Node *ans=Create_preorder(arr,7);
    cout<<ans->data<<endl;
    Preorder(ans);
    cout<<endl;
    Inorder(ans);
    return 0;
}