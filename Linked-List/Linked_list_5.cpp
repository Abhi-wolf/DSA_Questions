#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node *next;
}*first=NULL,*second=NULL,*third=NULL;


//      CREATING FIRST LINKED LIST
void Create1(int A[],int n)
{
    Node *last,*t;
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


//  CREATING SECOND LINKED LIST
void Create2(int A[],int n)
{
    Node *last,*t;
    second=new Node;
    second->data=A[0];
    second->next=NULL;
    last=second;

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
void Display(Node *p)
{
    if(p==NULL)
        cout<<"Empty\n";
    else
    {
        while(p!=NULL)
        {
            cout<<p->data<<"  ";
            p=p->next;
        }
        cout<<endl;
    }
}


//     CONCATENATE TWO LINKED LIST
//  (we will traverse through first linked list until there is a null and then 
//      we will fill the null with the address of second linked list)
void Concatenate(Node *p,Node *q)
{
    third=p;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=q;
}




//  MERGING TWO LINKED LIST IN SORTED ORDER
//   (both the linked list are sorted)
void Merge(Node *p,Node *q)
{
    Node *last;
    // ONLY FOR FIRST BOX OF LL
    // if data of first LL is smaller than that of second LL
    if(p->data < q->data)
    {
        third=last=p;
        p=p->next;
        last->next=NULL;
    }

    // data of second LL is smaller than that of first LL
    else
    {
        third=last=q;
        q=q->next;
        last->next=NULL;
    }

    //  loop after first box
    while(p!=NULL && q!=NULL)
    {
        if(p->data < q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p!=NULL)
        last->next=p;
    else
        last->next=q;
}



//  TO CHECK IF THE LINKED LIST IS LOOPED (THERE IS NO NULL POINTERS)
//      (In circular track if one cars is slow and the other is fast then they will surely meet at a point)
//  (here we are moving pointer p by 1 box and pointer q by 2 box)
int IsLoop(struct Node *f)
{
    struct Node *p,*q;
    p=q=f;
    do
    {
        p=p->next;
        q=q->next;
        if(q!=NULL)
            q=q->next;
    }while(p!=NULL && q!=NULL && p!=q);

    if(p==q)
        return 1;
    else
        return 0;
}




//      MAIN FUNCTION
int main()
{
    int A[]={1,2,4,6,8};
    int B[]={2,5,7,9,10};
    Create1(A,5);
    Create2(B,5);
    Display(first);
    Display(second);

    // Concatenate(first,second);
    // Display(third);

    Merge(first,second);
    Display(third);

    // struct Node *t1,*t2;

    // t1=first->next->next;           // t1 points on 4 (index 2) of A[]
    // t2=first->next->next->next->next;   // t2 points on 8 (index 4) of A[]
    // t2->next=t1;                        // t2 points on 4 (index 2) of A[] 
    
    //  to check if the LL is not looped comment upper three lines
    // cout<<"Is linked list Looped  "<<IsLoop(first)<<endl;       

    return 0;
}