#include <iostream>
using namespace std;

class node
{
public:
    int data;
    int column_no;
    node *next;

    node(int x, int y)
    {
        this->data = y;
        this->column_no = x;
        this->next = NULL;
    }
};

void display(node *p, int m, int n);

void create()
{
    int rows = 0, column = 0;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> column;

    node **root;
    root = new node *[rows];
    for (int i = 0; i < rows; i++)
    {
        int col = 0;
        cout << "Enter the number of non-zero elements in row " << i << " : ";
        cin >> col;
        node *first = NULL;
        node *p = NULL, *last = NULL;
        for (int j = 0; j < col; j++)
        {
            int num = 0, num2 = -1;
            cout << "Enter column number and element : ";
            cin >> num2 >> num;

            if (first == NULL)
            {
                first = new node(num2, num);
                last = first;
            }
            else
            {
                p = new node(num2, num);
                last->next = p;
            }
        }
        root[i] = first;
    }

    // node **p=root;
    int m = rows;
    int n = column;
    for (int i = 0; i < m; i++)
    {
        node *t = root[i];
        for (int j = 0; j < n; j++)
        {
            if (j == t->column_no)
            {
                cout << t->data << "  ";
                t = t->next;
            }
            else
            {
                cout << "0  ";
            }
        }
        cout << endl;
    }
}

int main()
{
    create();
    return 0;
}
