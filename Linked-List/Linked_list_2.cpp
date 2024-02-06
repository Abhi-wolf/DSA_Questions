#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

//  CREATE FUNCTION
void Create(int A[], int n)
{
    struct Node *p;
    struct Node *last;

    //  FOR C LANGUAGE first=(struct Node *)malloc(sizeof(struct Node));
    //  HEADER FILE FOR MALLOC FUN IS stdlib.h
    first = new Node;

    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        p = new Node;
        p->data = A[i];
        p->next = NULL;
        last->next = p;
        last = p;
    }
}

//     DISPLAY FUNCTION USING LOOP
void Display(struct Node *q)
{
    if (q == NULL)
        cout << "Empty\n";
    else
    {
        while (q != NULL)
        {
            cout << q->data << "  ";
            q = q->next;
        }
    }
}

// RECURSIVE DISPLAY FUNCTION
//  IF RDISPLAY IS WRITTEN BEFORE COUT OUTPUT WILL BE REVERSED
void RDisplay(struct Node *q)
{
    if (q != NULL)
    {
        cout << q->data << "  ";
        RDisplay(q->next);
    }
}

//  COUNT FUNCTION USING LOOP
int Count(struct Node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

//  RECURSIVE COUNT FUNCTION
int RCount(struct Node *p)
{
    if (p == NULL)
        return 0;
    else
        return RCount(p->next) + 1;
}

//  SUM FUNCTION USING LOOP
int Sum(struct Node *p)
{
    int sum = 0;
    while (p != 0)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

//  RECURSIVE SUM  FUNCTION
int RSum(struct Node *p)
{
    if (p == NULL)
        return 0;
    else
        return RSum(p->next) + (p->data);
}

//  ITERATIVE MAX FUNCTION
int Max(struct Node *a)
{
    int max = INT32_MIN;

    while (a)
    {
        if (a->data > max)
            max = a->data;
        a = a->next;
    }
    return max;
}

//  RECURSIVE MAX FUNCTION
int RMax(struct Node *a)
{
    int max = 0;
    if (a == 0)
        return INT32_MIN;

    max = RMax(a->next);
    if (a->data < max)
        return max;
    else
        return a->data;
}

//  BINARY SEARCH IS NOT SUITABLE BECAUSE WE CANNOT MOVE TO THE MIDDLE IN CONSTANT TIME
//  TO IMPROVE LINEAR SEARCH WE CAN BRING THE SEARCH NODE TO FRONT SO THAT NEXT TIME
//   IF ITIS BEING SEARCHED IT BECOMES EASY
//    ITERATIVE  LINEAR SEARCH
Node *LSearch(struct Node *a, int num)
{
    /* while(a!=NULL) {
         if(a->data == num)
             return (a);
         a=a->next;
     }
     return NULL;  */
    Node *b;
    while (a != NULL)
    {
        if (a->data == num)
        {
            b->next = a->next;
            a->next = first;
            first = a;
            return a;
        }
        b = a;
        a = a->next;
    }
    return NULL;
}

//  RECURSIVE LINEAR SEARCH
Node *RSearch(struct Node *a, int num)
{
    if (a == NULL)
        return NULL;
    if (a->data == num)
        return a;
    return RSearch(a->next, num);
}

int main()
{
    struct Node *temp;
    int A[] = {3, 900, 100, 5, 8, 4, 10};
    Create(A, 7);
    // Display(first);
    // RDisplay(first);
    // cout<<"\nNo of elements = "<<RCount(first)<<endl;
    // cout<<"Sum of elements = "<<RSum(first)<<endl;

    // cout<<"Maximum element of the Linked list is "<<RMax(first)<<endl;
    temp = LSearch(first, 10);
    LSearch(first, 5);
    if (temp)
        cout << "Element found " << temp->data << endl;
    else
        cout << "Element not found\n";
    Display(first);

    return 0;
}