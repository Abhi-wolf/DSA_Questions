// C++ program for Sparse Matrix Representation
// using List Of Lists
#include<bits/stdc++.h>
using namespace std;
#define R 4
#define C 5

// Node to represent row - list
struct row_list
{
	int row_number;
	struct row_list *link_down;
	struct value_list *link_right;
};

// Node to represent triples
struct value_list
{
	int column_index;
	int value;
	struct value_list *next;
};

// Function to create node for non - zero elements
void create_value_node(int data, int j, struct row_list **z)
{
	struct value_list *temp, *d;

	// Create new node dynamically
	temp = new value_list();
	temp->column_index = j+1;
	temp->value = data;
	temp->next = NULL;

	// Connect with row list
	if ((*z)->link_right==NULL)
		(*z)->link_right = temp;
	else
	{
		// d points to data list node
		d = (*z)->link_right;
		while(d->next != NULL)
			d = d->next;
		d->next = temp;
	}
}

// Function to create row list
void create_row_list(struct row_list **start, int row,
					int column, int Sparse_Matrix[R][C])
{
	// For every row, node is created
	for (int i = 0; i < row; i++)
	{
		struct row_list *z, *r;

		// Create new node dynamically
		z = new row_list();
		z->row_number = i+1;
		z->link_down = NULL;
		z->link_right = NULL;
		if (i==0)
			*start = z;
		else
		{
			r = *start;
			while (r->link_down != NULL)
				r = r->link_down;
			r->link_down = z;
		}

		// Firstiy node for row is created,
		// and then traversing is done in that row
		for (int j = 0; j < 5; j++)
		{
			if (Sparse_Matrix[i][j] != 0)
			{
				create_value_node(Sparse_Matrix[i][j], j, &z);
			}
		}
	}
}

//Function display data of LIL
void print_LIL(struct row_list *start)
{
	struct row_list *r;
	struct value_list *z;
	r = start;

	// Traversing row list
	while (r != NULL)
	{
		if (r->link_right != NULL)
		{
			cout<<"row="<<r->row_number<<endl;
			z = r->link_right;

			// Traversing data list
			while (z != NULL)
			{
				cout<<"column="<<z->column_index<<" value="<<z->value<<endl;
				z = z->next;
			}
		}
		r = r->link_down;
	}
}

//Driver of the program
int main()
{
	// Assume 4x5 sparse matrix
	int Sparse_Matrix[R][C] =
	{
		{0 , 0 , 3 , 0 , 4 },
		{0 , 0 , 5 , 7 , 0 },
		{0 , 0 , 0 , 0 , 0 },
		{0 , 2 , 6 , 0 , 0 }
	};

	// Start with the empty List of lists
	struct row_list* start = NULL;

	//Function creating List of Lists
	create_row_list(&start, R, C, Sparse_Matrix);

	// Display data of List of lists
	print_LIL(start);
	return 0;
}

// This code is contributed by rutvik_56.
