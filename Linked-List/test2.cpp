#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    Node *next;
};


void Insert(Node **p,int index,int x)
{
    Node *t,*q;
    q=*p;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;

    if(index==0)
    {
        *p=t;
    }

    else
    {
        for(int i=0;i<index-1;i++)
            q=q->next ;
        t->next=q->next;
        q->next=t;
    }
}


void Display(struct Node *p)
{
    if(p==NULL)
        printf("Empty\n");
    else
    {
        while(p!=NULL)
        {
            printf("%d  \n",p->data);
            p=p->next;
        }
        printf("\n");
    }
}

int main()
{
    Node *head=NULL;

    Insert(&head,0,10);
    Insert(&head,1,20);
    Insert(&head,2,30000);
    Insert(&head,3,40);

    Display(head);
    return 0;
} 