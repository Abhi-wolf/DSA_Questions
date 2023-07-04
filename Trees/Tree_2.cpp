#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node *root)
{
    int num;
    cout << "Enter num : ";
    cin >> num;

    root = new Node(num);

    if (num == -1)
        return NULL;

    cout << "Enter data for inserting in left child of " << num << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for inserting in right child of " << num << endl;
    root->right = buildTree(root->right);

    return root;
}

void preorder(Node *root)
{
    if (root)
    {
        cout << root->data << "  ";
        preorder(root->left);
        preorder(root->right);
    }
}



void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        // purana level pura traverse hoo chuka hai
        //  pop front sey hoo raha hai aur push last sey
        if (temp == NULL)
        {
            cout << endl;

            // queue still has some child nodes
            if (!q.empty())
                q.push(NULL);
        }

        else
        {
            cout << temp->data << "  ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}




void buildTreefromLevelOrder(Node *root)
{
    queue <Node*> q;
    cout<<"Enter data for root : ";
    int data;
    cin>>data;
    root=new Node(data);
    q.push(root);

    while(!q.empty())
    {
        Node *temp=q.front();
        q.pop();

        cout<<"Enter left node for : "<<temp->data<<endl;
        int ldata;
        cin>>ldata;

        if(ldata != -1)
        {
            temp->left=new Node(ldata);
            q.push(temp->left);
        }


        cout<<"Enter right node for : "<<temp->data<<endl;
        int rdata;
        cin>>rdata;

        if(rdata != -1)
        {
            temp->right=new Node(rdata);
            q.push(temp->right);
        }
    }
}

int main()
{
    Node *root = NULL;

    Node *ans = buildTree(root);
    levelOrder(ans);
    // preorder(ans);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

   // buildTreefromLevelOrder(root);
   // levelOrder(root);

    return 0;
}