#include <iostream>
#include <queue>
using namespace std;

/* Given a binary tree with n nodes and two node values, a and b, your task is to find the minimum
distance between them. The given two nodes are guaranteed to be in the binary tree and all node
values are unique.

Example 1:
Input:
        1
      /  \
     2    3
a = 2, b = 3
Output: 2
Explanation:
We need the distance between 2 and 3. Being at node 2, we need to take two steps ahead in order to reach
node 3. The path followed will be: 2 -> 1 -> 3. Hence, the result is 2.

Example 2:
Input:
        11
      /   \
     22  33
    /  \  /  \
  44 55 66 77
a = 77, b = 22
Output: 3
Explanation:
We need the distance between 77 and 22. Being at node 77, we need to take three steps ahead in order to
reach node 22. The path followed will be: 77 -> 33 -> 11 -> 22. Hence, the result is 3.


Your Task:
You don't need to read input or print anything. Your task is to complete the function findDist() which takes the root node of the tree and the two node values a and b as input parameters and returns the minimum distance between the nodes represented by the two given node values.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
2 <= n <= 105
0 <= Data of a node <= 109*/

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

Node *LCA(Node *root, int a, int b)
{
    if (root == NULL)
        return NULL;

    if (root->data == a || root->data == b)
        return root;

    Node *leftSubTree = LCA(root->left, a, b);
    Node *rightSubTree = LCA(root->right, a, b);

    if (leftSubTree && rightSubTree)
        return root;

    if (leftSubTree)
        return leftSubTree;
    else
        return rightSubTree;
}

int distanceFromAncestor(Node *ancestor, int num)
{
    if (ancestor == NULL)
        return -1;

    if (ancestor->data == num)
        return 0;

    int leftDist = distanceFromAncestor(ancestor->left, num);
    if (leftDist >= 0)
        return leftDist + 1;

    int rightDist = distanceFromAncestor(ancestor->right, num);
    if (rightDist >= 0)
        return rightDist + 1;

    return -1;
}

int findDist(Node *root, int a, int b)
{
    if (root == NULL)
        return -1;

    Node *lca = LCA(root, a, b);
    int firDist = distanceFromAncestor(lca, a);
    int secDist = distanceFromAncestor(lca, b);

    return firDist + secDist;
}

int main()
{
    int arr[] = {11, 22, 33, 44, 55, 66, 77};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = createTreeFromArray(arr, n);
    LevelOrder(root);
    int ans = findDist(root, 22, 77);
    cout << "Ans = " << ans << endl;
    return 0;
}