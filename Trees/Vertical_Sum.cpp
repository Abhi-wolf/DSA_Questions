#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

/* Given a binary tree having n nodes, find the vertical sum of the nodes that are in the same vertical line.
Return all sums through different vertical lines starting from the left-most vertical line to the right-most
vertical line.

Example 1:
Input:
       1
    /    \
  2      3
 /  \    /  \
4   5  6   7
Output:
4 2 12 3 7
Explanation:
The tree has 5 vertical lines
Line 1 has only one node 4 => vertical sum is 4.
Line 2 has only one node 2 => vertical sum is 2.
Line-3 has three nodes: 1,5,6 => vertical sum is 1+5+6 = 12.
Line-4 has only one node 3 => vertical sum is 3.
Line-5 has only one node 7 => vertical sum is 7.

Example 2:
Input:
          1
         /
        2
       /
      3
     /
    4
   /
  6
 /
7
Output:
7 6 5 4 3 2 1

Explanation:
There are seven vertical lines each having one node.
Your Task:
You don't need to take input. Just complete the function verticalSum() that takes root node of the tree as parameter and returns an array containing the vertical sum of tree from left to right.

Expected Time Complexity: O(nlogn).
Expected Auxiliary Space: O(n).

Constraints:
1<=n<=104
1<= Node value <= 105


*/

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

    Node *root = new Node(arr[0]);
    queue<Node *> que;
    int i = 1;
    que.push(root);
    while (i < n)
    {

        Node *p = que.front();
        que.pop();
        if (arr[i] != -1)
        {
            p->left = new Node(arr[i]);
            que.push(p->left);
        }
        else
        {
            p->left = NULL;
        }

        i++;

        if (i < n)
        {
            if (arr[i] != -1)
            {
                p->right = new Node(arr[i]);
                que.push(p->right);
            }
            else
            {
                p->right = NULL;
            }
            i++;
        }
    }
    return root;
}

// add level to each node decrease the level on moving left and increase the level on moving right (for getting left to right values)
void solve(Node *p, int ind, map<int, int> &mp)
{
    if (!p)
        return;
    mp[ind] += p->data;
    solve(p->left, ind - 1, mp);
    solve(p->right, ind + 1, mp);
}

// levelorder
void levelOrder(Node *root)
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
            cout << "\n";
            if (!que.empty())
                que.push(NULL);
        }
        else
        {
            cout << p->data << " , ";
            if (p->left)
                que.push(p->left);
            if (p->right)
                que.push(p->right);
        }
    }
}

vector<int> verticalSum(Node *root)
{
    // levelOrder(root);
    vector<int> res;

    map<int, int> mp;
    solve(root, 0, mp);
    for (auto x : mp)
    {
        res.push_back(x.second);
    }

    return res;
}

void Display(vector<int> vec)
{
    if (vec.size() == 0)
    {
        cout << "Empty \n";
        return;
    }

    cout << "\n\n";
    for (int num : vec)
        cout << num << " , ";
    cout << "\n\n";
}


int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = createTreeFromArray(arr, n);
    levelOrder(root);
    vector<int> res = verticalSum(root);
    Display(res);
    return 0;
}
