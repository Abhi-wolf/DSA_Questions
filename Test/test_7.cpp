#include <iostream>
#include <vector>
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

void preorder1(Node* &root,vector<int> &ans)
{
    if(root==NULL)
    return ;

    ans.push_back(root->data);

    preorder1(root->lchild,ans);
    preorder1(root->rchild,ans);

}

vector<int> preorder(Node *root)
{
    // vector<int>vec;
    // if(root==NULL)
    //     return vector<int>();
    
    // //cout<<root->data<<" ";
    // vec.push_back(root->data);
    // preorder(root->lchild);
    // preorder(root->rchild);
    
    // return vec;
    vector<int> ans;
    preorder1(root,ans);

    return ans;
}

int main()
{
    Node *root=NULL;
    root=buildTree(root);

    vector<int>ans=preorder(root);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<"  ";
    return 0;
}