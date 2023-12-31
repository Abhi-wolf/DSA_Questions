//{ Driver Code Starts
#include <bits/stdc++.h>

/*
    Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order.
Note: The flattened list will be printed using the bottom pointer instead of next pointer. For more clearity have a look at the printList()
function in the driver code.

*/

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node *flatten(Node *root);

int main(void)
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, flag = 1, flag1 = 1;
        struct Node *temp = NULL;
        struct Node *head = NULL;
        struct Node *pre = NULL;
        struct Node *tempB = NULL;
        struct Node *preB = NULL;
        cin >> n;
        int work[n];
        for (int i = 0; i < n; i++)
            cin >> work[i];
        for (int i = 0; i < n; i++)
        {
            m = work[i];
            --m;
            int data;
            scanf("%d", &data);
            temp = new Node(data);
            temp->next = NULL;
            temp->bottom = NULL;

            if (flag)
            {
                head = temp;
                pre = temp;
                flag = 0;
                flag1 = 1;
            }
            else
            {
                pre->next = temp;
                pre = temp;
                flag1 = 1;
            }
            for (int j = 0; j < m; j++)
            {

                int temp_data;
                scanf("%d", &temp_data);
                tempB = new Node(temp_data);

                if (flag1)
                {
                    temp->bottom = tempB;
                    preB = tempB;
                    flag1 = 0;
                }
                else
                {
                    preB->bottom = tempB;
                    preB = tempB;
                }
            }
        }
        Node *fun = head;
        Node *fun2 = head;

        Node *root = flatten(head);
        printList(root);
        cout << endl;
    }
    return 0;
}

/*  Function which returns the  root of
    the flattened linked list. */
Node *flatten(Node *root)
{
    // Your code here
    vector<int> v;
    Node *t = root;
    while (t != NULL)
    {
        v.push_back(t->data);
        if (t->bottom != NULL)
        {
            Node *p = t->bottom;
            while (p != NULL)
            {
                v.push_back(p->data);
                p = p->bottom;
            }
        }
        t = t->next;
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << "  ";
    cout << endl;

    Node *ans = new Node(-1);
    Node *tail = ans;
    int a = v.size();
    for (int i = 0; i < a; i++)
    {
        Node *q = new Node(v[i]);
        tail->bottom = q;
        tail = q;
    }
    Node *head = ans->bottom;
    return head;
}
