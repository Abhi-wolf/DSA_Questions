#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

class node {
    public:
    int data;
    node *left;
    node *right;

    node(int x) {
        this->data=x;
        this->left=NULL;
        this->right=NULL;
    }
};


node* createTree(node *root)
{
    int num;
    cout<<"Enter the value of num=";
    cin>>num;

    root=new node(num);
    if(num==-1) return NULL;

    cout<<"Enter data for entering in left node of "<<num<<endl;
    root->left=createTree(root);
    cout<<"Enter data for entering in right node of "<<num<<endl;
    root->right=createTree(root);

    return root;
}



int searchInorder(int inorder[],int start,int end,int key)
{
    for(int i=start;i<=end;i++) {
        if(inorder[i]==key) return i;
    }
    return -1;
}


node* buildTree(int *inorder,int *preorder,int inStart,int inEnd)
{
    static int preIndex=0;
    if(inStart>inEnd) return NULL;

    node *t=new node(preorder[preIndex++]);

    if(inStart==inEnd) return t;

    int splitIndex=searchInorder(inorder,inStart,inEnd,t->data);

    t->left=buildTree(inorder,preorder,inStart,splitIndex-1);
    t->right=buildTree(inorder,preorder,splitIndex+1,inEnd);

    return t;
}


void RecPreorder(node *p) {
    if(p==NULL) return;

    cout<<p->data<<", ";
    RecPreorder(p->left);
    RecPreorder(p->right);
}


void IterPreorder(node *p)
{
    stack<node*>stk;
    while(p || !stk.empty())
    {
        if(p) {
            cout<<p->data<<", ";
            stk.push(p);
            p=p->left;
        }
        else {
            p=stk.top();
            stk.pop();
            p=p->right;
        }
    }
}


void RecInorder(node *p)
{
    if(p==NULL) return;

    RecInorder(p->left);
    cout<<p->data<<", ";
    RecInorder(p->right);
}


void IterInorder(node *p)
{
    stack<node*>stk;

    while(p || !stk.empty())
    {
        if(p)
        {
            stk.push(p);
            p=p->left;
        }

        else {
            p=stk.top();
            stk.pop();
            cout<<p->data<<", ";
            p=p->right;
        }
    }
}


void RecPostorder(node *p)
{
    if(p==NULL) return;

    RecPostorder(p->left);
    RecPostorder(p->right);
    cout<<p->data<<", ";
}

// using two stacks
void IterPostorder(node *p)
{
    stack<node*>stk1,stk2;
    stk1.push(p);

    while(!stk1.empty())
    {
        p=stk1.top();
        stk1.pop();
        stk2.push(p);

        if(p->left) stk1.push(p->left);
        if(p->right) stk1.push(p->right);
    }

    while(!stk2.empty()){
        cout<<stk2.top()->data<<", ";
        stk2.pop();
    }
}

// using single stack
void IterPostOrderSingleStack(node *p)
{
    if(p==NULL) return;
    stack<node*>st;
    st.push(p);
    node *prev=NULL;
    while(!st.empty())
    {
        node *curr=st.top();

        if(prev==NULL || prev->left==curr || prev->right==curr)
        {
            if(curr->left) st.push(curr->left);
            else if(curr->right) st.push(curr->right);
            else {
                cout<<curr->data<<", ";
                st.pop();
            }
        }

        else if(curr->left==prev) 
        {
            if(curr->right) st.push(curr->right);
            else {
                cout<<curr->data<<", ";
                st.pop();
            }
        }

        else if(curr->right==prev) {
            st.pop();
            cout<<curr->data<<", ";
        }
        prev=curr;
    }
}


void Levelorder(node *p)
{
    queue<node*>que;
    que.push(p);
    que.push(NULL);

    while(!que.empty())
    {
        p=que.front();
        que.pop();
        if(p==NULL){
            cout<<"\n";
            if(!que.empty()) que.push(NULL);
        }

        else {
            cout<<p->data<<", ";
            if(p->left)que.push(p->left);
            if(p->right)que.push(p->right);
        }
    }
}





int main() {
    node *root=NULL;
    // root=createTree(root);
    int pre[]={1,2,4,5,3,6,7};
    int in[]={4,2,5,1,6,3,7};
    root=buildTree(in,pre,0,6);
    cout<<"\n recursive inorder = ";
    RecInorder(root);
    cout<<"\n iterative inorder = ";
    IterInorder(root);


    cout<<"\n recursive preorder = ";
    RecPreorder(root);
    cout<<"\n iterative preorder = ";
    IterPreorder(root);

    cout<<"\n recursive postorder = ";
    RecPostorder(root);
    cout<<"\n iterative postorder double stack = ";
    IterPostorder(root);
    cout<<"\n iterative postorder single stack = ";
    IterPostOrderSingleStack(root);

    cout<<"\n LevelOrder Traversal \n";
    Levelorder(root);
    return 0;
}