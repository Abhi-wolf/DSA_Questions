#include <iostream>
using namespace std;

class col_list;

class row_list
{
public:
    int row_no;
    col_list *link_right;
    row_list *link_down;

    row_list(int r)
    {
        this->row_no = r;
        this->link_down = NULL;
        this->link_right = NULL;
    }
};

class col_list
{
public:
    int col_no;
    int value;
    col_list *next;

    col_list(int v, int c)
    {
        this->col_no = c;
        this->value = v;
        this->next = NULL;
    }
};

void create_col_list(row_list **t, int val, int col)
{
    col_list *temp = new col_list(val, col);

    if ((*t)->link_right == NULL)
        (*t)->link_right = temp;

    else
    {
        col_list *d = (*t)->link_right;
        while (d->next != NULL)
            d = d->next;
        d->next = temp;
    }
}

void create_row_list(row_list *&head, row_list *&tail, int row, int c)
{
    row_list *t = new row_list(row);

    if (head == NULL)
    {
        head = tail = t;
    }

    else
    {
        tail->link_down = t;
        tail = t;
    }

    for (int i = 0; i < c; i++)
    {
        int num, col_no;
        cout << "Enter value and column no : ";
        cin >> num >> col_no;
        create_col_list(&tail, num, col_no);
    }
}

void print_LL(row_list *start)
{
    row_list *r = start;
    col_list *c;

    while (r != NULL)
    {
        if (r->link_right != NULL)
        {
            cout << "Row no -- " << r->row_no << endl;
            c = r->link_right;
            while (c != NULL)
            {
                cout << "column no -- " << c->col_no << "  value -- " << c->value << endl;
                c = c->next;
            }
        }
        r = r->link_down;
    }
}


//  ONLY THIS PART IS NOT WORKING
void print_matrix(row_list *start, int row, int col)
{
    row_list *r = start;
    col_list *c;
    int i = 0, j;
    while (r != NULL)
    {
        if (r->link_right != NULL)
        {
            c = r->link_right;
            j = 0;
            while (j < col)
            {
                if (c->col_no != j)
                {
                    cout<<"0 ";
                }
                else
                {
                    cout << c->value << " ";
                    c = c->next;
                }

                j++;
            }
        }
        else
        {
            for (int a = 0; a < col; a++)
                cout << "0 ";
        }
        cout << endl;
        r = r->link_down;
        i++;
    }
}

int main()
{
    int row, col;
    row_list *head, *tail;
    head = tail = NULL;
    cout << "Enter the total number of rows and columns in sparse matrix : ";
    cin >> row >> col;

    for (int i = 0; i < row; i++)
    {
        int c;
        cout << "Enter the no of non-zero columns in row " << i << " : ";
        cin >> c;
        create_row_list(head, tail, i, c);
    }

    cout << "\n\n";
     print_LL(head);
    print_matrix(head, row, col);
    return 0;
}