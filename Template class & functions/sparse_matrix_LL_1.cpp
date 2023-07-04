#include <iostream>
using namespace std;

class node
{
public:
    int row;
    int col;
    int data;
    node *next;

    node(int r, int c, int d)
    {
        this->row = r;
        this->col = c;
        this->data = d;
        this->next = NULL;
    }
};

void Insert(node *&head, node *&tail, int r, int c, int d)
{
    node *t = new node(r, c, d);

    if (head == NULL)
    {
        head = tail = t;
    }

    else
    {
        tail->next = t;
        tail = t;
    }
}

void display(node *head)
{
    node *p = head;
    while (p != nullptr)
    {
        cout << " Row No -- " << p->row << "  "
             << "Column No -- " << p->col << "  "
             << "Data -- " << p->data << endl;
        p = p->next;
    }
    cout << endl;
}

int main()
{
    int sparse_matrix[5][4] = {
        {0, 0, 3, 0},
        {0, 0, 5, 7},
        {0, 0, 0, 0},
        {0, 2, 6, 0},
        {4, 0, 0, 0}};

    node *head = NULL;
    node *tail = NULL;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (sparse_matrix[i][j] != 0)
                Insert(head, tail, i, j, sparse_matrix[i][j]);
        }
    }

    display(head);
    return 0;
}
