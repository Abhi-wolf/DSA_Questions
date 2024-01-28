#include <iostream>
#include <queue>
#include <utility>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        this->data = x;
        this->left = this->right = NULL;
    }
};

Node *createTreeFromArray(int arr[], int n)
{
    if (n == 0)
        return NULL;

    queue<Node *> que;
    int i = 0;
    Node *root = new Node(arr[i++]);
    que.push(root);

    while (i < n)
    {
        Node *temp = que.front();
        que.pop();

        if (arr[i] != -1)
        {
            temp->left = new Node(arr[i++]);
            que.push(temp->left);
        }
        else
        {
            temp->left == NULL;
            i++;
        }

        if (i < n && arr[i] != -1)
        {
            temp->right = new Node(arr[i++]);
            que.push(temp->right);
        }
        else
        {
            temp->right == NULL;
            i++;
        }
    }
    return root;
}

void LevelOrder(Node *root)
{
    queue<Node *> que;
    que.push(root);
    que.push(NULL);

    while (!que.empty())
    {
        Node *p = que.front();
        que.pop();

        if (p == NULL)
        {
            cout << endl;
            if (!que.empty())
                que.push(NULL);
        }

        else
        {
            cout << p->data << ", ";
            if (p->left)
                que.push(p->left);
            if (p->right)
                que.push(p->right);
        }
    }
    cout << endl;
}

// TOP VIEW
void TopView(Node *root)
{
    map<int, int> mp;
    queue<pair<Node *, int>> que;
    que.push({root, 0});

    while (!que.empty())
    {
        Node *p = que.front().first;
        int height = que.front().second;
        que.pop();

        if (mp[height] == 0)
            mp[height] = p->data;

        if (p->left)
            que.push({p->left, height - 1});
        if (p->right)
            que.push({p->right, height + 1});
    }

    for (auto x : mp)
        cout << x.second << ", ";

    cout << "\n\n";
}

// BOTTOM VIEW
void BottomView(Node *root)
{
    map<int, int> mp;
    queue<pair<Node *, int>> que;
    que.push({root, 0});

    while (!que.empty())
    {
        Node *p = que.front().first;
        int height = que.front().second;
        que.pop();

        mp[height] = p->data;

        if (p->left)
            que.push({p->left, height - 1});
        if (p->right)
            que.push({p->right, height + 1});
    }

    for (auto x : mp)
        cout << x.second << ", ";

    cout << "\n\n";
}
int main()
{
    int arr[] = {1, -1, 2, -1, 5, 3, 6, -1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = createTreeFromArray(arr, n);
    cout << "Top view = ";
    TopView(root);
    cout << "Bottom view = ";
    BottomView(root);

    int arr2[] = {20, 8, 22, 5, 3, 4, 25, -1, -1, 10, -1, -1, 14};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    Node *root2 = createTreeFromArray(arr2, n2);
    cout << "Top view = ";
    TopView(root2);
    cout << "Bottom view = ";
    BottomView(root2);

    int arr3[] = {10, 20, 30, 40, 60, 90, 100};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    Node *root3 = createTreeFromArray(arr3, n3);
    cout << "Top view = ";
    TopView(root3);
    cout << "Bottom view = ";
    BottomView(root3);

    int arr4[] = {10, 20, 30, 40, 60, 90, 100};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    Node *root4 = createTreeFromArray(arr4, n4);
    cout << "Top view = ";
    TopView(root4);
    cout << "Bottom view = ";
    BottomView(root4);
    return 0;
}