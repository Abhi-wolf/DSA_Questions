#include <iostream>
#include <queue>
using namespace std;

/*
    Binary search tree is a node-based binary tree data structure
                             PROPERTIES
    (1) The left subtree of a node contains only nodes with keys lesser than the node’s key.
    (2) The right subtree of a node contains only nodes with keys greater than the node’s key.
    (3) The left and right subtree each must also be a binary search tree.  
    (4) There must be no duplicate nodes(BST may have duplicate values with different handling approaches)
    (5) Inorder traversal gives sorted output.
    (6) Number of unique BSTs with n distinct keys is Catalan Number.
*/


class Node
{
    public:
        int data;
        Node *left;
        Node *right;
    
    Node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};




//  RECURSIVE INSERT FUNCTION 
Node* insert(Node* ptr,int key)
{
    if(ptr==NULL)
        return new Node(key);
    
    if(key < ptr->data)
        ptr->left=insert(ptr->left,key);
    
    else if(key > ptr->data)
        ptr->right=insert(ptr->right,key);
    
    return ptr;
}




//  ITERATIVE INSERT FUNCTION
void Insert_iterative(Node* &root,int key)
{
    Node* p=new Node(key);

    if(root==NULL)
    {
        root=p;
        return;
    }

    Node* prev=NULL;
    Node*temp=root;

    while(temp)
    {
        if(temp->data > key)
        {
            prev=temp;
            temp=temp->left;
        }

        else if(temp->data < key)
        {
            prev=temp;
            temp=temp->right;
        }
    }
    if(prev->data > key)
        prev->left=p;
    else
        prev->right=p;    

}




//  INORDER TRAVERSAL
void Inorder(Node *root)
{
    if(root!=NULL)
    {
        Inorder(root->left);
        cout<<root->data<<"  ";
        Inorder(root->right);
    }
}


//  LEVEL ORDER TRAVERSAL
void LevelOrder(Node* root)
{
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();


        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }

        else
        {
            cout<<temp->data<<"  ";

            if(temp->left)
                q.push(temp->left);
            
            if(temp->right)
                q.push(temp->right);
        }
    }
}




//  RECURSIVE BINARY SEARCH TREE
Node* binary_search_tree(Node *root,int key)
{
    if(root==NULL || root->data==key)
        return root;
    
    else if(root->data < key)
        return binary_search_tree(root->right,key);
    
    else
        return binary_search_tree(root->left,key);
}



//  ITERATIVE BINARY SEARCH TREE
Node* binary_search_tree_2(Node *root,int key)
{
    while(root!=NULL)
    {
        if(root->data == key)
            return root;
        else if(root->data > key)
            root=root->left;
        else
            root=root->right;
    }
    return NULL;
}




//  SMALLEST NODE IN BST -- returns the node with the smallest value in the BST.
Node* minValueNode(Node* root)
{
    while(root && root->left)
        root=root->left;
    
    return root;
}







int main()
{
    Node* root=NULL;
    /*
    root=insert(root,50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,90); */

    Insert_iterative(root,50);
    Insert_iterative(root,30);
    Insert_iterative(root,20);
    Insert_iterative(root,40);
    Insert_iterative(root,10);
    Insert_iterative(root,5);
    Insert_iterative(root,100);

    Inorder(root);
    cout<<endl;
    LevelOrder(root);

    Node* ans=NULL;
    // ans=binary_search_tree(root,100);
    ans=binary_search_tree_2(root,10);
    if(ans)
        cout<<"\nTrue"<<endl;
    else
        cout<<"\nFalse\n";


    cout<<"\nMinimum value in BST is "<<minValueNode(root)->data<<"\n\n";
    LevelOrder(root);
    return 0;
}
