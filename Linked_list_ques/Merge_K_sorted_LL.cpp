#include <iostream>
using namespace std;


// given k sorted linked lists merge the linked lists and return the head of the new list
class Node
{
public:
    int val;
    Node *next;
    Node(int x)
    {
        this->val = x;
        this->next = NULL;
    }
};

void Insert(Node **root, int num)
{
    Node *temp = new Node(num);
    if (*root == NULL)
    {
        *root = temp;
        return;
    }

    Node *p = *root;
    while (p->next != NULL)
        p = p->next;

    p->next = temp;
}

void print(Node *root)
{
    Node *p = root;
    while (p)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

Node *merge(Node *fir, Node *sec)
{
    Node *third = NULL;
    Node *p = NULL;
    if (fir->val < sec->val)
    {
        third = p = fir;
        fir = fir->next;
    }

    else
    {
        third = p = sec;
        sec = sec->next;
    }

    while (fir && sec)
    {
        if (fir->val < sec->val)
        {
            p->next = fir;
            fir = fir->next;
            p = p->next;
        }

        else
        {
            p->next = sec;
            sec = sec->next;
            p = p->next;
        }
    }

    if (fir)
        p->next = fir;
    if (sec)
        p->next = sec;

    return third;
}

Node *mergeKLists(Node *arr[], int k)
{
    if (k < 2)
        return arr[0];

    Node *ans = merge(arr[0], arr[1]);

    for (int i = 2; i < k; i++)
    {
        ans = merge(ans, arr[i]);
    }
    return ans;
}

int main()
{
    Node *arr[4];

    for (int i = 0; i < 4; i++)
    {
        cout << i << "th array \n";
        arr[i] = NULL;
        for (int j = 0; j < 3; j++)
        {
            int x;
            cout << "enter x: ";
            cin >> x;
            Insert(&arr[i], x);
        }
    }
    for (int i = 0; i < 4; i++)
    {
        cout << i << "th array = ";
        print(arr[i]);
    }

    Node *hell = mergeKLists(arr, 4);
    print(hell);
    return 0;
}