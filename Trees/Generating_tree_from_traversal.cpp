#include <iostream>
#include <queue>
using namespace std;

class Node
{
    public:
        int data;
        Node *lchild;
        Node *rchild;
    
    Node(int d)
    {
        this->data=d;
        this->lchild=NULL;
        this->rchild=NULL;
    }
};


void Preorder(Node *p)
{
    if(p!=NULL)
    {
        cout<<p->data<<"  ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}



void levelorder(Node *p)
{
    queue <Node*> q;
    q.push(p);
    cout<<p->data<<"  ";

    while(!q.empty())
    {
        p=q.front();
        q.pop();

        if(p->lchild)
        {
            q.push(p->lchild);
            cout<<p->lchild->data<<"  ";
        }

        if(p->rchild)
        {
            q.push(p->rchild);
            cout<<p->rchild->data<<"  ";
        }
    }
    cout<<endl;
}



int searchInorder(int arr[],int instart,int inend,int data)
{
    for(int i=instart;i<=inend;i++)
    {
        if(arr[i] == data)
            return i;
    }
    return -1;
}



//  GENERATION OF TREE IF PREORDER AND INORDER ARE GIVEN
Node* generateFromTraversal(int *inorder,int *preorder,int instart,int inend)
{
    static int preindex=0;

    if(instart > inend)
        return nullptr;
    
    Node *node = new Node (preorder[preindex++]);

    if(instart == inend)
        return node;
    

    int splitIndex = searchInorder(inorder,instart,inend,node->data);

    node->lchild=generateFromTraversal(inorder,preorder,instart,splitIndex-1);
    
    node->rchild=generateFromTraversal(inorder,preorder,splitIndex+1,inend);

    return node;
}





//  COUNT OF NUMBER OF NODES
int count(Node *p)
{
    int x=0,y=0;
    if(p!=NULL)
    {
        x=count(p->lchild);
        y=count(p->rchild);

        /*  COUNT OF NODES STRICTLY HAVING TWO NODES
        if(p->lchild && p->rchild)
            return x+y+1;
        else
            return (x+y);
        */

       //   COUNT OF TOTAL NUMBERS OF NODES
       return (x+y+1);
       
      
        //  SUM OF DATAS OF IN ALL THE NODES
        //return (x+y+p->data);


    }
    return 0;
}



//  CALCULATING HEIGHT OF TREE  (starts from 1)
int height(Node *p)
{
    int x=0,y=0;
    if(p==NULL)
        return 0;
    x=height(p->lchild);
    y=height(p->rchild);

    if(x>y)
        return x+1;
    else
        return y+1;
}




//  COUNTING NO OF LEAF NODES IN THE TREE
// LEAF NODES -- NODES HAVING NO CHILD      (external nodes)
// NON-LEAF NODES -- HAVING AT LEAST ONE CHILD      (internal nodes)

int leaf_nodes(Node *p)
{
    int x=0,y=0;

    if(p==NULL)
        return 0;
    
    x=leaf_nodes(p->lchild);
    y=leaf_nodes(p->rchild);

    if(!p->lchild && !p->rchild)
        return x+y+1;
    else
        return x+y;
}



//  NON-LEAF NODES (OF DEGREE 2 MEANS NODES HAVING BOTH THE CHILDS)
int Non_leaf_nodes_2(Node *p)
{
    int x=0,y=0;

    if(p==NULL)
        return 0;
    
    x=Non_leaf_nodes_2(p->lchild);
    y=Non_leaf_nodes_2(p->rchild);

    if(p->lchild && p->rchild)
        return x+y+1;
    else
        return x+y;
}



//  NON-LEAF NODES (OF DEGREE 1 MEANS NODES HAVING ONLY ONE CHILDS)
int Non_leaf_nodes_degree_1(Node *p)
{
    int x=0,y=0;

    if(p==NULL)
        return 0;
    
    x=Non_leaf_nodes_degree_1(p->lchild);
    y=Non_leaf_nodes_degree_1(p->rchild);

    if((p->lchild!=NULL && p->rchild==NULL) || (p->lchild==NULL && p->rchild!=NULL))
        return x+y+1;
    else
        return x+y;
}



//  NON-LEAF NODES (OF DEGREE 1 OR DEGREE 2 )
int Non_leaf_nodes_degree_1_OR_2(Node *p)
{
    int x=0,y=0;

    if(p==NULL)
        return 0;
    
    x=Non_leaf_nodes_degree_1_OR_2(p->lchild);
    y=Non_leaf_nodes_degree_1_OR_2(p->rchild);

    if(p->lchild!=NULL || p->rchild!=NULL)
        return x+y+1;
    else
        return x+y;
}



int main()
{
    // int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    // int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};

    int preorder[] = {1,2,4,5,3,6,7};
    int inorder[] = {4,2,5,1,6,3,7};
    

    Node *ans=generateFromTraversal(inorder,preorder,0,6);

    levelorder(ans);

    cout<<"Number of nodes in tree is "<<count(ans)<<"\n";

    cout<<"Height of in tree is "<<height(ans)<<"\n";

    cout<<"Number of leaf nodes in tree is "<<leaf_nodes(ans)<<endl;

    cout<<"Number of non-leaf nodes in tree is "<<Non_leaf_nodes_2(ans)<<endl;

    cout<<"Number of non-leaf nodes of degree 1 in tree is "<<Non_leaf_nodes_degree_1(ans)<<endl;

    cout<<"Number of non-leaf nodes of degree 1 or 2 in tree is "<<Non_leaf_nodes_degree_1_OR_2(ans)<<endl;

    return 0;
}