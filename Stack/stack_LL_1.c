#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*top=NULL; 


void Push(int x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    if(t==NULL)
        printf("Stack Overflow\n");
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}


int Pop()
{
    struct Node *t;
    int x=-1;
    //t=(struct Node *)malloc(sizeof(struct Node));
    if(top==NULL)
        printf("Stack Empty\n");
    else
    {
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}



void Display()
{
    struct Node *p=top;
    while(p!=NULL)
    {
        printf("%d  ",p->data);
        p=p->next;
    }
    printf("\n");
}



int isEmpty()
{
    if(top==NULL)
        return 1;
    else
        return 0;
}
 



int Stacktop()
{
    int x=-1;
    if(top)
        x=top->data;
    return x;
}


void Delete(struct Node **top)
{
    struct Node *t,*p;
    p=*top;
    while(p->next)
    {
        t=p;
        p=p->next;
        free(t);
    }
    free(p);
}

int main()
{
    Push(10);
    Push(20);
    Push(30);
    Push(40);
    Push(50);
    Push(60);
    Push(70);

    Display(top);

    printf("Deleted element is %d \n",Pop());
    Display();

    printf("isEmpty = %d \n",isEmpty());
    printf("stacktop = %d \n",Stacktop());

    Delete(&top);
    top=NULL;
    printf("isEmpty = %d \n",isEmpty());
    printf("stacktop = %d \n",Stacktop());
    return 0;
}