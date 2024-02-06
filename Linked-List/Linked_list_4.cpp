#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;



//  CREATED LINKED LIST 
void Create(int A[],int n)
{
    struct Node *last ,*t;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}


//  DISPLAYING LINKED LIST
void Display(struct Node *q)
{
    if(q==NULL)
        cout<<"\nEmpty\n";
    else
    {
        while(q!=NULL)
        {
            cout<<q->data<<"  ";
            q=q->next;
        }
    }
    cout<<"\n";
}




//      COUNTING NUMBER OF NODES IN THE LINKED LIST
int Count(struct Node *p)
{
    int count=0;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}



//      DELETING NODES IN LINKED LIST 
void Delete_node(struct Node *p,int index)
{
    struct Node *q;
    if(index<0 || index>Count(p))
        return ;
    
    if(index==1)
    {
        q=first;
        first=first->next;
        delete q;
    }
    else
    {
        for(int i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        delete p;
    }

}




//      FUNCTION TO CHECK IF THE LINKED LIST IS SORTED
bool IsSorted(struct Node *q)
{
    int x=-65536;   //(smallest possible value)
    while(q!=NULL)
    {
        if(q->data < x)
            return false;
        x=q->data;
        q=q->next;
    }
    return true;
}


//      FUNCTION TO REMOVE ALL DUPLICATES 
//  (IT IS CONSIDERED THAT LINKED LIST IS SORTED)
void Duplicates(struct Node *p)
{
    struct Node *q;
    q=p->next;
        while(q!=NULL)
        {
            if(p->data!=q->data)
            {
                p=q;
                q=q->next;
            }

            else
            {
                p->next=q->next;
                delete q;
                q=p->next;
            }
        }
    
}

//      REVERSE USING ARRAY
//  (first all elements are copied to the array and then elements are modified in the linked list)
void Reverse_Array(struct Node *p)
{
    int size=Count(p);
    int arr[size],x=0;
    while(p!=NULL)
    {
        arr[x]=p->data;
        p=p->next;
        x++;
    }
    p=first;
    x--;
    while(p!=NULL)
    {
        p->data=arr[x--];
        p=p->next;
    }
}


//  REVERSING BY CHANGING LINKS OF THE LINKED LISTS
//    (links to the nodes are changed while calling,sliding pointers)
void Reverse_Links(struct Node *p)
{
    struct Node *q,*r;
    q=NULL;
    r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}




//  REVERSING LINKED LIST USING RECURSION
//  (links of the nodes are reversed while returning)
void Reverse_recur(struct Node *q,struct Node *p)
{
    if(p!=NULL)
    {
        Reverse_recur(p,p->next);
        p->next=q;
    }
    else
        first=q;
}


//      MAIN FUNCTION
int main()
{
    int A[]={1,2,3,4,5,6,7,8,9,10};
    Create(A,10);
    Display(first);
    // Delete_node(first,5);
    // Display(first);
    // cout<<IsSorted(first)<<endl;
    // Duplicates(first);
    Reverse_Links(first);
    // Reverse_recur(NULL,first);
    Display(first);
    return 0;
}


