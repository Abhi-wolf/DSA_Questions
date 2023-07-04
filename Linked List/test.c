#include <stdio.h>
#include <stdlib.h>
//      29 AUGUST 

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;


void Create(int A[],int n)
{
    struct Node *last,*temp;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        temp=(struct Node *)malloc(sizeof(struct Node));
        temp->data=A[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }
}


void Display(struct Node *p)
{
    if(p==NULL)
        printf("\nStack Empty\n");
    else
    {
        printf("Displaying : ");
        while(p!=NULL)
        {
            printf("%d , ",p->data);
            p=p->next;
        }
        printf("\n");
    }
}


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


void Insert(struct Node *p,int index,int x)
{
    struct Node *t;
    if(index<0 || index>Count(p))
        return;

    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    if(index==0)
    {
        t->next=first;
        first=t;
    }

    else
    {
        for(int i=0;i<index-1;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
    }
}


int main()
{
    int A[]={1,2,3,4,5};
    Create(A,5);
    Display(first);
    printf("Size = %d\n",Count(first));
    Insert(first,3,10);
    Display(first);
    printf("Size = %d\n",Count(first));
    return 0;
}